#include "includes/ft_printf.h"

#include <stdio.h>

int main()
{
	printf("test 1 ft_printf : \n");
	int i;
	
	i = ft_printf("%c|", '0');
	printf("%i\n", i);
	i = ft_printf(" %c |", '0');
	printf("%i\n", i);
	i = ft_printf(" %c|", '0' - 256);
	printf("%i\n", i);
	i = ft_printf("%c |", '0' + 256);
	printf("%i\n", i);
	i = ft_printf(" %c %c %c |", '0', 0, '1');
	printf("%i\n", i);
	i = ft_printf(" %c %c %c |", ' ', ' ', ' ');
	printf("%i\n", i);
	i = ft_printf(" %c %c %c |", '1', '2', '3');
	printf("%i\n", i);
	i = ft_printf(" %c %c %c |", '2', '1', 0);
	printf("%i\n", i);
	i = ft_printf(" %c %c %c |", 0, '1', '2');
	printf("%i\n", i);
	
	printf("test 1 printf : \n");
		i = printf("%c|", '0');
	printf("%i\n", i);
	i = printf(" %c |", '0');
	printf("%i\n", i);
	i = printf(" %c|", '0' - 256);
	printf("%i\n", i);
	i = printf("%c |", '0' + 256);
	printf("%i\n", i);
	i = printf(" %c %c %c |", '0', 0, '1');
	printf("%i\n", i);
	i = printf(" %c %c %c |", ' ', ' ', ' ');
	printf("%i\n", i);
	i = printf(" %c %c %c |", '1', '2', '3');
	printf("%i\n", i);
	i = printf(" %c %c %c |", '2', '1', 0);
	printf("%i\n", i);
	i = printf(" %c %c %c |", 0, '1', '2');
	printf("%i\n", i);

	char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
	printf("test s ft_printf : \n");

	i = ft_printf("%s|", "");
	printf("%i\n", i);
	i = ft_printf(" %s|", "");
	printf("%i\n", i);
	i = ft_printf("%s |", "");
	printf("%i\n", i);
	i = ft_printf(" %s |", "");
	printf("%i\n", i);
	i = ft_printf(" %s %s |", "", "-");
	printf("%i\n", i);
	i = ft_printf(" %s %s |", "-", "");
	printf("%i\n", i);
	i = ft_printf(" %s %s %s %s %s|", " - ", "", "4", "", s2);
	printf("%i\n", i);
	i = ft_printf(" %s %s %s %s %s |", " - ", "", "4", "", "2 ");
	printf("%i\n", i);

	printf("test s printf : \n");
	i = printf("%s|", "");
	printf("%i\n", i);
	i = printf(" %s|", "");
	printf("%i\n", i);
	i = printf("%s |", "");
	printf("%i\n", i);
	i = printf(" %s |", "");
	printf("%i\n", i);
	i = printf(" %s %s |", "", "-");
	printf("%i\n", i);
	i = printf(" %s %s |", "-", "");
	printf("%i\n", i);
	i = printf(" %s %s %s %s %s|", " - ", "", "4", "", s2);
	printf("%i\n", i);
	i = printf(" %s %s %s %s %s |", " - ", "", "4", "", "2 ");
	printf("%i\n", i);

	printf("test p ft_printf : \n");
	
	i = ft_printf(" %p |", -1);
	printf("%i\n", i);
	i = ft_printf(" %p |", 1);
	printf("%i\n", i);
	i = ft_printf(" %p |", 15);
	printf("%i\n", i);
	i = ft_printf(" %p |", 16);
	printf("%i\n", i);
	i = ft_printf(" %p |", 17);
	printf("%i\n", i);
	i = ft_printf(" %p %p |", -__LONG_MAX__ -1L, __LONG_MAX__);
	printf("%i\n", i);
	i = ft_printf(" %p %p |", -__INT_MAX__ -1, __INT_MAX__);
	printf("%i\n", i);
	i = ft_printf(" %p %p |", __LONG_MAX__ *2UL+1UL, -__LONG_MAX__ *2UL-1UL);
	printf("%i\n", i);
	i = ft_printf(" %p %p |", 0, 0);
	printf("%i\n", i);
	
	printf("test p printf : \n");
	i = printf(" %p |", -1);
	printf("%i\n", i);
	i = printf(" %p |", 1);
	printf("%i\n", i);
	i = printf(" %p |", 15);
	printf("%i\n", i);
	i = printf(" %p |", 16);
	printf("%i\n", i);
	i = printf(" %p |", 17);
	printf("%i\n", i);
	i = printf(" %p %p |", -__LONG_MAX__ -1L, __LONG_MAX__);
	printf("%i\n", i);
	i = printf(" %p %p |", -__INT_MAX__ -1, __INT_MAX__);
	printf("%i\n", i);
	i = printf(" %p %p |", __LONG_MAX__ *2UL+1UL, -__LONG_MAX__ *2UL-1UL);
	printf("%i\n", i);
	i = printf(" %p %p |", 0, 0);
	printf("%i\n", i);
	
		int test = 42;
	int i;
	printf("test p ft_printf : \n");
	i = ft_printf("%p", &test);
	ft_printf("(ft_printf : %i)\n", i);
	i = printf("%p", &test);
	printf("(printf : %i)\n", i);
	i = ft_printf("%p is a virtual memory address", &test);
	ft_printf("(ft_printf : %i)\n", i);
	i = printf("%p is a virtual memory address", &test);
	printf("(printf : %i)\n", i);
	i = ft_printf("the address of the answer is %p", &test);
	ft_printf("(ft_printf : %i)\n", i);
	i = printf("the address of the answer is %p", &test);
	printf("(printf : %i)\n", i);
	i = ft_printf("the addres is %p, so what?", &test);
	ft_printf("(ft_printf : %i)\n", i);
	i = printf("the addres is %p, so what?", &test);
	printf("(printf : %i)\n", i);
	int *ptr = &test;
	i = ft_printf("A pointer at %p points to %p", &test, &ptr);
	ft_printf("(ft_printf : %i)\n", i);
	i = printf("A pointer at %p points to %p", &test, &ptr);
	printf("(printf : %i)\n", i);
	i = ft_printf("This %p is a very strang address", (void *)(long int)test);
	ft_printf("(ft_printf : %i)\n", i);
	i = printf("This %p is a very strang address", (void *)(long int)test);
	printf("(printf : %i)\n", i);
	char *mallocked = malloc(2);
	i = ft_printf("this %p is an to_address from the heap", mallocked);
	ft_printf("(ft_printf : %i)\n", i);
	i = printf("this %p is an to_address from the heap", mallocked);
	printf("(printf : %i)\n", i);
	free(mallocked);
	i = ft_printf("%p", NULL);
	ft_printf("(ft_printf : %i)\n", i);
	i = printf("%p", NULL);
	printf("(printf : %i)\n", i);
	i = ft_printf("The NULL macro represents the %p address", NULL);
	ft_printf("(ft_printf : %i)\n", i);
	i = printf("The NULL macro represents the %p address", NULL);
	printf("(printf : %i)\n", i);
	i = ft_printf("this %p is even stranger", (void *)-1);
	ft_printf("(ft_printf : %i)\n", i);
	i = printf("this %p is even stranger", (void *)-1);
	printf("(printf : %i)\n", i);
}

int	to_address(long long n)
{
	char	*res;
	char	*base;
	int		i;

	base = "0123456789abcdef";
	res = malloc(get_int_len(n) * sizeof(char) + 1);
	if (!res)
		return (0);
	i = 0;
	while (n > 0)
	{
		res[i] = base[n % 16];
		n = n / 16;
		i++;
	}
	res[i] = 0;
	revert_char(res);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(res, 1);
	free (res);
	return (i + 1);
}

int	to_hex(int n, int uppercase)
{
	char	*res;
	char	*base;
	int		i;

	base = "0123456789ABCDEF";
	res = malloc(get_int_len(n) * sizeof(char) + 1);
	if (!res)
		return (0);
	i = 0;
	while (n > 0)
	{
		res[i] = base[n % 16];
		n = n / 16;
		i++;
	}
	res[i] = 0;
	revert_char(res);
	if (!uppercase)
		lower_str(res);
	ft_putstr_fd(res, 1);
	free(res);
	return (i - 1);
}

void	lower_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
}

void	revert_char(char *str)
{
	int		len;
	int		i;
	char	temp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}

int	get_int_len(int n)
{
	if (n < 10)
		return (1);
	return (1 + get_int_len(n / 10));
}

void	ft_put_unsigned_nbr_fd(unsigned int n, int fd)
{
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else 
	{
		ft_put_unsigned_nbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n * -1, fd);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd(n + '0', fd);
		else
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(n % 10 + '0', fd);
		}
	}
}
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
