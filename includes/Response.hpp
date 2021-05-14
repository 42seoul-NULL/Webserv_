/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@42student.co.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:40:17 by juyang            #+#    #+#             */
/*   Updated: 2021/05/12 16:40:17 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include <iostream>
# include <map>
# include <ctime>
# include <sys/stat.h>
# include "Request.hpp"
# include "parser.hpp"

class Request;
class Server;
class Location;

class Response
{
	private:
		std::string	allow;
		std::string	content_language;
		std::string	content_length;
		std::string	content_location;
		std::string	content_type;
		std::string	date;
		std::string	last_modified;
		std::string	location;
		std::string	retry_after;
		std::string	server;
		std::string	transfer_encoding;
		std::string	www_authenticate;

		static std::map<std::string, std::string> mime_type;
		static std::map<std::string, std::string> status_code;

	public:
		Response(void);
		Response(const Response& src);
		virtual ~Response(void);

		Response&	operator=(const Response& src);

		const std::string&	getAllow(void) const;
		const std::string&	getContentLanguage(void) const;
		const std::string&	getContentLength(void) const;
		const std::string&	getContentLocation(void) const;
		const std::string&	getContentType(void) const;
		const std::string&	getDate(void) const;
		const std::string&	getLastModified(void) const;
		const std::string&	getLocation(void) const;
		const std::string&	getRetryAfter(void) const;
		const std::string&	getServer(void) const;
		const std::string&	getTransferEncoding(void) const;
		const std::string&	getWWWAuthenticate(void) const;

		void	setAllow(const std::string& allow);
		void	setContentLanguage(const std::string& content_language);
		void	setContentLength(const std::string& content_length);
		void	setContentLocation(const std::string& content_location);
		void	setContentType(const std::string& content_type);
		void	setDate(const std::string& date);
		void	setLastModified(const std::string& last_modified);
		void	setLocation(const std::string& location);
		void	setRetryAfter(const std::string& retry_after);
		void	setServer(const std::string& server);
		void	setTransferEncoding(const std::string& transfer_encoding);
		void	setWWWAuthenticate(const std::string& www_authenticate);

		void	initResponse(void);
		void	createResponse(const Request& request, const Server& server);

		void	generateAllow(const Request& request, Server& server);
		void	generateContentLanguage(const Request& request);
		void	generateContentLength(const Request& request);
		void	generateContentLocation(const Request& request);
		void	generateContentType(const Request& request);
		void	generateDate(const Request& request);
		void	generateLastModified(const Request& request);
		void	generateLocation(const Request& request, const Server& server);
		void	generateRetryAfter(const Request& request);
		void	generateServer(const Request& request);
		void	generateTransferEncoding(const Request& request);
		void	generateWWWAuthenticate(const Request& request);

		void	generateRawResponseHeader(void) const;
};

#endif
