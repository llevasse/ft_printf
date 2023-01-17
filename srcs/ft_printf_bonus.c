/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:33:53 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/17 12:02:08 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	ft_printf(const char *string, ...)
{
	va_list		args;
	int			sum;

	va_start(args, string);
	sum = 0;
	while (*string)
	{
		while (*string != '%' && *string)
			sum += ft_putchar(*string++);
		if (*string == '%')
		{
			string++;
			sum += p_var(string, args);
			if (is_specifier_b(*string, 1))
			{
				string++;
				while (!is_specifier_b(*string, 0))
					string++;
			}
		}
		if (*string)
			string++;
	}
	va_end(args);
	return (sum);
}

int	p_var(const char *str, va_list args)
{
	if (*str == '%')
		return (ft_printf("%c", '%'));
	else if (*str == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*str == 's')
		return (ft_putstr(va_arg(args, char *), 0));
	else if (*str == 'd' || *str == 'i')
		return (ft_putstr(ft_itoa(va_arg(args, int)), 1));
	else if (*str == 'u')
		return (ft_putstr(ft_itoa_unsigned(va_arg(args, int)), 1));
	else if (*str == 'x')
		return (to_hex(va_arg(args, int), 0));
	else if (*str == 'X')
		return (to_hex(va_arg(args, int), 1));
	else if (*str == 'p')
		return (to_address(va_arg(args, unsigned long long)));
	else if (is_specifier_b(*str, 1) || ft_isdigit(*str))
		return (p_var_bonus(str, args));
	return (0);
}

int	p_var_bonus(const char *str, va_list args)
{
	int	min_print;

	if (*str == '-')
		return (p_var_minus(str + 1, args));
	if (ft_isdigit(*str) && *str != '0')
	{
		min_print = ft_atoi(str);
		while (!is_specifier_b(*str, 0) || *str != '.')
		{
			if (*str++ == '.')
				return (p_field_max(str, args, min_print, ft_atoi((str))));
		}
		return (p_var_field_minimum(*str, args, min_print));
	}
	if (*str == '0')
		return (p_var_0(str + 1, args));
	if (*str == '.')
		return (p_var_dot(str + 1, args));
	if (*str == '#')
		return (p_var_pound(str + 1, args));
	if (*str == ' ')
		return (p_var_space_plus(str + 1, args, ' '));
	if (*str == '+')
		return (p_var_space_plus(str + 1, args, '+'));
	return (0);
}

int	is_specifier_b(char c, int is_bonus)
{
	if (is_bonus == 0 && (c == '%' || c == 'c' || c == 's' || c == 'd' \
	|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == 'p'))
		return (1);
	if (is_bonus == 1 && (c == '-' || c == '.' \
	|| c == '#' || c == ' ' || c == '+' || ft_isdigit(c)))
		return (1);
	if (is_bonus == 2 && (is_specifier_b(c, 0) || is_specifier_b(c, 1)))
		return (1);
	return (0);
}
