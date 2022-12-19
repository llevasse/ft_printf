/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:33:53 by llevasse          #+#    #+#             */
/*   Updated: 2022/12/19 16:18:56 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	ft_printf(const char *string, ...)
{
	const char	*to_print_str;
	va_list		args;
	int			sum;

	to_print_str = string;
	va_start(args, string);
	sum = 0;
	while (*to_print_str)
	{
		while (*to_print_str != '%' && *to_print_str)
		{
			ft_putchar_fd(*to_print_str, 1);
			to_print_str++;
			sum++;
		}
		if (*to_print_str == '%')
		{
			to_print_str++;
			sum += print_var(*to_print_str, args);
			sum += print_var_bonus(to_print_str, args);
			if (is_bonus_specifier(*to_print_str) || ft_isdigit(*to_print_str))
			{
				to_print_str++;
				while (!is_specifier(*to_print_str) || ft_isdigit(*to_print_str))
					to_print_str++;
			}
		}
		if (*to_print_str)
			to_print_str++;
	}
	va_end(args);
	return (sum);
}

int	print_var(char c, va_list args)
{
	char			*temp;
	int				size;

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
		temp = va_arg(args, char *);
		if (!temp)
			return (ft_putstr_fd("(null)", 1), 6);
		ft_putstr_fd(temp, 1);
		return (ft_strlen(temp));
	}
	else if (c == 'd' || c == 'i')
	{
		temp = ft_itoa(va_arg(args, int));
		ft_putstr_fd(temp, 1);
		size = ft_strlen(temp);
		free(temp);
		return (size);
	}
	else if (c == 'u')
	{
		temp = ft_itoa_unsigned(va_arg(args, unsigned int));
		ft_putstr_fd(temp, 1);
		size = ft_strlen(temp);
		free(temp);
		return (size);
	}
	else if (c == 'x')
		return (to_hex(va_arg(args, int), 0));
	else if (c == 'X')
		return (to_hex(va_arg(args, int), 1));
	else if (c == 'p')
		return (to_address((unsigned long long)va_arg(args, unsigned long long)));
	return (0);
}

int	print_var_bonus(const char *str, va_list args)
{
	int	min_print;
	int	sum;

	sum = 0;
	if (*str == '-')
	{
		str++;
		min_print = ft_atoi(str);
		while (!is_specifier(*str))
			str++;
		sum = print_var(*str, args);
		while (sum < min_print)
		{
			ft_putchar_fd(' ', 1);
			sum++;
		}
	}
	if (ft_isdigit(*str) && *str != '0')
	{
		min_print = ft_atoi(str);
		while (!is_specifier(*str))
			str++;
		sum = print_var(*str, args);
		while (sum < min_print)
		{
			ft_putchar_fd(' ', 1);
			sum++;
		}
	}
	if (*str == '0')
	{
		str++;
		return (print_var_0(str, args));
	}
	if (*str == '.')
	{
		str++;
		return (print_var_dot(str, args));
	}
	return (sum);
}

int	print_var_0(const char *str, va_list args)
{
	int		min_print;

	min_print = ft_atoi(str);
	while (!is_specifier(*str))
		str++;
	if (*str == 'd' || *str == 'i')
		return (print_var_0_d_or_i(args, min_print));
	if (*str == 'u')
		return (print_var_0_u(args, min_print));
	if (*str == 'x')
		return (print_var_0_hex(args, min_print, 0));
	if (*str == 'X')
		return (print_var_0_hex(args, min_print, 1));
	return (0);
}

int	print_var_0_d_or_i(va_list args, int min_print)
{
	int	to_print;
	int	len_to_print;
	int	i;

	i = 0;
	to_print = va_arg(args, int);
	if (to_print < 0)
	{
		if (to_print == -2147483648)
		{
			if (min_print <= 10)
				return (ft_printf("-2147483648"));
			len_to_print = 10;
		}
		else
			len_to_print = get_len_int(to_print * -1);
		i += ft_printf("-");
		to_print = to_print * -1;
	}
	else
		len_to_print = get_len_int(to_print);
	if (len_to_print >= min_print)
		return (i + ft_printf("%d", to_print));
	while (i < (min_print - len_to_print))
	{
		ft_printf("0");
		i++;
	}
	return (i + ft_printf("%d", to_print));
}

int	print_var_0_u(va_list args, int min_print)
{
	unsigned int	to_print;
	int	len_to_print;
	int	i;

	i = 0;
	to_print = va_arg(args, unsigned int);
	len_to_print = get_unsigned_len(to_print);
	if (len_to_print >= min_print)
		return (i + ft_printf("%u", to_print));
	while (i < (min_print - len_to_print))
	{
		ft_printf("0");
		i++;
	}
	return (i + ft_printf("%u", to_print));
}

int	print_var_0_hex(va_list args, int min_print, int uppercase)
{
	char	*to_print;
	int		len_to_print;
	int		i;

	i = 0;
	to_print = get_hex(va_arg(args, int), uppercase);
	if (!to_print)
		return (0);
	len_to_print = ft_strlen(to_print);
	if (len_to_print >= min_print)
	{	
		ft_printf("%s", to_print);
		i += ft_strlen(to_print);
		return (free (to_print), i);
	}
	while (i < (min_print - len_to_print))
	{
		ft_printf("0");
		i++;
	}
	ft_printf("%s", to_print);
	i += ft_strlen(to_print);
	return (free (to_print), i);
}



int	is_bonus_specifier(char c)
{
	if (c == '-')
		return (1);
	return (0);
}

int is_specifier(char c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == 'p')
		return (1);
	return (0);
}
