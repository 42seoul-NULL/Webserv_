#include "../libft_cpp/libft.hpp"
#include "../includes/parser.hpp"
#include "../includes/Request.hpp"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	Request	test_request;

	while (test_request.tryMakeRequest())
		;

	// test_request.makeStartLine();
	// while (test_request.makeRequestHeader() == -1)
	// {
	// 	read() -> raw_request ->
	// };
	// test_request.makeRequestBody();
	std::cout << test_request.createRawRequest();

	// std::cout << ft_strlen("hello\n!!") << std::endl;
	std::cout << "\n\n<body>\n";
	test_request.bodyPrint();
}
