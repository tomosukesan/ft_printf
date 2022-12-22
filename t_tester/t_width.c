#include <stdio.h>
#include "../ft_printf.h"

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

	puts("\n[%10.d]");
	   printf("printf   :%10.c\n", c);
	   printf("printf   :%10.s\n", s);
	   printf("printf   :%10.d\n", d);
	   printf("printf   :%10.d\n", m);
	   printf("printf   :%10.u\n", d);
	   printf("printf   :%10.x\n", d);
	   printf("printf   :%10.X\n", d);
	   printf("printf   :%10.p\n", &d);
	ft_printf("ft_printf:%10.c\n", c);
	ft_printf("ft_printf:%10.s\n", s);
	ft_printf("ft_printf:%10.d\n", d);
	ft_printf("ft_printf:%10.d\n", m);
	ft_printf("ft_printf:%10.u\n", d);
	ft_printf("ft_printf:%10.x\n", d);
	ft_printf("ft_printf:%10.X\n", d);
	ft_printf("ft_printf:%10.p\n", &d);

	puts("\n[%3.d]");
	   printf("printf   :%3.c\n", c);
	   printf("printf   :%3.s\n", s);
	   printf("printf   :%3.d\n", d);
	   printf("printf   :%3.d\n", m);
	   printf("printf   :%3.u\n", d);
	   printf("printf   :%3.x\n", d);
	   printf("printf   :%3.X\n", d);
	   printf("printf   :%3.p\n", &d);
	ft_printf("ft_printf:%3.c\n", c);
	ft_printf("ft_printf:%3.s\n", s);
	ft_printf("ft_printf:%3.d\n", d);
	ft_printf("ft_printf:%3.d\n", m);
	ft_printf("ft_printf:%3.u\n", d);
	ft_printf("ft_printf:%3.x\n", d);
	ft_printf("ft_printf:%3.X\n", d);
	ft_printf("ft_printf:%3.p\n", &d);

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

	puts("\n[%-10.d]");
	   printf("printf   :%-10.c\n", c);
	   printf("printf   :%-10.s\n", s);
	   printf("printf   :%-10.d\n", d);
	   printf("printf   :%-10.d\n", m);
	   printf("printf   :%-10.u\n", d);
	   printf("printf   :%-10.x\n", d);
	   printf("printf   :%-10.X\n", d);
	   printf("printf   :%-10.p\n", &d);
	ft_printf("ft_printf:%-10.c\n", c);
	ft_printf("ft_printf:%-10.s\n", s);
	ft_printf("ft_printf:%-10.d\n", d);
	ft_printf("ft_printf:%-10.d\n", m);
	ft_printf("ft_printf:%-10.u\n", d);
	ft_printf("ft_printf:%-10.x\n", d);
	ft_printf("ft_printf:%-10.X\n", d);
	ft_printf("ft_printf:%-10.p\n", &d);

	puts("\n[%-3.d]");
	   printf("printf   :%-3.c\n", c);
	   printf("printf   :%-3.s\n", s);
	   printf("printf   :%-3.d\n", d);
	   printf("printf   :%-3.d\n", m);
	   printf("printf   :%-3.u\n", d);
	   printf("printf   :%-3.x\n", d);
	   printf("printf   :%-3.X\n", d);
	   printf("printf   :%-3.p\n", &d);
	ft_printf("ft_printf:%-3.c\n", c);
	ft_printf("ft_printf:%-3.s\n", s);
	ft_printf("ft_printf:%-3.d\n", d);
	ft_printf("ft_printf:%-3.d\n", m);
	ft_printf("ft_printf:%-3.u\n", d);
	ft_printf("ft_printf:%-3.x\n", d);
	ft_printf("ft_printf:%-3.X\n", d);
	ft_printf("ft_printf:%-3.p\n", &d);

// zero
	puts("\n+++++++++++++++++++");

	puts("\n[%0.d]");
	//   printf("printf   :%0.c\n", c);
	//   printf("printf   :%0.s\n", s);
	   printf("printf   :%0.d\n", d);
	   printf("printf   :%0.d\n", m);
	   printf("printf   :%0.u\n", d);
	   printf("printf   :%0.x\n", d);
	   printf("printf   :%0.X\n", d);
	//   printf("printf   :%0.p\n", &d);
	//ft_printf("ft_printf:%0.c\n", c);
	//ft_printf("ft_printf:%0.s\n", s);
	ft_printf("ft_printf:%0.d\n", d);
	ft_printf("ft_printf:%0.d\n", m);
	ft_printf("ft_printf:%0.u\n", d);
	ft_printf("ft_printf:%0.x\n", d);
	ft_printf("ft_printf:%0.X\n", d);
	//ft_printf("ft_printf:%0.p\n", &d);

	puts("\n[%010.d]");
	//   printf("printf   :%010.c\n", c);
	//   printf("printf   :%010.s\n", s);
	   printf("printf   :%010.d\n", d);
	   printf("printf   :%010.d\n", m);
	   printf("printf   :%010.u\n", d);
	   printf("printf   :%010.x\n", d);
	   printf("printf   :%010.X\n", d);
	//   printf("printf   :%010.p\n", &d);
	//ft_printf("ft_printf:%010.c\n", c);
	//ft_printf("ft_printf:%010.s\n", s);
	ft_printf("ft_printf:%010.d\n", d);
	ft_printf("ft_printf:%010.d\n", m);
	ft_printf("ft_printf:%010.u\n", d);
	ft_printf("ft_printf:%010.x\n", d);
	ft_printf("ft_printf:%010.X\n", d);
	//ft_printf("ft_printf:%010.p\n", &d);

	puts("\n[%03.d]");
	//   printf("printf   :%03.c\n", c);
	//   printf("printf   :%03.s\n", s);
	   printf("printf   :%03.d\n", d);
	   printf("printf   :%03.d\n", m);
	   printf("printf   :%03.u\n", d);
	   printf("printf   :%03.x\n", d);
	   printf("printf   :%03.X\n", d);
	//   printf("printf   :%03.p\n", &d);
	//ft_printf("ft_printf:%03.c\n", c);
	//ft_printf("ft_printf:%03.s\n", s);
	ft_printf("ft_printf:%03.d\n", d);
	ft_printf("ft_printf:%03.d\n", m);
	ft_printf("ft_printf:%03.u\n", d);
	ft_printf("ft_printf:%03.x\n", d);
	ft_printf("ft_printf:%03.X\n", d);
	//ft_printf("ft_printf:%03.p\n", &d);

// space || plus
	puts("\n+++++++++++++++++++");

	// with none
	puts("\n[%+.d]");
	   printf("printf   :%+.d\n", d);
	   printf("printf   :%+.d\n", m);
	ft_printf("ft_printf:%+.d\n", d);
	ft_printf("ft_printf:%+.d\n", m);

	puts("\n[%+10.d]");
	   printf("printf   :%+10.d\n", d);
	   printf("printf   :%+10.d\n", m);
	ft_printf("ft_printf:%+10.d\n", d);
	ft_printf("ft_printf:%+10.d\n", m);

	puts("\n[%+3.d]");
	   printf("printf   :%+3.d\n", d);
	   printf("printf   :%+3.d\n", m);
	ft_printf("ft_printf:%+3.d\n", d);
	ft_printf("ft_printf:%+3.d\n", m);

	// with minus
	puts("\n[%-+.d]");
	   printf("printf   :%-+.d\n", d);
	   printf("printf   :%-+.d\n", m);
	ft_printf("ft_printf:%-+.d\n", d);
	ft_printf("ft_printf:%-+.d\n", m);

	puts("\n[%-+10.d]");
	   printf("printf   :%-+10.d\n", d);
	   printf("printf   :%-+10.d\n", m);
	ft_printf("ft_printf:%-+10.d\n", d);
	ft_printf("ft_printf:%-+10.d\n", m);

	puts("\n[%+-3.d]");
	   printf("printf   :%+-3.d\n", d);
	   printf("printf   :%+-3.d\n", m);
	ft_printf("ft_printf:%+-3.d\n", d);
	ft_printf("ft_printf:%+-3.d\n", m);

	// with zero
	puts("\n[%+0.d]");
	   printf("printf   :%+0.d\n", d);
	   printf("printf   :%+0.d\n", m);
	ft_printf("ft_printf:%+0.d\n", d);
	ft_printf("ft_printf:%+0.d\n", m);

	puts("\n[%+010.d]");
	   printf("printf   :%+010.d\n", d);
	   printf("printf   :%+010.d\n", m);
	ft_printf("ft_printf:%+010.d\n", d);
	ft_printf("ft_printf:%+010.d\n", m);

	puts("\n[%+03.d]");
	   printf("printf   :%+03.d\n", d);
	   printf("printf   :%+03.d\n", m);
	ft_printf("ft_printf:%+03.d\n", d);
	ft_printf("ft_printf:%+03.d\n", m);

// sherp
	puts("\n+++++++++++++++++++");

	// with none
	puts("\n[%#.x]");
	   printf("printf   :%#.x\n", d);
	   printf("printf   :%#.X\n", d);
	ft_printf("ft_printf:%#.x\n", d);
	ft_printf("ft_printf:%#.X\n", d);

	puts("\n[%#10.x]");
	   printf("printf   :%#10.x\n", d);
	   printf("printf   :%#10.X\n", d);
	ft_printf("ft_printf:%#10.x\n", d);
	ft_printf("ft_printf:%#10.X\n", d);

	puts("\n[%#3.x]");
	   printf("printf   :%#3.x\n", d);
	   printf("printf   :%#3.X\n", d);
	ft_printf("ft_printf:%#3.x\n", d);
	ft_printf("ft_printf:%#3.X\n", d);

	// with minus
	puts("\n[%#-.x]");
	   printf("printf   :%#-.x\n", d);
	   printf("printf   :%#-.X\n", d);
	ft_printf("ft_printf:%#-.x\n", d);
	ft_printf("ft_printf:%#-.X\n", d);

	puts("\n[%#-10.x]");
	   printf("printf   :%#-10.x\n", d);
	   printf("printf   :%#-10.X\n", d);
	ft_printf("ft_printf:%#-10.x\n", d);
	ft_printf("ft_printf:%#-10.X\n", d);

	puts("\n[%-#3.x]");
	   printf("printf   :%-#3.x\n", d);
	   printf("printf   :%-#3.X\n", d);
	ft_printf("ft_printf:%-#3.x\n", d);
	ft_printf("ft_printf:%-#3.X\n", d);

	// with zero
	puts("\n[%#0.x]");
	   printf("printf   :%#0.x\n", d);
	   printf("printf   :%#0.X\n", d);
	ft_printf("ft_printf:%#0.x\n", d);
	ft_printf("ft_printf:%#0.X\n", d);

	puts("\n[%#010.x]");
	   printf("printf   :%#010.x\n", d);
	   printf("printf   :%#010.X\n", d);
	ft_printf("ft_printf:%#010.x\n", d);
	ft_printf("ft_printf:%#010.X\n", d);

	puts("\n[%#03.x]");
	   printf("printf   :%#03.x\n", d);
	   printf("printf   :%#03.X\n", d);
	ft_printf("ft_printf:%#03.x\n", d);
	ft_printf("ft_printf:%#03.X\n", d);
}