#include "ft_printf.h"
#include <stdio.h>

int main()
{
	//int n = ft_printf("hello\n");
	//printf("%d\n", n);
	int a = ft_printf("hello%");
	int b = ft_printf("hello%");

	printf("\n%d %d", a, b);
	//ft_printf("a%cb", 'x');
	//ft_printf("%%");
	//ft_printf("%c%c", 'A', 'B');
	//ft_printf("%%%c", 'x');
}
