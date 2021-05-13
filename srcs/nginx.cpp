/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nginx.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:26:40 by honlee            #+#    #+#             */
/*   Updated: 2021/05/13 09:18:43 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nginx.hpp"
#include <errno.h>
#include <string>

Nginx::Nginx() : fd_max(-1)
{
	FT_FD_ZERO(&(this->reads));
	FT_FD_ZERO(&(this->writes));
	FT_FD_ZERO(&(this->errors));
}

Nginx::~Nginx()
{
	
}

bool	Nginx::initServers(int queue_size)
{
	std::map<std::string, int> temp_map;

	for (std::map<std::string, Server>::iterator iter = Config::getInstance()->getServers().begin(); iter != Config::getInstance()->getServers().end(); iter++)
	{
		std::string key = iter->second.getIP() + ":" + ft_itoa(iter->second.getPort());
		if (temp_map.find(key) != temp_map.end()) // 이미 존재한다.
		{
			this->servers[temp_map[key]][iter->second.getServerName()] = iter->second;
			std::cout << "Server " << iter->second.getServerName() << "(" << iter->second.getIP() << ":" << iter->second.getPort() << ") launched" << std::endl;	
			continue ;
		}

		struct sockaddr_in  server_addr;
		
		iter->second.setSocketFd(socket(PF_INET, SOCK_STREAM, 0));

		ft_memset(&server_addr, 0, sizeof(server_addr));
		server_addr.sin_family = AF_INET;
		server_addr.sin_addr.s_addr = inet_addr(iter->second.getIP().c_str());
		server_addr.sin_port = ft_htons(iter->second.getPort());

		if (bind(iter->second.getSocketFd(), (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
		{
			std::cerr << "bind() error" << std::endl;
			throw strerror(errno);
		}
		if (listen(iter->second.getSocketFd(), queue_size) == -1)
			throw strerror(errno);

		std::cout << "Server " << iter->second.getServerName() << "(" << iter->second.getIP() << ":" << iter->second.getPort() << ") started" << std::endl;

		// 서버소켓은 read 와 error 만 검사.
		FT_FD_SET(iter->second.getSocketFd(), &(this->reads));
		FT_FD_SET(iter->second.getSocketFd(), &(this->errors));

		this->servers[iter->second.getSocketFd()][iter->second.getServerName()] = iter->second;
		temp_map[key] = iter->second.getSocketFd();

		if (this->fd_max < iter->second.getSocketFd())
			this->fd_max = iter->second.getSocketFd();
	}
	return (true);
}

bool	Nginx::run(struct timeval	timeout, unsigned int buffer_size)
{
	fd_set	cpy_reads;
	fd_set	cpy_writes;
	fd_set	cpy_errors;

	struct sockaddr_in  client_addr;
	socklen_t			addr_size = sizeof(client_addr);
	int		fd_num;
	
	char	buf[buffer_size + 1];

	while (1)
	{
		cpy_reads = this->reads;
		cpy_writes = this->writes;
		cpy_errors = this->errors;

		if ( (fd_num = select(this->fd_max + 1, &cpy_reads, &cpy_writes, &cpy_errors, &timeout)) == -1)
			throw strerror(errno);

		if (fd_num == 0)
			continue ;
		
		for (int i = 0; i <= this->fd_max; i++)
		{
			if (FT_FD_ISSET(i, &cpy_reads))
			{
				if (this->servers.count(i) == 1) // server socket event
				{
					int client_socket = accept(i, (struct sockaddr*)&client_addr, &addr_size);
				
					FT_FD_SET(client_socket, &(this->reads));
					FT_FD_SET(client_socket, &(this->writes));
					FT_FD_SET(client_socket, &(this->errors));
					if (this->fd_max < client_socket)
						this->fd_max = client_socket;

					this->clients[client_socket].setServerSocket(i);
					this->clients[client_socket].setSocketFd(client_socket);
					
					std::cout << "connected client : " << client_socket << std::endl;
				}
				else	// client socket event
				{
					int len = read(i, buf, buffer_size);
					buf[len] = 0;
					if (len == 0) // close request
					{
						FT_FD_CLR(i, &reads);
						FT_FD_CLR(i, &writes);
						FT_FD_CLR(i, &errors);
						close(i);
						std::cout << "disconnected : " << i << " in Server ";
						this->clients.erase(this->clients.find(i));
					}
					else // receive request raw data
					{
						this->clients[i].getRawRequest() += buf;
						this->clients[i].setStatus(REPSONE_READY);
					}
				}
			}
			else if (FT_FD_ISSET(i, &cpy_writes))
			{
				// always client socket event
				if (!this->clients[i].getRawRequest().empty() && this->clients[i].getStatus() == REPSONE_READY)
				{
					write(i, this->clients[i].getRawRequest().c_str(), this->clients[i].getRawRequest().size());
					this->clients[i].getRawRequest().clear();
					clients[i].setStatus(HEADER_RECEVING);
				}
			}
			else if (FT_FD_ISSET(i, &cpy_errors))
			{
				if (this->servers.count(i) == 1) // server socket error
				{
					FT_FD_CLR(i, &reads);
					FT_FD_CLR(i, &errors);
					close(i);
					std::cout << "server " << i << " error!!" << std::endl;
					this->servers.erase(this->servers.find(i));
				}
				else // client socket error
				{
					FT_FD_CLR(i, &reads);
					FT_FD_CLR(i, &writes);
					FT_FD_CLR(i, &errors);
					close(i);
					this->clients.erase(this->clients.find(i));
					std::cout << "error client disconnected : " << i << std::endl;
				}
			}
		}
	}
	return (true);
}