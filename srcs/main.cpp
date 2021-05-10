/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 09:32:06 by honlee            #+#    #+#             */
/*   Updated: 2021/05/10 15:27:12 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_cpp/libft.hpp"
#include "../includes/parser.hpp"
#include <vector>

int	main()
{
	std::vector<std::string> vec;
	ft_split("	   hi this    is	test!!		", " \t" , vec);

	for (std::vector<std::string>::iterator iter = vec.begin(); iter != vec.end(); iter++)
	{
		std::cout << "|" << *iter << "|" << std::endl;
	}
}