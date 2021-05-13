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

Request::Request(void) : raw_request(""), method(""), uri(""), http_version(""), accept_charsets(""), accept_language(""), authorization(""), content_length(""), content_type(""), date(""), host(""), referer(""), transfer_encoding(""), user_agent(""), status(0), type(0)
{
	this->raw_request = "GET /tutorials/other/top-20-mysql-best-practices/ HTTP/1.1\r\nHost: net.tutsplus.com\r\nUser-Agent: Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US; rv:1.9.1.5) Gecko/20091102 Firefox/3.5.5 (.NET CLR 3.5.30729)\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nAccept-Language: en-us,en;q=0.5\r\nAccept-Encoding: gzip,deflate\r\nAccept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7\r\n\r\n2\r\nab\r\n3\r\nxyz\r\n2\r\nef\r\n0\r\n";
}

Request::Request(const Request& src) : raw_request(src.raw_request), method(src.method), uri(src.uri), http_version(src.http_version), accept_language(src.accept_language), authorization(src.authorization), content_length(src.content_length), content_type(src.content_type), date(src.date), host(src.host), referer(src.referer), transfer_encoding(src.transfer_encoding), user_agent(src.user_agent), status(src.status), type(src.type)
{

}

Request&	Request::operator=(const Request& src)
{
	this->raw_request = src.raw_request;
	this->method = src.method;
	this->uri = src.uri;
	this->http_version = src.http_version;
	this->accept_charsets = src.accept_charsets;
	this->accept_language = src.accept_language;
	this->authorization = src.authorization;
	this->content_length = src.content_length;
	this->content_type = src.content_type;
	this->date = src.date;
	this->host = src.host;
	this->referer = src.referer;
	this->transfer_encoding = src.transfer_encoding;
	this->user_agent = src.user_agent;
	this->status = 0;
	this->type = 0;

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

void	Request::setRawRequest(const std::string& raw_request)
{
	this->raw_request = raw_request;
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

int	Request::generateRequest(void)
{
	std::size_t	found = this->raw_request.find("\r\n\r\n");
	int	res = 1;

	if (found != std::string::npos && status == 0)
	{
		this->generateStartLine();
		this->generateRequestHeader();
		status = 1;
		res = bodyCheck();
	}
	else if (status == 1)
	{
		this->generateRequestBody();
		return (isComplete());
	}
	return (1);
}

void	Request::generateStartLine(void)
{
	this->parseMethod();
	this->parseUri();
	this->parseHttpVersion();
}

void	Request::generateRequestHeader(void)
{
	this->raw_header = this->raw_request.substr(this->raw_request.find("\r\n") + 1, this->raw_request.find("\r\n\r\n"));

	this->parseAcceptCharsets();
	this->parseAcceptLanguage();
	this->parseAuthorization();
	this->parseContentLength();
	this->parseContentType();
	this->parseDate();
	this->parseHost();
	this->parseReferer();
	this->parseTransferEncoding();
	this->parseUserAgent();

	//this->transfer_encoding = "chunked";        테스트 할라고 청크만들어서 해쏘요

	this->temp_body += this->raw_request.substr(this->raw_request.find("\r\n\r\n") + 4);
	this->raw_request.clear();
}

void	Request::generateRequestBody(void)
{
	this->temp_body += raw_request;
}

void	Request::parseMethod(void)
{
	std::size_t	found = this->raw_request.find("\r\n");
	std::string start_line = this->raw_request.substr(0, found);

	this->method = start_line.substr(0, start_line.find(' '));
}

void	Request::parseUri(void)
{
	std::size_t	found = this->raw_request.find("\r\n");
	std::string start_line = this->raw_request.substr(0, found);
	std::size_t start_pos = start_line.find(' ');

	this->uri = start_line.substr(start_pos + 1, start_line.find_last_of(' ') - start_pos);
}

void	Request::parseHttpVersion(void)
{
	std::size_t	found = this->raw_request.find("\r\n");
	std::string start_line = this->raw_request.substr(0, found);
	
	this->http_version = start_line.substr(start_line.find_last_of(' ') + 1);
}

void	Request::parseAcceptCharsets(void)
{
	std::string	key = "Accept-Charset: ";
	std::size_t	found = this->raw_header.find(key);

	if (found != std::string::npos)
	{
		std::size_t	target_pos = found + key.length();

		this->accept_charsets = this->raw_header.substr(target_pos, this->raw_header.find("\r\n", target_pos) - target_pos + 1);
	}
}

void	Request::parseAcceptLanguage(void)
{
	std::string key = "Accept-Language: ";
	std::size_t found = this->raw_header.find(key);

	if (found != std::string::npos)
	{
		std::size_t target_pos = found + key.length();
		
		this->accept_language = this->raw_header.substr(target_pos, this->raw_header.find("\r\n", target_pos) - target_pos + 1);
	}
}

void	Request::parseAuthorization(void)
{
	std::string key = "Authorization: ";
	std::size_t found = this->raw_header.find(key);

	if (found != std::string::npos)
	{
		std::size_t target_pos = found + key.length();
		
		this->authorization = this->raw_header.substr(target_pos, this->raw_header.find("\r\n", target_pos) - target_pos + 1);
	}
}

void	Request::parseContentLength(void)
{
	std::string key = "Content-Length: ";
	std::size_t found = this->raw_header.find(key);

	if (found != std::string::npos)
	{
		std::size_t target_pos = found + key.length();
		
		this->content_length = this->raw_header.substr(target_pos, this->raw_header.find("\r\n", target_pos) - target_pos + 1);
	}
}

void	Request::parseContentType(void)
{
	std::string key = "Content-Type: ";
	std::size_t found = this->raw_header.find(key);

	if (found != std::string::npos)
	{
		std::size_t target_pos = found + key.length();
		
		this->content_type = this->raw_header.substr(target_pos, this->raw_header.find("\r\n", target_pos) - target_pos + 1);
	}
}

void	Request::parseDate(void)
{
	std::string key = "Date: ";
	std::size_t found = this->raw_header.find(key);

	if (found != std::string::npos)
	{
		std::size_t target_pos = found + key.length();
		
		this->date = this->raw_header.substr(target_pos, this->raw_header.find("\r\n", target_pos) - target_pos + 1);
	}
}

void	Request::parseHost(void)
{
	std::string key = "Host: ";
	std::size_t found = this->raw_header.find(key);

	if (found != std::string::npos)
	{
		std::size_t target_pos = found + key.length();
		
		this->host = this->raw_header.substr(target_pos, this->raw_header.find("\r\n", target_pos) - target_pos + 1);
	}
}

void	Request::parseReferer(void)
{
	std::string key = "Referer: ";
	std::size_t found = this->raw_header.find(key);

	if (found != std::string::npos)
	{
		std::size_t target_pos = found + key.length();
		
		this->referer = this->raw_header.substr(target_pos, this->raw_header.find("\r\n", target_pos) - target_pos + 1);
	}
}

void	Request::parseTransferEncoding(void)
{
	std::string key = "Transfer-Encoding: ";
	std::size_t found = this->raw_header.find(key);

	if (found != std::string::npos)
	{
		std::size_t target_pos = found + key.length();
		
		this->transfer_encoding = this->raw_header.substr(target_pos, this->raw_header.find("\r\n", target_pos) - target_pos + 1);
	}
}

void	Request::parseUserAgent(void)
{
	std::string key = "User-Agent: ";
	std::size_t found = this->raw_header.find(key);

	if (found != std::string::npos)
	{
		std::size_t target_pos = found + key.length();
		
		this->user_agent = this->raw_header.substr(target_pos, this->raw_header.find("\r\n", target_pos) - target_pos + 1);
	}
}

bool	Request::bodyCheck(void)
{
	if (this->transfer_encoding == "chunked")
		this->type = 2;
	else if (this->content_length != "")
		this->type = 1;
	return (type);
}

bool	Request::isComplete(void)
{
	if (this->type == 1 && this->temp_body.length() >= (std::size_t)ft_atoi(this->content_length))
	{
		this->raw_body += this->temp_body;
		this->temp_body.clear();
	}
	else if (this->type == 2)
	{
		std::size_t found = this->temp_body.find("\r\n");
		std::size_t	chunk_size;

		while  (found != std::string::npos)
		{
			chunk_size = ft_atoi(this->temp_body.substr(0, found)); // ft_atoi -> ft_atoi_hex 바꿔야함 10진수로 생각하고 테스트 중
			if (chunk_size == 0)
				return (false);
			this->temp_body = this->temp_body.substr(found + 2);
			if (this->temp_body.length() >= chunk_size)
			{
				found = this->temp_body.find("\r\n");
				raw_body += this->temp_body.substr(0, found);
				this->temp_body = this->temp_body.substr(found + 2);
			}
			found = this->temp_body.find("\r\n");
		}
	}
	return (true);
}

std::string	Request::createRawRequest(void) const
{
	std::string	header = std::string("");

	header += "Method: " + this->method + "\r\n";
	header += "URI: " + this->uri + "\r\n";
	header += "HTTP-Version: " + this->http_version + "\r\n";
	header += "Accept-Charset: " + this->accept_charsets + "\r\n";
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

void	Request::bodyPrint(void)
{
	std::cout << this->raw_body << std::endl;
}
