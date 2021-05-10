#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				sign;
	size_t			index;
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	sign = 1;
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	if (dest > src)
	{
		sign = -1;
		temp_dest = ((unsigned char *)dest + n - 1);
		temp_src = ((unsigned char *)src + n - 1);
	}
	index = 0;
	while (index < n)
	{
		*temp_dest = *temp_src;
		temp_dest += sign;
		temp_src += sign;
		index++;
	}
	return (dest);
}
