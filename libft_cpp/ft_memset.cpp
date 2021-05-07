#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *temp;

	temp = (unsigned char *)s;
	while (n--)
		*(temp++) = (unsigned char)c;
	return (s);
}
