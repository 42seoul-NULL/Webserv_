#include "libft.h"

std::string			ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	std::string		newstr(s);
	unsigned int	i;

	if (s == 0 || f == 0)
		return (NULL);
	i = 0;
	while (s[i])
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
