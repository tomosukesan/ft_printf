#include <stdio.h>
#include "ft_printf.h"

int main (void)
{
	char	c = 'a';
	char	*s = "42tokyo";
	int		d = 42;
	int		m = -42;

// none
	puts("\n[%.d]");
	   printf("printf   :%.c\n", c);
	   printf("printf   :%.s\n", s);
	   printf("printf   :%.d\n", d);
	   printf("printf   :%.d\n", m);
	   printf("printf   :%.u\n", d);
	   printf("printf   :%.x\n", d);
	   printf("printf   :%.X\n", d);
	   printf("printf   :%.p\n", &d);
	ft_printf("ft_printf:%.c\n", c);
	ft_printf("ft_printf:%.s\n", s);
	ft_printf("ft_printf:%.d\n", d);
	ft_printf("ft_printf:%.d\n", m);
	ft_printf("ft_printf:%.u\n", d);
	ft_printf("ft_printf:%.x\n", d);
	ft_printf("ft_printf:%.X\n", d);
	ft_printf("ft_printf:%.p\n", &d);

	puts("\n[%.10d]");
	   printf("printf   :%.10c\n", c);
	   printf("printf   :%.10s\n", s);
	   printf("printf   :%.10d\n", d);
	   printf("printf   :%.10d\n", m);
	   printf("printf   :%.10u\n", d);
	   printf("printf   :%.10x\n", d);
	   printf("printf   :%.10X\n", d);
	   printf("printf   :%.10p\n", &d);
	ft_printf("ft_printf:%.10c\n", c);
	ft_printf("ft_printf:%.10s\n", s);
	ft_printf("ft_printf:%.10d\n", d);
	ft_printf("ft_printf:%.10d\n", m);
	ft_printf("ft_printf:%.10u\n", d);
	ft_printf("ft_printf:%.10x\n", d);
	ft_printf("ft_printf:%.10X\n", d);
	ft_printf("ft_printf:%.10p\n", &d);

	puts("\n[%.3d]");
	   printf("printf   :%.3c\n", c);
	   printf("printf   :%.3s\n", s);
	   printf("printf   :%.3d\n", d);
	   printf("printf   :%.3d\n", m);
	   printf("printf   :%.3u\n", d);
	   printf("printf   :%.3x\n", d);
	   printf("printf   :%.3X\n", d);
	   printf("printf   :%.3p\n", &d);
	ft_printf("ft_printf:%.3c\n", c);
	ft_printf("ft_printf:%.3s\n", s);
	ft_printf("ft_printf:%.3d\n", d);
	ft_printf("ft_printf:%.3d\n", m);
	ft_printf("ft_printf:%.3u\n", d);
	ft_printf("ft_printf:%.3x\n", d);
	ft_printf("ft_printf:%.3X\n", d);
	ft_printf("ft_printf:%.3p\n", &d);

// minus
	puts("\n+++++++++++++++++++");

	puts("\n[%-.d]");
	   printf("printf   :%-.c\n", c);
	   printf("printf   :%-.s\n", s);
	   printf("printf   :%-.d\n", d);
	   printf("printf   :%-.d\n", m);
	   printf("printf   :%-.u\n", d);
	   printf("printf   :%-.x\n", d);
	   printf("printf   :%-.X\n", d);
	   printf("printf   :%-.p\n", &d);
	ft_printf("ft_printf:%-.c\n", c);
	ft_printf("ft_printf:%-.s\n", s);
	ft_printf("ft_printf:%-.d\n", d);
	ft_printf("ft_printf:%-.d\n", m);
	ft_printf("ft_printf:%-.u\n", d);
	ft_printf("ft_printf:%-.x\n", d);
	ft_printf("ft_printf:%-.X\n", d);
	ft_printf("ft_printf:%-.p\n", &d);

	puts("\n[%-.10d]");
	   printf("printf   :%-.10c\n", c);
	   printf("printf   :%-.10s\n", s);
	   printf("printf   :%-.10d\n", d);
	   printf("printf   :%-.10d\n", m);
	   printf("printf   :%-.10u\n", d);
	   printf("printf   :%-.10x\n", d);
	   printf("printf   :%-.10X\n", d);
	   printf("printf   :%-.10p\n", &d);
	ft_printf("ft_printf:%-.10c\n", c);
	ft_printf("ft_printf:%-.10s\n", s);
	ft_printf("ft_printf:%-.10d\n", d);
	ft_printf("ft_printf:%-.10d\n", m);
	ft_printf("ft_printf:%-.10u\n", d);
	ft_printf("ft_printf:%-.10x\n", d);
	ft_printf("ft_printf:%-.10X\n", d);
	ft_printf("ft_printf:%-.10p\n", &d);

	puts("\n[%-.3d]");
	   printf("printf   :%-.3c\n", c);
	   printf("printf   :%-.3s\n", s);
	   printf("printf   :%-.3d\n", d);
	   printf("printf   :%-.3d\n", m);
	   printf("printf   :%-.3u\n", d);
	   printf("printf   :%-.3x\n", d);
	   printf("printf   :%-.3X\n", d);
	   printf("printf   :%-.3p\n", &d);
	ft_printf("ft_printf:%-.3c\n", c);
	ft_printf("ft_printf:%-.3s\n", s);
	ft_printf("ft_printf:%-.3d\n", d);
	ft_printf("ft_printf:%-.3d\n", m);
	ft_printf("ft_printf:%-.3u\n", d);
	ft_printf("ft_printf:%-.3x\n", d);
	ft_printf("ft_printf:%-.3X\n", d);
	ft_printf("ft_printf:%-.3p\n", &d);

// zero
	puts("\n+++++++++++++++++++");

	puts("\n[%.0d]");
	   printf("printf   :%.0c\n", c);
	   printf("printf   :%.0s\n", s);
	   printf("printf   :%.0d\n", d);
	   printf("printf   :%.0d\n", m);
	   printf("printf   :%.0u\n", d);
	   printf("printf   :%.0x\n", d);
	   printf("printf   :%.0X\n", d);
	   printf("printf   :%.0p\n", &d);
	ft_printf("ft_printf:%.0c\n", c);
	ft_printf("ft_printf:%.0s\n", s);
	ft_printf("ft_printf:%.0d\n", d);
	ft_printf("ft_printf:%.0d\n", m);
	ft_printf("ft_printf:%.0u\n", d);
	ft_printf("ft_printf:%.0x\n", d);
	ft_printf("ft_printf:%.0X\n", d);
	ft_printf("ft_printf:%.0p\n", &d);

	puts("\n[%.010d]");
	   printf("printf   :%.010c\n", c);
	   printf("printf   :%.010s\n", s);
	   printf("printf   :%.010d\n", d);
	   printf("printf   :%.010d\n", m);
	   printf("printf   :%.010u\n", d);
	   printf("printf   :%.010x\n", d);
	   printf("printf   :%.010X\n", d);
	   printf("printf   :%.010p\n", &d);
	ft_printf("ft_printf:%.010c\n", c);
	ft_printf("ft_printf:%.010s\n", s);
	ft_printf("ft_printf:%.010d\n", d);
	ft_printf("ft_printf:%.010d\n", m);
	ft_printf("ft_printf:%.010u\n", d);
	ft_printf("ft_printf:%.010x\n", d);
	ft_printf("ft_printf:%.010X\n", d);
	ft_printf("ft_printf:%.010p\n", &d);

	puts("\n[%.03d]");
	   printf("printf   :%.03c\n", c);
	   printf("printf   :%.03s\n", s);
	   printf("printf   :%.03d\n", d);
	   printf("printf   :%.03d\n", m);
	   printf("printf   :%.03u\n", d);
	   printf("printf   :%.03x\n", d);
	   printf("printf   :%.03X\n", d);
	   printf("printf   :%.03p\n", &d);
	ft_printf("ft_printf:%.03c\n", c);
	ft_printf("ft_printf:%.03s\n", s);
	ft_printf("ft_printf:%.03d\n", d);
	ft_printf("ft_printf:%.03d\n", m);
	ft_printf("ft_printf:%.03u\n", d);
	ft_printf("ft_printf:%.03x\n", d);
	ft_printf("ft_printf:%.03X\n", d);
	ft_printf("ft_printf:%.03p\n", &d);

// space || plus
	puts("\n+++++++++++++++++++");

	// with none
	puts("\n[%+.d]");
	   printf("printf   :%+.d\n", d);
	   printf("printf   :%+.d\n", m);
	ft_printf("ft_printf:%+.d\n", d);
	ft_printf("ft_printf:%+.d\n", m);

	puts("\n[%+.10d]");
	   printf("printf   :%+.10d\n", d);
	   printf("printf   :%+.10d\n", m);
	ft_printf("ft_printf:%+.10d\n", d);
	ft_printf("ft_printf:%+.10d\n", m);

	puts("\n[%+.3d]");
	   printf("printf   :%+.3d\n", d);
	   printf("printf   :%+.3d\n", m);
	ft_printf("ft_printf:%+.3d\n", d);
	ft_printf("ft_printf:%+.3d\n", m);

	// with minus
	puts("\n[%-+.d]");
	   printf("printf   :%-+.d\n", d);
	   printf("printf   :%-+.d\n", m);
	ft_printf("ft_printf:%-+.d\n", d);
	ft_printf("ft_printf:%-+.d\n", m);

	puts("\n[%-+.10d]");
	   printf("printf   :%-+.10d\n", d);
	   printf("printf   :%-+.10d\n", m);
	ft_printf("ft_printf:%-+.10d\n", d);
	ft_printf("ft_printf:%-+.10d\n", m);

	puts("\n[%+-.3d]");
	   printf("printf   :%+-.3d\n", d);
	   printf("printf   :%+-.3d\n", m);
	ft_printf("ft_printf:%+-.3d\n", d);
	ft_printf("ft_printf:%+-.3d\n", m);

	// with zero
	puts("\n[%+.0d]");
	   printf("printf   :%+.0d\n", d);
	   printf("printf   :%+.0d\n", m);
	ft_printf("ft_printf:%+.0d\n", d);
	ft_printf("ft_printf:%+.0d\n", m);

	puts("\n[%+.010d]");
	   printf("printf   :%+.010d\n", d);
	   printf("printf   :%+.010d\n", m);
	ft_printf("ft_printf:%+.010d\n", d);
	ft_printf("ft_printf:%+.010d\n", m);

	puts("\n[%+.03d]");
	   printf("printf   :%+.03d\n", d);
	   printf("printf   :%+.03d\n", m);
	ft_printf("ft_printf:%+.03d\n", d);
	ft_printf("ft_printf:%+.03d\n", m);

// sherp
	puts("\n+++++++++++++++++++");

	// with none
	puts("\n[%#.x]");
	   printf("printf   :%#.x\n", d);
	   printf("printf   :%#.X\n", d);
	ft_printf("ft_printf:%#.x\n", d);
	ft_printf("ft_printf:%#.X\n", d);

	puts("\n[%#.10x]");
	   printf("printf   :%#.10x\n", d);
	   printf("printf   :%#.10X\n", d);
	ft_printf("ft_printf:%#.10x\n", d);
	ft_printf("ft_printf:%#.10X\n", d);

	puts("\n[%#.3x]");
	   printf("printf   :%#.3x\n", d);
	   printf("printf   :%#.3X\n", d);
	ft_printf("ft_printf:%#.3x\n", d);
	ft_printf("ft_printf:%#.3X\n", d);

	// with minus
	puts("\n[%#-.x]");
	   printf("printf   :%#-.x\n", d);
	   printf("printf   :%#-.X\n", d);
	ft_printf("ft_printf:%#-.x\n", d);
	ft_printf("ft_printf:%#-.X\n", d);

	puts("\n[%#-.10x]");
	   printf("printf   :%#-.10x\n", d);
	   printf("printf   :%#-.10X\n", d);
	ft_printf("ft_printf:%#-.10x\n", d);
	ft_printf("ft_printf:%#-.10X\n", d);

	puts("\n[%-#.3x]");
	   printf("printf   :%-#.3x\n", d);
	   printf("printf   :%-#.3X\n", d);
	ft_printf("ft_printf:%-#.3x\n", d);
	ft_printf("ft_printf:%-#.3X\n", d);

	// with zero
	puts("\n[%#.0x]");
	   printf("printf   :%#.0x\n", d);
	   printf("printf   :%#.0X\n", d);
	ft_printf("ft_printf:%#.0x\n", d);
	ft_printf("ft_printf:%#.0X\n", d);

	puts("\n[%#.010x]");
	   printf("printf   :%#.010x\n", d);
	   printf("printf   :%#.010X\n", d);
	ft_printf("ft_printf:%#.010x\n", d);
	ft_printf("ft_printf:%#.010X\n", d);

	puts("\n[%#.03x]");
	   printf("printf   :%#.03x\n", d);
	   printf("printf   :%#.03X\n", d);
	ft_printf("ft_printf:%#.03x\n", d);
	ft_printf("ft_printf:%#.03X\n", d);
}