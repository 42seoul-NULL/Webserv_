/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:01:33 by juyang            #+#    #+#             */
/*   Updated: 2021/05/13 17:36:15 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_HPP
# define REQUEST_HPP

# include <iostream>
# include <sys/time.h>
# include <ctime>

class Request
{
	private:
		std::string method;
		std::string uri;
		std::string	accept_charsets;
		std::string	accept_language;
		std::string	authorization;
		std::string	content_length;
		std::string	content_type;
		std::string	date;
		std::string	host;
		std::string	referer;
		std::string	transfer_encoding;
		std::string	user_agent;

		std::string		raw_request;

	public:
		Request(void);
		Request(const Request& src) {};
		virtual ~Request(void) {};
		Request& operator=(const Request& src) {};

		const std::string&	getAcceptCharsets(void) const;
		const std::string&	getAcceptLanguage(void) const;
		const std::string&	getAuthorization(void) const;
		const std::string&	getContentLength(void) const;
		const std::string&	getContentType(void) const;
		const std::string&	getDate(void) const;
		const std::string&	getHost(void) const;
		const std::string&	getReferer(void) const;
		const std::string&	getTransferEncoding(void) const;
		const std::string&	getUserAgent(void) const;
		std::string&		getRawRequest(void);

		void	setAcceptCharsets(const std::string& accept_charsets);
		void	setAcceptLanguage(const std::string& accept_language);
		void	setAuthorization(const std::string& authorization);
		void	setContentLength(const std::string& content_length);
		void	setContentType(const std::string& content_type);
		void	setDate(const std::string& date);
		void	setHost(const std::string& host);
		void	setReferer(const std::string& referer);
		void	setTransferEncoding(const std::string& transfer_encoding);
		void	setUserAgent(const std::string& user_agent);

		

		std::string&	createRequestHeader();
};

#endif
