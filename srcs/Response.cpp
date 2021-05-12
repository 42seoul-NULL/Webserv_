/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@42student.co.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:40:53 by juyang            #+#    #+#             */
/*   Updated: 2021/05/12 16:40:54 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Response.hpp"

Response::Response(void) : allow(""), content_language(""), content_length(""), content_location(""), content_type(""), date(""), last_modified(""), location(""), retry_after(""), server(""), transfer_encoding(""), www_authenticate("");
{

}

Response::Response(const Response& src) : allow(src.allow), content_language(src.content_language), content_length(src.content_length), content_location(src.content_location), content_type(src.content_type), date(src.date), last_modified(src.last_modified), location(src.location), retry_after(src.retry_after), server(src.server), transfer_encoding(src.transfer_encoding), www_authenticate(src.www_authenticate)
{

}

Response::~Response(void)
{

}

Response&	Response::operator=(const Response& src)
{
	this->allow = src.allow;
	this->content_language = src.content_language;
	this->content_length = src.content_length;
	this->content_location = src.content_location;
	this->content_type = src.content_type;
	this->date = src.date;
	this->last_modified = src.last_modified;
	this->location = src.location;
	this->retry_after = src.retry_after;
	this->server = src.server;
	this->transfer_encoding = src.transfer_encoding;
	this->www_authenticate = src.www_authenticate;

	return (*this);
}

const std::string&	Response::getAllow(void) const
{
	return (this->allow);
}

const std::string&	Response::getContentLanguage(void) const
{
	return (this->content_language);
}

const std::string&	Response::getContentLength(void) const
{
	return (this->content_length);
}

const std::string&	Response::getContentType(void) const
{
	return (this->content_type);
}

const std::string&	Response::getDate(void) const
{
	return (this->date);
}

const std::string&	Response::getLastModified(void) const
{
	return (this->server);
}

const std::string&	Response::getLocation(void) const
{
	return (this->location);
}

const std::string&	Response::getRetryAfter(void) const
{
	return (this->retry_after);
}

const std::string&	Response::getServer(void) const
{
	return (this->server);
}

const std::string&	Response::getTransferEncoding(void) const
{
	return (this->transfer_encoding);
}

const std::string&	Response::getWWWAuthenticate(void) const
{
	return (this->www_authenticate);
}

void	Response::setAllow(const std::string& allow)
{
	this->allow = allow;
}

void	Response::setContentLanguage(const std::string& content_language)
{
	this->content_language = content_language;
}

void	Response::setContentLength(const std::string& content_length)
{
	this->content_length = content_length;
}

void	Response::setContentLocation(const std::string& content_location)
{
	this->content_location = content_location;
}

void	Response::setContentType(const std::string& content_type)
{
	this->content_type = content_type;
}

void	Response::setDate(const std::string& date)
{
	this->date = date;
}

void	Response::setLastModified(const std::string& last_modified)
{
	this->last_modified = last_modified;
}

void	Response::setLocation(const std::string& location)
{
	this->location = location;
}

void	Response::setRetryAfter(const std::string& retry_after)
{
	this->retry_after = retry_after;
}

void	Response::setServer(const std::string& server)
{
	this->server = server;
}

void	Response::setTransferEncoding(const std::string& transfer_encoding)
{
	this->transfer_encoding = transfer_encoding;
}

void	Response::setWWWAuthenticate(const std::string& www_authenticate)
{
	this->www_authenticate = www_authenticate;
}

void	Response::initResponse(void)
{
	this->allow = "";
	this->content_language = "";
	this->content_length = "";
	this->content_location = "";
	this->content_type = "";
	this->date = "";
	this->last_modified = "";
	this->location = "";
	this->retry_after = "";
	this->server = "";
	this->transfer_encoding = "";
	this->www_authenticate = "";
}

void	Response::createResponse(const Request& request)
{

}

void	Response::generateAllow(const Request& request, Server& server)
{
	for (std::map<std::string, Location>::iterator location_iter = server.getLocations().begin(); location_iter != server.getLocations().begin(); location_iter++)
	{
		for (std::list<std::string>::iterator iter = location_iter->second.getAllowMethods().begin(); iter != location_iter->second.getAllowMethods().end(); iter++)
		{
			this->
		}
	}
}

void	Response::generateContentLanguage(const Request& request)
{

}

void	Response::generateContentLength(const Request& request)
{

}

void	Response::generateContentLocation(const Request& request)
{

}

void	Response::generateContentType(const Request& request)
{

}

void	Response::generateDate(const Request& request)
{

}

void	Response::generateLastModified(const Request& request)
{

}

void	Response::generateLocation(const Request& request)
{

}

void	Response::generateRetryAfter(const Request& request)
{

}

void	Response::generateServer(const Request& request)
{

}

void	Response::generateTransferEncoding(const Request& request)
{

}

void	Response::generateWWWAuthenticate(const Request& request)
{

}