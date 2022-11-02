#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	char c = 't';
	char s[] = "tachi";
	int	year = 26;
	int	result;
	int	tmp;

	result = ft_printf("My name is %c%s.\nI'm %d.\n", c, s, year);
	printf("%d\n", result);
	// result = printf("My name is %c%s.\nI'm %d.\n", c, s, year);
	// printf("%d\n", result);
	tmp = ft_printf("%u\n", INT_MAX);	// 2147483647
	printf("%d\n", tmp);				// 10 + 1
	tmp = ft_printf("%u\n", INT_MIN);	// 2147483648
	printf("%d\n", tmp);				// 10 + 1
	tmp = ft_printf("%x\n", INT_MAX);	// 7fffffff
	printf("%d\n", tmp);				// 9
	return (0);
}
