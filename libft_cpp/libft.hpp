/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 20:43:53 by hyeonseun         #+#    #+#             */
/*   Updated: 2021/05/10 09:35:52 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_HPP
# define LIBFT_HPP

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <string>
# include <vector>

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
// void				*ft_memcpy(void *dest, const void *src, size_t n);
// void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
// void				*ft_memmove(void *dst, const void *src, size_t len);
// void				*ft_memchr(const void *s, int c, size_t n);
// int					ft_memcmp(const void *s1, const void *s2, size_t n);
// int					ft_strlen(const char *str);
// size_t				ft_strlcpy(char *dst, const char *src, size_t size);
// size_t				ft_strlcat(char *dest, const char *src, size_t dstsize);
// char				*ft_strchr(const char *s, int c);
// char				*ft_strrchr(const char *s, int c);
// char				*ft_strnstr(const char *str, const char *to_find, size_t len);
// int					ft_strncmp(char *s1, char *s2, size_t n);
int					ft_atoi(const std::string& str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

// void				*ft_calloc(size_t count, size_t size);
// char				*ft_strdup(const char *src);

// char				*ft_substr(const char *s, unsigned int start, size_t len);
// char				*ft_strjoin(char const *s1, char const *s2);
bool				ft_split(const std::string &target, const std::string& sep, std::vector<std::string> &saver);
// char				*ft_strtrim(char const *s1, char const *set);
std::string			ft_itoa(int n);
std::string			ft_strmapi(const char *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const std::string &str, int fd);
void				ft_putendl_fd(const std::string &str, int fd);
void				ft_putnbr_fd(int n, int fd);

int					ft_nbr_length(int n);
int					get_next_line(int fd, std::string &line);

#endif
