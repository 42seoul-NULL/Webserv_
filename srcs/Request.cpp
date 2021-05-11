/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:39:16 by juyang            #+#    #+#             */
/*   Updated: 2021/05/10 18:39:16 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Request.hpp"

Request::Request(void) : accept_charsets(""), accept_language(""), authorization(""), content_length(""), content_type(""), date(""), host(""), referer(""), transfer_encoding(""), user_agent("")
{

}

Request::Request(const Request& src)
{
	(void)src;
}

Request&	Request::operator=(const Request& src)
{
	(void)src;

	return (*this);
}

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

void	Request::initRequest(void)
{
	this->accept_charsets = "";
	this->accept_language = "";
	this->authorization = "";
	this->content_length = "";
	this->content_type = "";
	this->date = "";
	this->host = "";
	this->referer = "";
	this->transfer_encoding = "";
	this->user_agent = "";
}

void	Request::generateRequest(const std::string& raw)
{
	std::string	raw_header = raw.substr(raw.find("\r\n"));

	parseAcceptCharsets(raw_header);
	parseAcceptLanguage(raw_header);
	parseAuthorization(raw_header);
	parseContentLength(raw_header);
	parseContentType(raw_header);
	parseDate(raw_header);
	parseHost(raw_header);
	parseReferer(raw_header);
	parseTransferEncoding(raw_header);
	parseUserAgent(raw_header);
}

void	Request::parseAcceptCharsets(const std::string& raw)
{
	std::string	key = "Accept-Charsets: ";
	std::size_t	found = raw.find(key);

	if (found != std::string::npos)
	{
		std::size_t	target_pos = found + key.length();

		this->accept_charsets = raw.substr(target_pos, raw.find("\r\n", target_pos) - target_pos + 1);
	}
}

void	Request::parseAcceptLanguage(const std::string& raw)
{
	std::string key = "Accept-Language: ";
	std::size_t found = raw.find(key);

	if (found != std::string::npos)
	{
		std::size_t target_pos = found + key.length();
		
		this->accept_language = raw.substr(target_pos, raw.find("\r\n", target_pos) - target_pos + 1);
	}
}

void	Request::parseAuthorization(const std::string& raw)
{
	std::string key = "Authorization: ";
	std::size_t found = raw.find(key);

	if (found != std::string::npos)
	{
		std::size_t target_pos = found + key.length();
		
		this->authorization = raw.substr(target_pos, raw.find("\r\n", target_pos) - target_pos + 1);
	}
}

void	Request::parseContentLength(const std::string& raw)
{
	std::string key = "Content-Length: ";
	std::size_t found = raw.find(key);

	if (found != std::string::npos)
	{
		std::size_t target_pos = found + key.length();
		
		this->content_length = raw.substr(target_pos, raw.find("\r\n", target_pos) - target_pos + 1);
	}
}

void	Request::parseContentType(const std::string& raw)
{
	std::string key = "Content-Type: ";
	std::size_t found = raw.find(key);

	if (found != std::string::npos)
	{
		std::size_t target_pos = found + key.length();
		
		this->content_type = raw.substr(target_pos, raw.find("\r\n", target_pos) - target_pos + 1);
	}
}

void	Request::parseDate(const std::string& raw)
{
	std::string key = "Date: ";
	std::size_t found = raw.find(key);

	if (found != std::string::npos)
	{
		std::size_t target_pos = found + key.length();
		
		this->date = raw.substr(target_pos, raw.find("\r\n", target_pos) - target_pos + 1);
	}
}

void	Request::parseHost(const std::string& raw)
{
	std::string key = "Host: ";
	std::size_t found = raw.find(key);

	if (found != std::string::npos)
	{
		std::size_t target_pos = found + key.length();
		
		this->host = raw.substr(target_pos, raw.find("\r\n", target_pos) - target_pos + 1);
	}
}

void	Request::parseReferer(const std::string& raw)
{
	std::string key = "Referer: ";
	std::size_t found = raw.find(key);

	if (found != std::string::npos)
	{
		std::size_t target_pos = found + key.length();
		
		this->referer = raw.substr(target_pos, raw.find("\r\n", target_pos) - target_pos + 1);
	}
}

void	Request::parseTransferEncoding(const std::string& raw)
{
	std::string key = "Transfer-Encoding: ";
	std::size_t found = raw.find(key);

	if (found != std::string::npos)
	{
		std::size_t target_pos = found + key.length();
		
		this->transfer_encoding = raw.substr(target_pos, raw.find("\r\n", target_pos) - target_pos + 1);
	}
}

void	Request::parseUserAgent(const std::string& raw)
{
	std::string key = "User-Agent: ";
	std::size_t found = raw.find(key);

	if (found != std::string::npos)
	{
		std::size_t target_pos = found + key.length();
		
		this->user_agent = raw.substr(target_pos, raw.find("\r\n", target_pos) - target_pos + 1);
	}
}

std::string	Request::createRawRequest(void) const
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