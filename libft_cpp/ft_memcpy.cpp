#include "libft.h"

void				*ft_memcpy(void *dest, const void *source, size_t n)
{
	unsigned char	*temp;
	unsigned char	*cpyd;

	if (dest == NULL && source == NULL)
		return (dest);
	temp = (unsigned char *)source;
	cpyd = (unsigned char *)dest;
	while (n)
	{
		*cpyd++ = *temp++;
		n--;
	}
	return (dest);
}
