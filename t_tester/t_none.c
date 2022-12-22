#include <stdio.h>
#include "ft_printf.h"

int main (void)
{
	char	c = 'a';
	char	*s = "42tokyo";
	int		d = 42;
	int		m = -42;

	puts("\n[%d]");
	   printf("printf   :%c\n", c);
	   printf("printf   :%s\n", s);
	   printf("printf   :%d\n", d);
	   printf("printf   :%d\n", m);
	   printf("printf   :%u\n", d);
	   printf("printf   :%x\n", d);
	   printf("printf   :%X\n", d);
	   printf("printf   :%p\n", &d);
	ft_printf("ft_printf:%c\n", c);
	ft_printf("ft_printf:%s\n", s);
	ft_printf("ft_printf:%d\n", d);
	ft_printf("ft_printf:%d\n", m);
	ft_printf("ft_printf:%u\n", d);
	ft_printf("ft_printf:%x\n", d);
	ft_printf("ft_printf:%X\n", d);
	ft_printf("ft_printf:%p\n", &d);

	puts("\n[%10d]");
	   printf("printf   :%10c\n", c);
	   printf("printf   :%10s\n", s);
	   printf("printf   :%10d\n", d);
	   printf("printf   :%10d\n", m);
	   printf("printf   :%10u\n", d);
	   printf("printf   :%10x\n", d);
	   printf("printf   :%10X\n", d);
	   printf("printf   :%10p\n", &d);
	ft_printf("ft_printf:%10c\n", c);
	ft_printf("ft_printf:%10s\n", s);
	ft_printf("ft_printf:%10d\n", d);
	ft_printf("ft_printf:%10d\n", m);
	ft_printf("ft_printf:%10u\n", d);
	ft_printf("ft_printf:%10x\n", d);
	ft_printf("ft_printf:%10X\n", d);
	ft_printf("ft_printf:%10p\n", &d);

	puts("\n[%10.3d]");
	   printf("printf   :%10.3c\n", c);	// undefined
	   printf("printf   :%10.3s\n", s);
	   printf("printf   :%10.3d\n", d);
	   printf("printf   :%10.3d\n", m);
	   printf("printf   :%10.3u\n", d);
	   printf("printf   :%10.3x\n", d);
	   printf("printf   :%10.3X\n", d);
	   printf("printf   :%10.3p\n", &d);	// undefined
	ft_printf("ft_printf:%10.3c\n", c);
	ft_printf("ft_printf:%10.3s\n", s);
	ft_printf("ft_printf:%10.3d\n", d);
	ft_printf("ft_printf:%10.3d\n", m);
	ft_printf("ft_printf:%10.3u\n", d);
	ft_printf("ft_printf:%10.3x\n", d);
	ft_printf("ft_printf:%10.3X\n", d);
	ft_printf("ft_printf:%10.3p\n", &d);

	puts("\n[%10.8d]");
	   printf("printf   :%10.8c\n", c);	// undefined
	   printf("printf   :%10.8s\n", s);
	   printf("printf   :%10.8d\n", d);
	   printf("printf   :%10.8d\n", m);
	   printf("printf   :%10.8u\n", d);
	   printf("printf   :%10.8x\n", d);
	   printf("printf   :%10.8X\n", d);
	   printf("printf   :%10.8p\n", &d);	// undefined
	ft_printf("ft_printf:%10.8c\n", c);
	ft_printf("ft_printf:%10.8s\n", s);
	ft_printf("ft_printf:%10.8d\n", d);
	ft_printf("ft_printf:%10.8d\n", m);
	ft_printf("ft_printf:%10.8u\n", d);
	ft_printf("ft_printf:%10.8x\n", d);
	ft_printf("ft_printf:%10.8X\n", d);
	ft_printf("ft_printf:%10.8p\n", &d);

	puts("\n[%3.8d]");
	   printf("printf   :%3.8c\n", c);		// undefined
	   printf("printf   :%3.8s\n", s);
	   printf("printf   :%3.8d\n", d);
	   printf("printf   :%3.8d\n", m);
	   printf("printf   :%3.8u\n", d);
	   printf("printf   :%3.8x\n", d);
	   printf("printf   :%3.8X\n", d);
	   printf("printf   :%3.8p\n", &d);	// undefined
	ft_printf("ft_printf:%3.8c\n", c);
	ft_printf("ft_printf:%3.8s\n", s);
	ft_printf("ft_printf:%3.8d\n", d);
	ft_printf("ft_printf:%3.8d\n", m);
	ft_printf("ft_printf:%3.8u\n", d);
	ft_printf("ft_printf:%3.8x\n", d);
	ft_printf("ft_printf:%3.8X\n", d);
	ft_printf("ft_printf:%3.8p\n", &d);

	puts("\n[%3.2d]");
	   printf("printf   :%3.2c\n", c);		// undefined
	   printf("printf   :%3.2s\n", s);
	   printf("printf   :%3.2d\n", d);
	   printf("printf   :%3.2d\n", m);
	   printf("printf   :%3.2u\n", d);
	   printf("printf   :%3.2x\n", d);
	   printf("printf   :%3.2X\n", d);
	   printf("printf   :%3.2p\n", &d);	// undefined
	ft_printf("ft_printf:%3.2c\n", c);
	ft_printf("ft_printf:%3.2s\n", s);
	ft_printf("ft_printf:%3.2d\n", d);
	ft_printf("ft_printf:%3.2d\n", m);
	ft_printf("ft_printf:%3.2u\n", d);
	ft_printf("ft_printf:%3.2x\n", d);
	ft_printf("ft_printf:%3.2X\n", d);
	ft_printf("ft_printf:%3.2p\n", &d);

	return (0);
}