#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*result;
	unsigned char	*source;
	size_t			i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	result = (unsigned char *)dest;
	source = (unsigned char *)src;
	while (i < n)
	{
		result[i] = source[i];
		if (source[i] == (unsigned char)c)
			return ((void *)(result + i + 1));
		i++;
	}
	return (NULL);
}
