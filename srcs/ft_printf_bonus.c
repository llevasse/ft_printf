/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:33:53 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/26 14:13:50 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	ft_printf(const char *string, ...)
{
	va_list		args;
	int			i;

	va_start(args, string);
	i = 0;
	while (*string && i != -1)
	{
		while (*string != '%' && *string)
		{
			ft_putchar(*string, &i);
			string++;
		}
		if (*string == '%')
		{
			string++;
			print_var(string, args, &i);
			while (!is_specifier(*string, 0))
				string++;
		}
		if (*string)
			string++;
	}
	va_end(args);
	return (i);
}

void	print_var(const char *str, va_list args, int *sum)
{
	char	*base;

	if (is_specifier(*str, 1))
		return (print_var_bonus(str, args, sum));
	base = "0123456789abcdef";
	if (*str == '%')
		return (ft_putchar('%', sum));
	else if (*str == 'c')
		return (ft_putchar(va_arg(args, int), sum));
	else if (*str == 's')
		return (ft_putstr(va_arg(args, char *), sum));
	else if (*str == 'd' || *str == 'i')
		return (ft_putnbr(va_arg(args, int), sum));
	else if (*str == 'u')
		return (ft_putnbr(va_arg(args, unsigned int), sum));
	else if (*str == 'x')
		return (ft_putnbr_base(va_arg(args, int), "0123456789abcdef", sum));
	else if (*str == 'X')
		return (ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", sum));
	else if (*str == 'p')
	{
		ft_putstr("0x", sum);
		ft_putnbr_base_u(va_arg(args, unsigned long long), base, sum);
	}
}

void	print_var_bonus(const char *str, va_list args, int *sum)
{
	if (*str == '#')
		return (print_pound(str++, args, sum));
	if (*str == '-')
		return (print_minus(str++, args, sum));
}

int	is_specifier(char c, int bonus)
{
	if (!bonus && (c == '%' || c == 'c' || c == 's' || c == 'd' || c == 'i' \
	|| c == 'u' || c == 'x' || c == 'X' || c == 'p'))
		return (1);
	if (bonus == 1 && (c == '#' || c == '-'))
		return (1);
	if (bonus == 2 && (is_specifier(c, 0) || is_specifier(c, 1)))
		return (1);
	return (0);
}
