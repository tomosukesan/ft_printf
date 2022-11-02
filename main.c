#include "libftprintf.h"

int	main(void)
{
	char c = 't';
	char s[] = "tachi";
	int	year = 26;
	ft_printf("My name is %c%s.\nI'm %d.\n", c, s, year);
	return (0);
}
