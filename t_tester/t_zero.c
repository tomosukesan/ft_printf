#include <stdio.h>
#include "../ft_printf.h"

int main (void)
{
	char	c = 'a';
	char	*s = "42tokyo";
	int		d = 42;
	int		m = -42;

/*
*/

	puts("\n[%0d]");
	//   printf("printf   :%0c\n", c);		// undefined
	//   printf("printf   :%0s\n", s);		// undefined
	   printf("printf   :%0d\n", d);
	   printf("printf   :%0d\n", m);
	   printf("printf   :%0u\n", d);
	   printf("printf   :%0x\n", d);
	   printf("printf   :%0X\n", d);
	//   printf("printf   :%0p\n", &d);	// undefined
	//ft_printf("ft_printf:%0c\n", c);
	//ft_printf("ft_printf:%0s\n", s);
	ft_printf("ft_printf:%0d\n", d);
	ft_printf("ft_printf:%0d\n", m);
	ft_printf("ft_printf:%0u\n", d);
	ft_printf("ft_printf:%0x\n", d);
	ft_printf("ft_printf:%0X\n", d);
	//ft_printf("ft_printf:%0p\n", &d);

	puts("\n[%010d]");
	//   printf("printf   :%010c\n", c);
	//   printf("printf   :%010s\n", s);
	   printf("printf   :%010d\n", d);
	   printf("printf   :%010d\n", m);
	   printf("printf   :%010u\n", d);
	   printf("printf   :%010x\n", d);
	   printf("printf   :%010X\n", d);
	//   printf("printf   :%010p\n", &d);
	//ft_printf("ft_printf:%010c\n", c);
	//ft_printf("ft_printf:%010s\n", s);
	ft_printf("ft_printf:%010d\n", d);
	ft_printf("ft_printf:%010d\n", m);
	ft_printf("ft_printf:%010u\n", d);
	ft_printf("ft_printf:%010x\n", d);
	ft_printf("ft_printf:%010X\n", d);
	//ft_printf("ft_printf:%010p\n", &d);

	puts("\n[%010.3d]");
	//   printf("printf   :%010.3c\n", c);	// undefined
	//   printf("printf   :%010.3s\n", s);
	   printf("printf   :%010.3d\n", d);
	   printf("printf   :%010.3d\n", m);
	   printf("printf   :%010.3u\n", d);
	   printf("printf   :%010.3x\n", d);
	   printf("printf   :%010.3X\n", d);
	//   printf("printf   :%010.3p\n", &d);	// undefined
	//ft_printf("ft_printf:%010.3c\n", c);
	//ft_printf("ft_printf:%010.3s\n", s);
	ft_printf("ft_printf:%010.3d\n", d);
	ft_printf("ft_printf:%010.3d\n", m);
	ft_printf("ft_printf:%010.3u\n", d);
	ft_printf("ft_printf:%010.3x\n", d);
	ft_printf("ft_printf:%010.3X\n", d);
	//ft_printf("ft_printf:%010.3p\n", &d);

	puts("\n[%010.8d]");
	//   printf("printf   :%010.8c\n", c);	// undefined
	//   printf("printf   :%010.8s\n", s);
	   printf("printf   :%010.8d\n", d);
	   printf("printf   :%010.8d\n", m);
	   printf("printf   :%010.8u\n", d);
	   printf("printf   :%010.8x\n", d);
	   printf("printf   :%010.8X\n", d);
	//   printf("printf   :%010.8p\n", &d);	// undefined
	//ft_printf("ft_printf:%010.8c\n", c);
	//ft_printf("ft_printf:%010.8s\n", s);
	ft_printf("ft_printf:%010.8d\n", d);
	ft_printf("ft_printf:%010.8d\n", m);
	ft_printf("ft_printf:%010.8u\n", d);
	ft_printf("ft_printf:%010.8x\n", d);
	ft_printf("ft_printf:%010.8X\n", d);
	//ft_printf("ft_printf:%010.8p\n", &d);

	puts("\n[%03.8d]");
	//   printf("printf   :%03.08c\n", c);		// undefined
	//   printf("printf   :%03.08s\n", s);
	   printf("printf   :%03.08d\n", d);
	   printf("printf   :%03.08d\n", m);
	   printf("printf   :%03.08u\n", d);
	   printf("printf   :%03.08x\n", d);
	   printf("printf   :%03.08X\n", d);
	//   printf("printf   :%03.08p\n", &d);	// undefined
	//ft_printf("ft_printf:%03.08c\n", c);
	//ft_printf("ft_printf:%03.08s\n", s);
	ft_printf("ft_printf:%03.08d\n", d);
	ft_printf("ft_printf:%03.08d\n", m);
	ft_printf("ft_printf:%03.08u\n", d);
	ft_printf("ft_printf:%03.08x\n", d);
	ft_printf("ft_printf:%03.08X\n", d);
	//ft_printf("ft_printf:%03.08p\n", &d);

	puts("\n[%03.2d]");
	//   printf("printf   :%03.2c\n", c);		// undefined
	//   printf("printf   :%03.2s\n", s);
	   printf("printf   :%03.2d\n", d);
	   printf("printf   :%03.2d\n", m);
	   printf("printf   :%03.2u\n", d);
	   printf("printf   :%03.2x\n", d);
	   printf("printf   :%03.2X\n", d);
	//   printf("printf   :%03.2p\n", &d);	// undefined
	//ft_printf("ft_printf:%03.2c\n", c);
	//ft_printf("ft_printf:%03.2s\n", s);
	ft_printf("ft_printf:%03.2d\n", d);
	ft_printf("ft_printf:%03.2d\n", m);
	ft_printf("ft_printf:%03.2u\n", d);
	ft_printf("ft_printf:%03.2x\n", d);
	ft_printf("ft_printf:%03.2X\n", d);
	//ft_printf("ft_printf:%03.2p\n", &d);

	puts("\n[%010.1d]");
	//   printf("printf   :%03.2c\n", c);		// undefined
	//   printf("printf   :%03.2s\n", s);
	   printf("printf   :%010.1d\n", d);
	   printf("printf   :%010.1d\n", m);
	   printf("printf   :%010.1u\n", d);
	   printf("printf   :%010.1x\n", d);
	   printf("printf   :%010.1X\n", d);
	//   printf("printf   :%03.2p\n", &d);	// undefined
	//ft_printf("ft_printf:%03.2c\n", c);
	//ft_printf("ft_printf:%03.2s\n", s);
	ft_printf("ft_printf:%010.1d\n", d);
	ft_printf("ft_printf:%010.1d\n", m);
	ft_printf("ft_printf:%010.1u\n", d);
	ft_printf("ft_printf:%010.1x\n", d);
	ft_printf("ft_printf:%010.1X\n", d);
	//ft_printf("ft_printf:%03.2p\n", &d);

	puts("\n+++++zero && minus++++++++++");

	puts("\n[%0-10.3d]");
	//   printf("printf   :%010.3c\n", c);	// undefined
	//   printf("printf   :%010.3s\n", s);
	   printf("printf   :%0-10.3d\n", d);
	   printf("printf   :%0-10.3d\n", m);
	   printf("printf   :%0-10.3u\n", d);
	   printf("printf   :%0-10.3x\n", d);
	   printf("printf   :%0-10.3X\n", d);
	//   printf("printf   :%010.3p\n", &d);	// undefined
	//ft_printf("ft_printf:%010.3c\n", c);
	//ft_printf("ft_printf:%010.3s\n", s);
	ft_printf("ft_printf:%0-10.3d\n", d);
	ft_printf("ft_printf:%0-10.3d\n", m);
	ft_printf("ft_printf:%0-10.3u\n", d);
	ft_printf("ft_printf:%0-10.3x\n", d);
	ft_printf("ft_printf:%0-10.3X\n", d);
	//ft_printf("ft_printf:%010.3p\n", &d);

	puts("\n[%-010.8d]");
	//   printf("printf   :%010.8c\n", c);	// undefined
	//   printf("printf   :%010.8s\n", s);
	   printf("printf   :%-010.8d\n", d);
	   printf("printf   :%-010.8d\n", m);
	   printf("printf   :%-010.8u\n", d);
	   printf("printf   :%-010.8x\n", d);
	   printf("printf   :%-010.8X\n", d);
	//   printf("printf   :%010.8p\n", &d);	// undefined
	//ft_printf("ft_printf:%010.8c\n", c);
	//ft_printf("ft_printf:%010.8s\n", s);
	ft_printf("ft_printf:%-010.8d\n", d);
	ft_printf("ft_printf:%-010.8d\n", m);
	ft_printf("ft_printf:%-010.8u\n", d);
	ft_printf("ft_printf:%-010.8x\n", d);
	ft_printf("ft_printf:%-010.8X\n", d);
	//ft_printf("ft_printf:%010.8p\n", &d);

	puts("\n[%0-3.8d]");
	//   printf("printf   :%03.08c\n", c);		// undefined
	//   printf("printf   :%03.08s\n", s);
	   printf("printf   :%0-3.08d\n", d);
	   printf("printf   :%0-3.08d\n", m);
	   printf("printf   :%0-3.08u\n", d);
	   printf("printf   :%0-3.08x\n", d);
	   printf("printf   :%0-3.08X\n", d);
	//   printf("printf   :%03.08p\n", &d);	// undefined
	//ft_printf("ft_printf:%03.08c\n", c);
	//ft_printf("ft_printf:%03.08s\n", s);
	ft_printf("ft_printf:%0-3.08d\n", d);
	ft_printf("ft_printf:%0-3.08d\n", m);
	ft_printf("ft_printf:%0-3.08u\n", d);
	ft_printf("ft_printf:%0-3.08x\n", d);
	ft_printf("ft_printf:%0-3.08X\n", d);
	//ft_printf("ft_printf:%03.08p\n", &d);


	return (0);
}