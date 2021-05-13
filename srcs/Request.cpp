/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:39:16 by juyang            #+#    #+#             */
/*   Updated: 2021/05/13 19:32:31 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Request.hpp"

Request::Request(void) : accept_charsets(""), accept_language(""), authorization(""), content_length(""), content_type(""), date(""), host(""), referer(""), transfer_encoding(""), user_agent(""), raw_request("")
{

}

///////////////////////////////////////////////////////////////
/////////////       Request Class Getter        ///////////////
///////////////////////////////////////////////////////////////

const std::string&	Request::getAcceptCharsets(void) const
{
	return (this->accept_charsets);
}

const std::string&	Request::getAcceptLanguage(void) const
{
	return (this->accept_language);
}

const std::string&	Request::getAuthorization(void) const
{
	return (this->content_length);
}

const std::string&	Request::getContentLength(void) const
{
	return (this->content_length);
}

const std::string&	Request::getContentType(void) const
{
	return (this->content_type);
}

const std::string&	Request::getDate(void) const
{
	return (this->date);
}

const std::string&	Request::getHost(void) const
{
	return (this->host);
}

const std::string&	Request::getReferer(void) const
{
	return (this->referer);
}

const std::string&	Request::getTransferEncoding(void) const
{
	return (this->transfer_encoding);
}

const std::string&	Request::getUserAgent(void) const
{
	return (this->user_agent);
}

std::string& Request::getRawRequest()
{
	return (this->raw_request);
}

///////////////////////////////////////////////////////////////
/////////////       Request Class Setter        ///////////////
///////////////////////////////////////////////////////////////

void	Request::setAcceptCharsets(const std::string& accept_charsets)
{
	this->accept_charsets = accept_charsets;
}

void	Request::setAcceptLanguage(const std::string& accept_language)
{
	this->accept_language = accept_language;
}

void	Request::setAuthorization(const std::string& authorization)
{
	this->authorization = authorization;
}

void	Request::setContentLength(const std::string& content_length)
{
	this->content_length = content_length;
}

void	Request::setContentType(const std::string& content_type)
{
	this->content_type = content_type;
}

void	Request::setDate(const std::string& date)
{
	this->date = date;
}

void	Request::setHost(const std::string& host)
{
	this->host = host;
}

void	Request::setReferer(const std::string& referer)
{
	this->referer = referer;
}

void	Request::setTransferEncoding(const std::string& transfer_encoding)
{
	this->transfer_encoding = transfer_encoding;
}

void	Request::setUserAgent(const std::string& user_agent)
{
	this->user_agent = user_agent;
}

///////////////////////////////////////////////////////////////
/////////////         Request Variable          ///////////////
///////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
/////////////          Request Header           ///////////////
///////////////////////////////////////////////////////////////

std::string&	Request::createRequestHeader()
{
	std::string	header = std::string("");

	header += "Aceept-Charset: " + this->accept_charsets + "\r\n";
	header += "Accept-Language: " + this->accept_language + "\r\n";
	header += "Authorization: " + this->authorization + "\r\n";
	header += "Content-Length: " + this->content_length + "\r\n";
	header += "Content-Type: " + this->content_type + "\r\n";
	header += "Date: " + this->date + "\r\n";
	header += "Host: " + this->host + "\r\n";
	header += "Referer: " + this->referer + "\r\n";
	header += "Transfer-Encoding: " + this->transfer_encoding + "\r\n";
	header += "User-Agent: " + this->user_agent + "\r\n";
	header += "\r\n";

	return (header);
}