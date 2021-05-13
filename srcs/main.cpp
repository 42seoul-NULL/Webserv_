/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:34:00 by juyang            #+#    #+#             */
/*   Updated: 2021/05/13 16:34:01 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_cpp/libft.hpp"
#include "../includes/parser.hpp"
#include "../includes/Request.hpp"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	// std::string fake_request = "GET /tutorials/other/top-20-mysql-best-practices/ HTTP/1.1\r\nHost: net.tutsplus.com\r\nUser-Agent: Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US; rv:1.9.1.5) Gecko/20091102 Firefox/3.5.5 (.NET CLR 3.5.30729)\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nAccept-Language: en-us,en;q=0.5\r\nAccept-Encoding: gzip,deflate\r\nAccept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7\r\nKeep-Alive: 300\r\nConnection: keep-alive\r\nCookie: PHPSESSID=r2t5uvjq435r4q7ib3vtdjq120\r\nPragma: no-cache\r\nCache-Control: no-cache\r\n\r\n";

	Request	test_request;
	// test_request.initRequest();
	test_request.generateRequest();

	// test_request.generateStartLine();
	// while (test_request.generateRequestHeader() == -1)
	// {
	// 	read() -> raw_request -> 
	// };
	// test_request.generateRequestBody();
	std::cout << test_request.createRawRequest();

	// std::cout << ft_strlen("hello\n!!") << std::endl;
}
