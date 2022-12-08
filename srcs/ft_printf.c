/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:33:53 by llevasse          #+#    #+#             */
/*   Updated: 2022/12/08 17:27:00 by leo              ###   ########.fr       */
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
		size = va_arg(args, int);
		ft_putnbr_fd(size, 1);
		return (get_int_len(size));
	}
	else if (c == 'u')
	{
		unsignedint = va_arg(args, unsigned int);
		ft_put_unsigned_nbr_fd(unsignedint, 1);
		return (get_int_len(unsignedint));
	}
	else if (c == 'x')
		return (to_hex(va_arg(args, int), 0));
	else if (c == 'X')
		return (to_hex(va_arg(args, int), 1));
	else if (c == 'p')
		return (to_address((long long)va_arg(args, unsigned long long)));
	return (0);
}







#include <stdio.h>

int main()
{
	
}

int	to_address(long long n)
{
	char	*res;
	char	*base;
	int		i;

	if (n < 0)
		return (ft_printf("0xffffffffffffffff"));
	if (n == 0)
		return (ft_printf("(nil)"));
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
