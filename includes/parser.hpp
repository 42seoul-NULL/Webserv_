/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:58:37 by honlee            #+#    #+#             */
/*   Updated: 2021/05/06 15:59:24 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_HPP
# define CONFIG_HPP

# include <stdlib.h>
# include <string>
# include <map>
# include <list>
# include <unistd.h>
# include <fcntl.h>
# include <iostream>
# include <vector>
# include "../libft_cpp/libft.hpp"
# include <queue>

class Location;
class Server;

class Config
{
	private :
		Config(){};
		Config(const Config &src);
		Config& operator=(const Config& src);
		bool	returnFalseWithMsg(const char *str);
		bool	isReserved(const std::string &src);

		std::map<std::string, Server> servers;
		static Config*	instance;

	public	:
		virtual ~Config();
		static Config* getInstance();
		std::map<std::string, Server>& getServers();
		bool	makeConfig(const char *path);
		
		//for test
		void	show();
};

class Server
{
	private	:
		std::string		ip;
		unsigned short	port;
		std::string		server_name;
		std::string		error_page;
		std::map<std::string, Location> locations;

	public	:
		Server();
		Server(const Server &src);
		Server& operator=(const Server &src);
		virtual	~Server();

		void	setPort(unsigned short port);
		void	setIP(const std::string &ip);
		void	setServerName(const std::string &server_name);

		const std::string &getIP();
		const std::string &getServerName();
		unsigned short	   getPort();

		std::map<std::string, Location> &getLocations();
		//for test//
		void	show();
};

class Location
{
	private	:
		std::string		root;
		std::list<std::string> index;
		std::list<std::string> allow_methods;
		int	client_body_buffer_size;
		std::string		error_page;
		std::string		error_number;
		std::string		upload_path;
		bool			auto_index;

	public	:
		Location();
		virtual ~Location(){};
		Location(const Location &src);
		Location& operator=(const Location &src);

		void			setRoot(const std::string &root);
		void			setClientBodyBufferSize(int client_body_buffer_size);
		void			setErrorPage(const std::string &error_page);
		void			setErrorNumber(const std::string &error_number);
		void			setUploadPath(const std::string &upload_path);
		void			setAutoIndex(bool auto_index);

		const std::string &getRoot();
		std::list<std::string> &getIndex();
		std::list<std::string> &getAllowMethods();
		int getClientBodyBufferSize();
		const std::string &getErrorPage();
		const std::string &getErorrNumber();
		const std::string &getUploadPath();
		bool	getAutoIndex();

		//for test//
		void	show();
};
#endif