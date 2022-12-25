#include <stdio.h>
#include "../ft_printf.h"

int main (void)
{
	char	c = 'a';
	char	*s = "42tokyo";
	int		d = 42;
	int		m = -42;
	int		tmp1;
	int		tmp2;

/*
    - zero
        - %#0x
        - %010x ＞ MISS：0が過多 ＞ ft_hex_flags関数でのif (flag.zero)内を変更
        - %010.3x ＞ MISS：0が過小 ＞ dotフラグの有無で変化するよう対処
        - %010.8x, %03.8x, %03.2x
*/

	puts("\n[%#x]");
	tmp1 =   printf("printf   :%#x\n", d);
	   printf("printf   :%#X\n", d);
	tmp2 = ft_printf("ft_printf:%#x\n", d);
	ft_printf("ft_printf:%#X\n", d);
	printf("printf: %d, ft_printf: %d", tmp1, tmp2);

	puts("\n[%#10x]");
	tmp1 =   printf("printf   :%#10x\n", d);
	   printf("printf   :%#10X\n", d);
	tmp2 = ft_printf("ft_printf:%#10x\n", d);
	ft_printf("ft_printf:%#10X\n", d);
	printf("printf: %d, ft_printf: %d", tmp1, tmp2);

	puts("\n[%#10.3x]");
	tmp1 =   printf("printf   :%#10.3x\n", d);
	   printf("printf   :%#10.3X\n", d);
	tmp2 = ft_printf("ft_printf:%#10.3x\n", d);
	ft_printf("ft_printf:%#10.3X\n", d);
	printf("printf: %d, ft_printf: %d", tmp1, tmp2);

	puts("\n[%#10.8x]");
	tmp1 =   printf("printf   :%#10.8x\n", d);
	   printf("printf   :%#10.8X\n", d);
	tmp2 = ft_printf("ft_printf:%#10.8x\n", d);
	ft_printf("ft_printf:%#10.8X\n", d);
	printf("printf: %d, ft_printf: %d", tmp1, tmp2);

	puts("\n[%#3.8x]");
	tmp1 =   printf("printf   :%#3.8x\n", d);
	   printf("printf   :%#3.8X\n", d);
	tmp2 = ft_printf("ft_printf:%#3.8x\n", d);
	ft_printf("ft_printf:%#3.8X\n", d);
	printf("printf: %d, ft_printf: %d", tmp1, tmp2);

	puts("\n[%#3.2x]");
	tmp1 =    printf("printf   :%#3.2x\n", d);
	   printf("printf   :%#3.2X\n", d);
	tmp2 = ft_printf("ft_printf:%#3.2x\n", d);
	ft_printf("ft_printf:%#3.2X\n", d);
	printf("printf: %d, ft_printf: %d", tmp1, tmp2);

	puts("\n+++++++++++++++++++++++++++");

	puts("\n[%#-x]");
	tmp1 =   printf("printf   :%#-x\n", d);
	   printf("printf   :%#-X\n", d);
	tmp2 = ft_printf("ft_printf:%#-x\n", d);
	ft_printf("ft_printf:%#-X\n", d);
	printf("printf: %d, ft_printf: %d", tmp1, tmp2);

	puts("\n[%#-10x]");
	tmp1 =   printf("printf   :%#-10x\n", d);
	   printf("printf   :%#-10X\n", d);
	tmp2 = ft_printf("ft_printf:%#-10x\n", d);
	ft_printf("ft_printf:%#-10X\n", d);
	printf("printf: %d, ft_printf: %d", tmp1, tmp2);

	puts("\n[%#-10.3x]");
	   printf("printf   :%#-10.3x\n", d);
	   printf("printf   :%#-10.3X\n", d);
	ft_printf("ft_printf:%#-10.3x\n", d);
	ft_printf("ft_printf:%#-10.3X\n", d);

	puts("\n[%#-10.8x]");
	tmp1 =   printf("printf   :%#-10.8x\n", d);
	   printf("printf   :%#-10.8X\n", d);
	tmp2 = ft_printf("ft_printf:%#-10.8x\n", d);
	ft_printf("ft_printf:%#-10.8X\n", d);
	printf("printf: %d, ft_printf: %d", tmp1, tmp2);

	puts("\n[%#-3.8x]");
	tmp1 =    printf("printf   :%#-3.8x\n", d);
	   printf("printf   :%#-3.8X\n", d);
	tmp2 = ft_printf("ft_printf:%#-3.8x\n", d);
	ft_printf("ft_printf:%#-3.8X\n", d);
	printf("printf: %d, ft_printf: %d", tmp1, tmp2);

	puts("\n[%#-3.2x]");
	tmp1 =    printf("printf   :%#-3.2x\n", d);
	   printf("printf   :%#-3.2X\n", d);
	tmp2 = ft_printf("ft_printf:%#-3.2x\n", d);
	ft_printf("ft_printf:%#-3.2X\n", d);
	printf("printf: %d, ft_printf: %d", tmp1, tmp2);

	puts("\n+++++++++++++++++++++++++++");

	puts("\n[%#0x]");
	tmp1 =   printf("printf   :%#0x\n", d);
	   printf("printf   :%#0X\n", d);
	tmp2 = ft_printf("ft_printf:%#0x\n", d);
	ft_printf("ft_printf:%#0X\n", d);
	printf("printf: %d, ft_printf: %d", tmp1, tmp2);

	puts("\n[%#010x]");
	tmp1 =   printf("printf   :%#010x\n", d);
	   printf("printf   :%#010X\n", d);
	tmp2 = ft_printf("ft_printf:%#010x\n", d);
	ft_printf("ft_printf:%#010X\n", d);
	printf("printf: %d, ft_printf: %d", tmp1, tmp2);

	puts("\n[%#010.3x]");
	tmp1 =   printf("printf   :%#010.3x\n", d);
	   printf("printf   :%#010.3X\n", d);
	tmp2 = ft_printf("ft_printf:%#010.3x\n", d);
	ft_printf("ft_printf:%#010.3X\n", d);
	printf("printf: %d, ft_printf: %d", tmp1, tmp2);

	puts("\n[%#010.8x]");
	tmp1 =   printf("printf   :%#010.8x\n", d);
	   printf("printf   :%#010.8X\n", d);
	tmp2 = ft_printf("ft_printf:%#010.8x\n", d);
	ft_printf("ft_printf:%#010.8X\n", d);
	printf("printf: %d, ft_printf: %d", tmp1, tmp2);

	puts("\n[%#03.8x]");
	tmp1 =   printf("printf   :%#03.8x\n", d);
	   printf("printf   :%#03.8X\n", d);
	tmp2 = ft_printf("ft_printf:%#03.8x\n", d);
	ft_printf("ft_printf:%#03.8X\n", d);
	printf("printf: %d, ft_printf: %d", tmp1, tmp2);

	puts("\n[%#03.2x]");
	tmp1 =   printf("printf   :%#03.2x\n", d);
	   printf("printf   :%#03.2X\n", d);
	tmp2 = ft_printf("ft_printf:%#03.2x\n", d);
	ft_printf("ft_printf:%#03.2X\n", d);
	printf("printf: %d, ft_printf: %d", tmp1, tmp2);

	return (0);
}