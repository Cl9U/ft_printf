#include "ft_printf.h"
#include <stdio.h>

//int main()
//{
//	//int n = ft_printf("hello\n");
//	//printf("%d\n", n);
//	//int a = ft_printf("%u", 10000000);
//	//printf("\n");
//	//int b = printf("%u", 10000000);

//	//printf("\n%d\n%d", a, b);

//	int	x;
//	int a;
//	int b;
//	int c;
//	int d;
//	a = printf("%p\n", (void *)&x);
//	printf("%d\n", a);
//	b = printf("%p\n", NULL);
//	printf("%d\n", b);
//	printf("------------------\n");
//	c = ft_printf("%p\n", (void *)&x);
//	printf("%d\n", c);
//	d = ft_printf("%p\n", NULL);
//	printf("%d\n", d);

//	//ft_printf("a%cb", 'x');
//	//ft_printf("%%");
//	//ft_printf("%c%c", 'A', 'B');
//	//ft_printf("%%%c", 'x');

//	//ft_printf("%s", "hello");
//}

#include <stdio.h>
#include <limits.h>
#include <unistd.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	int				ret_ft;
	int				ret_original;
	char			*str;
	char			c;

	str = "Hello 1337";
	c = 'A';

	printf("========== CHAR %c ==========\n", c);
	ret_ft = ft_printf("ft_printf:    [%c]\n", c);
	ret_original = printf("printf:       [%c]\n", c);
	printf("Return: ft=%d | original=%d\n\n", ret_ft, ret_original);

	printf("========== STRING ==========\n");
	ret_ft = ft_printf("ft_printf:    [%s]\n", str);
	ret_original = printf("printf:       [%s]\n", str);
	printf("Return: ft=%d | original=%d\n\n", ret_ft, ret_original);

	printf("========== NULL STRING ==========\n");
	ret_ft = ft_printf("ft_printf:    [%s]\n", (char *)NULL);
	ret_original = printf("printf:       [%s]\n", (char *)NULL);
	printf("Return: ft=%d | original=%d\n\n", ret_ft, ret_original);

	printf("========== POINTER ==========\n");
	ret_ft = ft_printf("ft_printf:    [%p]\n", (void *)str);
	ret_original = printf("printf:       [%p]\n", (void *)str);
	printf("Return: ft=%d | original=%d\n\n", ret_ft, ret_original);

	printf("========== DECIMAL / INTEGER ==========\n");
	ret_ft = ft_printf("ft_printf:    [%d] [%i] [%d]\n",
			42, -42, 0);
	ret_original = printf("printf:       [%d] [%i] [%d]\n",
			42, -42, 0);
	printf("Return: ft=%d | original=%d\n\n", ret_ft, ret_original);

	printf("========== UNSIGNED ==========\n");
	ret_ft = ft_printf("ft_printf:    [%u] [%u] [%u]\n",
			0u, 42u, UINT_MAX);
	ret_original = printf("printf:       [%u] [%u] [%u]\n",
			0u, 42u, UINT_MAX);
	printf("Return: ft=%d | original=%d\n\n", ret_ft, ret_original);

	printf("========== HEXADECIMAL ==========\n");
	ret_ft = ft_printf("ft_printf:    [%x] [%X] [%x]\n",
			42u, 42u, 0u);
	ret_original = printf("printf:       [%x] [%X] [%x]\n",
			42u, 42u, 0u);
	printf("Return: ft=%d | original=%d\n\n", ret_ft, ret_original);

	printf("========== PERCENT SIGN ==========\n");
	ret_ft = ft_printf("ft_printf:    [%%] [%%%%]\n");
	ret_original = printf("printf:       [%%] [%%%%]\n");
	printf("Return: ft=%d | original=%d\n\n", ret_ft, ret_original);

	printf("========== MIXED ==========\n");
	ret_ft = ft_printf("ft_printf:    %c %s %p %d %i %u %x %X %%\n",
			'A', "1337", (void *)str, -42, 42, 42u, 42u, 42u);
	ret_original = printf("printf:       %c %s %p %d %i %u %x %X %%\n",
			'A', "1337", (void *)str, -42, 42, 42u, 42u, 42u);
	printf("Return: ft=%d | original=%d\n\n", ret_ft, ret_original);

	printf("========== EMPTY STRING ==========\n");
	ret_ft = ft_printf("");
	ret_original = printf("");
	printf("Return: ft=%d | original=%d\n\n", ret_ft, ret_original);

	printf("========== NO CONVERSION ==========\n");
	ret_ft = ft_printf("Hello, 1337!\n");
	ret_original = printf("Hello, 1337!\n");
	printf("Return: ft=%d | original=%d\n\n", ret_ft, ret_original);

	printf("========== INT LIMITS ==========\n");
	ret_ft = ft_printf("ft_printf:    [%d] [%d]\n", INT_MIN, INT_MAX);
	ret_original = printf("printf:       [%d] [%d]\n", INT_MIN, INT_MAX);
	printf("Return: ft=%d | original=%d\n\n", ret_ft, ret_original);

	return (0);
}
