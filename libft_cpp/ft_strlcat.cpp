#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	char			*dst;
	const char		*src_start;
	unsigned int	dst_digit;
	unsigned int	remain;

	dst = dest;
	src_start = src;
	remain = dstsize;
	while (remain-- != 0 && *dst != '\0')
		dst++;
	dst_digit = dst - dest;
	remain = dstsize - dst_digit;
	if (remain == 0)
		return (dst_digit + ft_strlen(src));
	while (*src != '\0')
	{
		if (remain > 1)
		{
			*dst++ = *src;
			remain--;
		}
		src++;
	}
	*dst = '\0';
	return (dst_digit + (src - src_start));
}
