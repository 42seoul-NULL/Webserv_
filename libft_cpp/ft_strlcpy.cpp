#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t size;

	i = 0;
	size = 0;
	if (dest == 0 || src == 0)
		return (0);
	while (src[size])
		size++;
	if (n > 0)
	{
		while (src[i] != 0 && i < (n - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (size);
}
