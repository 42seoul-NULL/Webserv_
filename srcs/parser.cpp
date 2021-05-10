/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:52:22 by honlee            #+#    #+#             */
/*   Updated: 2021/05/10 14:15:37 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.hpp"

/////////////////////////////////////////////////////////
/////////////////// class Config start //////////////////
Config &Config::operator=(const Config &src)
{
	return (*this);
}

Config::~Config()
{
	delete (this->instance);
	return ;
}

std::map<std::string, Server> &Config::getServers()
{
	return (this->servers);
}
/////////////////// class Config end ////////////////////
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
////////////////// class Server start ///////////////////
Server &Server::operator=(const Server &src)
{
	return (*this);
}

Server::~Server()
{
	return ;
}

void	Server::setPort(int port)
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

int		Server::getPort()
{
	return (this->port);
}

std::map<std::string, Location> &Server::getLocations()
{
	return (this->locations);
}
////////////////// class Server end /////////////////////
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
///////////////// class Location start //////////////////
Location &Location::operator=(const Location &src)
{
	return (*this);
}

void		Location::setRoot(const std::string& root)
{
	this->root = root;
	return ;
}

void		Location::setClientBodyBufferSize(unsigned int client_body_buffer_size)
{
	this->client_body_buffer_size = client_body_buffer_size;
	return ;
}

void		Location::setErrorPage(const std::string& error_page)
{
	this->error_page = error_page;
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

unsigned int Location::getClientBodyBufferSize()
{
	return (this->client_body_buffer_size);
}

const std::string &Location::getErrorPage()
{
	return (this->error_page);
}
///////////////// class Location end ////////////////////
/////////////////////////////////////////////////////////
