/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:52:22 by honlee            #+#    #+#             */
/*   Updated: 2021/05/11 12:51:38 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.hpp"

/////////////////////////////////////////////////////////
/////////////////// class Config start //////////////////

Config* Config::instance;

Config::Config(const Config &src)
{
	(void)src;
}

Config &Config::operator=(const Config &src)
{
	(void)src;
	return (*this);
}

Config::~Config()
{
	delete (this->instance);
	return ;
}

Config *Config::getInstance()
{
	if (instance == NULL)
		instance = new Config();
	return (instance);
}

bool	Config::returnFalseWithMsg(const char *str)
{
	std::cerr << str << std::endl;
	return (false);
}

std::map<std::string, Server> &Config::getServers()
{
	return (this->servers);
}

bool	Config::isReserved(const std::string &src)
{
	if (src == "server" || 
		src == "listen" || 
		src == "server_name" || 
		src == "location" || 
		src == "error_page" || 
		src == "error_number" || 
		src == "allow_methods" || 
		src == "root" ||
		src == "index" ||
		src == "upload_path" ||
		src == "auto_index" ||
		src == "client_body_buffer_size" ||
		src == "}" ||
		src == "{" )
		return (true);
	return (false);
}

bool	Config::makeConfig(const char *path)
{
	int				fd;
	std::string		line;
	int				ret;
	std::string		splited;
	std::vector<std::string> vec;
	std::string		key;
	std::string		location_name;

	fd = open(path, O_RDONLY);
	if (fd < 3)
		return (returnFalseWithMsg("Can't open config"));

	try
	{
		while ( (ret = get_next_line(fd, line)) > 0)
		{
			if (line == "")
				continue ;
			splited = ft_split(line, " \t", vec);
			line.clear();
		}

		for (std::vector<std::string>::iterator iter = vec.begin(); iter != vec.end(); iter++)
		{
			if (*iter == "server_name")
			{
				iter++;
				std::string server_name = *iter;
				iter++; // listen
				iter++; // 8080
				std::string port = *iter;
				iter++; // 127.0.0.1
				key = server_name + ":" + port;
				if (instance->servers.find(key) != instance->servers.end()) // 이미 존재
					throw "server_name and port already exists";
				instance->servers[key].setServerName(server_name);
				instance->servers[key].setPort(ft_atoi(port));
				instance->servers[key].setIP(*iter);
			}
			else if (*iter == "location")
			{
				iter++;
				location_name = *iter;
			}
			else if (*iter == "error_page")
			{
				iter++;
				instance->servers[key].getLocations()[location_name].setErrorPage(*iter);
			}
			else if (*iter == "error_number")
			{
				iter++;
				instance->servers[key].getLocations()[location_name].setErrorNumber(*iter);
			}
			else if (*iter == "allow_methods")
			{
				iter++;
				while (!isReserved(*iter) && iter != vec.end())
				{
					instance->servers[key].getLocations()[location_name].getAllowMethods().push_back(*iter);
					iter++;
				}
				if (iter == vec.end())
					break ;
			}
			else if (*iter == "root")
			{
				iter++;
				instance->servers[key].getLocations()[location_name].setRoot(*iter);
			}
			else if (*iter == "index")
			{
				iter++;
				while (!isReserved(*iter) && iter != vec.end())
				{
					instance->servers[key].getLocations()[location_name].getIndex().push_back(*iter);
					iter++;
				}
				if (iter == vec.end())
					break ;
			}
			else if (*iter == "upload_path")
			{
				iter++;
				instance->servers[key].getLocations()[location_name].setUploadPath(*iter);
			}
			else if (*iter == "auto_index")
			{
				iter++;
				if (*iter == "on")
					instance->servers[key].getLocations()[location_name].setAutoIndex(true);
				else
					instance->servers[key].getLocations()[location_name].setAutoIndex(false);
			}
			else if (*iter == "client_body_buffer_size")
			{
				iter++;
				instance->servers[key].getLocations()[location_name].setClientBodyBufferSize(ft_atoi(*iter));
			}
		}
	}
	catch(const char *e)
	{
		std::cout << e << std::endl;
		return (false);
	}
	return (true);	
}

//for test
void		Config::show()
{
	for (std::map<std::string, Server>::iterator iter = this->servers.begin(); iter != this->servers.end(); iter++)
	{
		std::cout << "server key : " << iter->first << std::endl;
		iter->second.show();
	}
}

/////////////////// class Config end ////////////////////
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
////////////////// class Server start ///////////////////
Server::Server() : port(-1)
{
	
}

Server::Server(const Server& src)
{
	(void)src;
}

Server &Server::operator=(const Server &src)
{
	(void)src;
	return (*this);
}

Server::~Server()
{
	return ;
}

void	Server::setPort(unsigned short port)
{
	this->port = port;
	return ;
}

void	Server::setIP(const std::string &ip)
{
	this->ip = ip;
	return ;
}

void	Server::setServerName(const std::string &server_name)
{
	this->server_name = server_name;
	return ;
}

const std::string &Server::getIP()
{
	return (this->ip);
}

const std::string &Server::getServerName()
{
	return (this->server_name);
}

unsigned short		Server::getPort()
{
	return (this->port);
}

std::map<std::string, Location> &Server::getLocations()
{
	return (this->locations);
}
//for test
void		Server::show()
{
	std::cout << "ip	:	" << this->ip << std::endl;
	std::cout << "port	:	" << this->port << std::endl;
	std::cout << "server_name	:	" << this->server_name << std::endl;
	std::cout << "error_page	:	" << this->error_page << std::endl;
	std::cout << "============= location start =============" << std::endl;
	for (std::map<std::string, Location>::iterator iter = locations.begin(); iter != locations.end(); iter++)
	{
		std::cout << "=== Location Key : " << iter->first << " ===" << std::endl;
		iter->second.show();
	}
	std::cout << "============= location end ===============" << std::endl;
}

////////////////// class Server end /////////////////////
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
///////////////// class Location start //////////////////
Location::Location() : client_body_buffer_size(-1)
{
	
}

Location::Location(const Location &src)
{
	(void)src;
}

Location &Location::operator=(const Location &src)
{
	(void)src;
	return (*this);
}

void		Location::setRoot(const std::string& root)
{
	this->root = root;
	return ;
}

void		Location::setClientBodyBufferSize(int client_body_buffer_size)
{
	this->client_body_buffer_size = client_body_buffer_size;
	return ;
}

void		Location::setErrorPage(const std::string &error_page)
{
	this->error_page = error_page;
	return ;
}

void		Location::setErrorNumber(const std::string &error_number)
{
	this->error_number = error_number;
	return ;
}

void		Location::setUploadPath(const std::string &upload_path)
{
	this->upload_path = upload_path;
	return ;
}

void		Location::setAutoIndex(bool auto_index)
{
	this->auto_index = auto_index;
	return ;
}

const std::string &Location::getRoot()
{
	return (this->root);
}

std::list<std::string> &Location::getIndex()
{
	return (this->index);
}

std::list<std::string> &Location::getAllowMethods()
{
	return (this->allow_methods);
}

int Location::getClientBodyBufferSize()
{
	return (this->client_body_buffer_size);
}

const std::string &Location::getErrorPage()
{
	return (this->error_page);
}

const std::string &Location::getErorrNumber()
{
	return (this->error_number);
}

const std::string &Location::getUploadPath()
{
	return (this->upload_path);
}

bool	Location::getAutoIndex()
{
	return (this->auto_index);
}
//for test
void	Location::show()
{
	std::cout << "root	:	" << this->root << std::endl;
	std::cout << "cbbs	:	" << this->client_body_buffer_size << std::endl;
	std::cout << "error_page	:	" << this->error_page << std::endl;
	std::cout << "error_number	:	" << this->error_number << std::endl;
	std::cout << "upload_path	:	" << this->upload_path << std::endl;
	std::cout << "auto_index	:	" << this->auto_index << std::endl;
	std::cout << "index	: ";
	for (std::list<std::string>::iterator iter = this->index.begin(); iter != this->index.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
	std::cout << "allow_methods	: ";
	for (std::list<std::string>::iterator iter = this->allow_methods.begin(); iter != this->allow_methods.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

///////////////// class Location end ////////////////////
/////////////////////////////////////////////////////////
