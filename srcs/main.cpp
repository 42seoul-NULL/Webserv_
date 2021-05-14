/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <kilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:34:00 by juyang            #+#    #+#             */
/*   Updated: 2021/05/14 11:45:44 by kilee            ###   ########.fr       */
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

	while (test_request.tryMakeRequest())
		;

	// test_request.makeStartLine();
	// while (test_request.tryMakeRequestHeader() == -1)
	// {
	// 	read() -> raw_request ->
	// };
	// test_request.tryMakeRequestBody();
	std::cout << test_request.createRawRequest();

	// std::cout << ft_strlen("hello\n!!") << std::endl;
	std::cout << "\n\n<body>\n";
	test_request.bodyPrint();
}
