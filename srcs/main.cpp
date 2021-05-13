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
	
	Request	test_request;

	while (test_request.generateRequest())
		;

	// test_request.generateStartLine();
	// while (test_request.generateRequestHeader() == -1)
	// {
	// 	read() -> raw_request -> 
	// };
	// test_request.generateRequestBody();
	std::cout << test_request.createRawRequest();

	// std::cout << ft_strlen("hello\n!!") << std::endl;
	std::cout << "\n\n<body>\n";
	test_request.bodyPrint();
}
