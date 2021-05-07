#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		index;

	index = 0;
	while (src[index])
		index++;
	dup = new char[index + 1];
	index = 0;
	while (src[index] != '\0')
	{
		dup[index] = src[index];
		index++;
	}
	dup[index] = src[index];
	return (dup);
}
