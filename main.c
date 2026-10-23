#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	a;
	int	b;

	printf("ft : [");
	fflush(stdout);
	a = ft_printf("%k");
	printf("] -> %d\n", a);
	printf("std: [");
	fflush(stdout);
	b = printf("%k");
	printf("] -> %d\n", b);
	return (0);
}