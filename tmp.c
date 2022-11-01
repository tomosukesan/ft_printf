#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
//#include "../libft/libft.h"

void	foo(char *fmt, ...);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

int	main(void)
{
	char s[] = "ttachi";
	int	year = 26;
	foo("My name is %s.\nI'm %d.\n", s, year);
	return (0);
}

void foo(char *fmt, ...)
{
	va_list ap;
	int d;
	char c;
	char *s;

	va_start(ap, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 's')
			{
				s = va_arg(ap, char *);
				ft_putstr_fd(s, 1);
			}
			else if (*fmt == 'd')
			{
				d = va_arg(ap, int);
				ft_putnbr_fd(d, 1);
			}
			else if (*fmt == 'c')
			{
				c = va_arg(ap, int);
				ft_putchar_fd(c, 1);
			}
			else if (*fmt == '%')
				write(1, fmt, 1);
			fmt++;
		}
		else
		{
			write(1, fmt, 1);
			fmt++;
		}
	}
	va_end(ap);
}

size_t	ft_strlen(const char *str)
{
	size_t	num;

	num = 0;
	while (str[num] != '\0')
		num++;
	return (num);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	s_len;

	if (s == NULL)
		return ;
	s_len = ft_strlen(s);
	if (s_len > INT_MAX)
	{
		write(fd, s, INT_MAX);
		write(fd, &s[INT_MAX], s_len - INT_MAX);
	}
	else
		write(fd, s, s_len);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	devisor;
	long long	tmp;
	char		num;

	devisor = 1;
	tmp = (long long)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		tmp *= -1;
	}
	while (n <= -10 || n >= 10)
	{
		devisor *= 10;
		n /= 10;
	}
	while (devisor)
	{
		num = (char)(tmp / devisor);
		ft_putchar_fd(num + '0', fd);
		tmp %= devisor;
		devisor /= 10;
	}
}