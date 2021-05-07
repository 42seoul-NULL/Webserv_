#include "libft.h"

const char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*result;

	if (s == 0)
		return (0);
	if ((result = (char *)malloc(sizeof(char) * (len + 1))) == 0)
		return (0);
	size = ft_strlen(s);
	i = 0;
	while (i < len && i + start < size)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = 0;
	return (result);
}