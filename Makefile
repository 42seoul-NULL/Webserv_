# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honlee <honlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 21:20:00 by honlee            #+#    #+#              #
#    Updated: 2021/05/10 09:48:42 by honlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=		\
					main.cpp\

NAME		=		webserv

LIB_NAME	=		libft.a

CC			=		clang++

CF			=		-Wall -Wextra -Werror -std=c++98 ${SRCS}
DCF			=		-g ${SRCS}

${NAME}     :
					make all -C "./libft_cpp"
					cp libft_cpp/${LIB_NAME} ${LIB_NAME}
					${CC} ${CF} ${LIB_NAME} -o ${NAME} 

test		:		fclean
					${CC} ${DCF} -o ${NAME}

fclean		:		
					make fclean -C "./libft_cpp"
					rm -rf ${NAME}
					rm -rf ${LIB_NAME}

re			:		fclean all

all         :      	${NAME}

.PHONY		:		fclean re all test ${NAME}