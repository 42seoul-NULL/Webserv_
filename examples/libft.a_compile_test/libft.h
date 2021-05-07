/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 10:39:25 by honlee            #+#    #+#             */
/*   Updated: 2021/05/07 13:31:29 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

extern "C" void				*ft_memset(void *ptr, int c, size_t size);
extern "C" void				ft_bzero(void *ptr, size_t length);
extern "C" void				*ft_memcpy(void *dest, const void *src, size_t len);
extern "C" void				*ft_memccpy(void *dest, const void *src, int c, size_t len);
extern "C" void				*ft_memmove(void *dest, const void *src, size_t len);
extern "C" void				*ft_memchr(const void *ptr, int value, size_t len);
extern "C" int					ft_memcmp(const void *ptr1, const void *ptr2, size_t len);
extern "C" size_t				ft_strlen(const char *str);
extern "C" size_t				ft_strlcpy(char *dest, const char *src, size_t size);
extern "C" size_t				ft_strlcat(char *dest, char *src, size_t size);
extern "C" char				*ft_strchr(const char *str, int value);
extern "C" char				*ft_strrchr(const char *str, int value);
extern "C" char				*ft_strnstr(const char *src, const char *str, size_t len);
extern "C" int					ft_strncmp(const char *str1, const char *str2, size_t len);
extern "C" int					ft_atoi(const char *str);
extern "C" int					ft_isalpha(int c);
extern "C" int					ft_isdigit(int c);
extern "C" int					ft_isalnum(int c);
extern "C" int					ft_isascii(int c);
extern "C" int					ft_isprint(int c);
extern "C" int					ft_toupper(int c);
extern "C" int					ft_tolower(int c);
extern "C" void				*ft_calloc(size_t ele_cnt, size_t ele_size);
extern "C" char				*ft_strdup(const char *src);
extern "C" char				*ft_substr(const char *s, unsigned int start, size_t len);
extern "C" char				*ft_strjoin(const char *s1, const char *s2);
extern "C" char				*ft_strtrim(const char *s1, const char *set);
extern "C" char				**ft_split(const char *str, char c);
extern "C" char				*ft_itoa(int n);
extern "C" char				*ft_strmapi(char const *str, char (*f)(unsigned int, char));
extern "C" void				ft_putchar_fd(char c, int fd);
extern "C" void				ft_putstr_fd(char *str, int fd);
extern "C" void				ft_putendl_fd(char *str, int fd);
extern "C" void				ft_putnbr_fd(int n, int fd);
extern "C" t_list				*ft_lstnew(void *content);
extern "C" void				ft_lstadd_front(t_list **lst, t_list *nw);
extern "C" int					ft_lstsize(t_list *lst);
extern "C" t_list				*ft_lstlast(t_list *lst);
extern "C" void				ft_lstadd_back(t_list **lst, t_list *nw);
extern "C" void				ft_lstdelone(t_list *lst, void (*del)(void *));
extern "C" void				ft_lstclear(t_list **lst, void (*del)(void *));
extern "C" void				ft_lstiter(t_list *lst, void (*f)(void *));
extern "C" t_list				*ft_lstmap(t_list *lst,
							void *(*f)(void *), void (*del)(void *));

#endif
