#include "libft.hpp"

int ft_atoi_hex(const std::string &str)
{
	std::string upper("0123456789ABCDEF");
	std::string lower("0123456789abcdef");

	size_t idx = 0;
	int i = 0;
	int result = 0;
	while (str[i]
		&& ((idx = upper.find(str[i]) != std::string::npos)
		|| (idx = lower.find(str[i]) != std::string::npos)))
	{
		result = result * 16 + idx;
		i++;
	}
	return (result);
}