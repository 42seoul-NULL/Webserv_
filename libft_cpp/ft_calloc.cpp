#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	unsigned char *result;

	result = new unsigned char[size * count];
	ft_memset(result, 0, size * count);
	return (result);
}
