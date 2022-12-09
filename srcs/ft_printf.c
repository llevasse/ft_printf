/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:33:53 by llevasse          #+#    #+#             */
/*   Updated: 2022/12/09 08:44:16 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *string, ...)
{
	const char	*to_print_str;
	va_list		args;
	int			i;

	to_print_str = string;
	va_start(args, string);
	i = 0;
	while (*to_print_str)
	{
		while (*to_print_str != '%' && *to_print_str)
		{
			ft_putchar_fd(*to_print_str, 1);
			to_print_str++;
			i++;
		}
		if (*to_print_str == '%')
		{
			to_print_str++;
			i += print_var(*to_print_str, args);
		}
		if (*to_print_str)
			to_print_str++;
	}
	va_end(args);
	return (i);
}

int	print_var(char c, va_list args)
{
	char			*str;
	int				size;
	unsigned int	unsignedint;

	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (c == 's')
	{
		str = va_arg(args, char *);
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	else if (c == 'd' || c == 'i')
	{
		str = ft_itoa(va_arg(args, int));
		ft_putstr_fd(str, 1);
		size = ft_strlen(str);
		free(str);
		return (size);
	}
	else if (c == 'u')
	{
		unsignedint = va_arg(args, unsigned int);
		ft_put_unsigned_nbr_fd(unsignedint, 1);
		return (get_len_int(unsignedint));
	}
	else if (c == 'x')
		return (to_hex(va_arg(args, int), 0));
	else if (c == 'X')
		return (to_hex(va_arg(args, int), 1));
	else if (c == 'p')
		return (to_address((long long)va_arg(args, unsigned long long)));
	return (0);
}

/* #include <stdio.h>

#define INT_MAX INT32_MAX
#define INT_MIN -INT32_MAX-1
#define LONG_MAX __LONG_MAX__
#define LONG_MIN -__LONG_MAX__-1L
#define UINT_MAX INT32_MAX*2U+1U
#define ULONG_MAX __LONG_MAX__*2UL+1UL

int main()
{
	int i;
	i = ft_printf(" %d ", 0);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", -1);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", 1);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", 9);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", 10);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", 11);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", 15);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", 16);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", 17);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", 99);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", 100);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", 101);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", -9);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", -10);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", -11);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", -14);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", -15);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", -16);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", -99);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", -100);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", -101);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", INT_MAX);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", INT_MIN);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", LONG_MAX);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", LONG_MIN);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", UINT_MAX);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", ULONG_MAX);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d ", 9223372036854775807LL);
	printf("(ft_printf : %i)\n", i);
	i = ft_printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("(ft_printf : %i)\n", i);	
}

int	to_address(long long n)
{
	char	*res;
	char	*base;
	int		i;

	if (n < 0)
		return (i = ft_printf("0xffffffffffffffff"));
	if (n == 0)
		return (i = ft_printf("(nil)"));
	base = "0123456789abcdef";
	res = malloc(17 * sizeof(char));
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
	return (i + 2);
}

int	to_hex(int n, int uppercase)
{
	char	*res;
	char	*base;
	int		i;

	base = "0123456789ABCDEF";
	res = malloc(get_len_int(n) * sizeof(char) + 1);
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

int	get_len_int(int n)
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

char	*ft_itoa(int n)
{
	char	*res;
	int		len_int;
	int		is_neg;
	long	long_n;

	long_n = (long)n;
	is_neg = 0;
	if (long_n < 0)
	{
		is_neg = 1;
		long_n = long_n * -1;
	}
	len_int = get_int_len(long_n);
	res = malloc((len_int + 2) * sizeof(char));
	if (!res)
		return (NULL);
	res[len_int] = '\0';
	fill_res(res, len_int, long_n);
	if (is_neg == 0)
		return (res);
	else
		return (set_minus(res, len_int));
}

void	fill_res(char *res, int len_int, long n)
{
	int	i;

	i = len_int - 1;
	while (i > 0 && n > 9)
	{
		res[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	res[0] = n + '0';
}

char	*set_minus(char *s, int len)
{
	char	*res;

	res = malloc(len * sizeof(char) + 2);
	if (!res)
		return (NULL);
	ft_memset(res, 0, len + 2);
	res[0] = '-';
	ft_strcat(res, s);
	return (res);
}

void	ft_strcat(char *dst, const char *src)
{
	while (*dst)
		dst++;
	while (*src)
	{
		*dst++ = *src;
		src++;
	}
	*dst = '\0';
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	replace;

	replace = (unsigned char) c;
	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = replace;
		i++;
	}
	return (b);
}
 */