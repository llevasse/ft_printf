/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:33:53 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/24 12:26:19 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	ft_printf(const char *string, ...)
{
	va_list		args;
	int			sum;

	va_start(args, string);
	sum = 0;
	while (*string && sum != -1)
	{
		while (*string != '%' && *string)
			ft_putchar(*string++, &sum);
		if (*string == '%')
		{
			string++;
			p_var(string, args, &sum);
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

void	p_var(const char *str, va_list args, int *sum)
{
	char	*str_p;

	str_p = NULL;
	if (is_specifier_b(*str, 1) || ft_isdigit(*str))
		return (p_var_bonus(str, args, sum));
	else if (*str == '%')
		return (ft_putchar('%', sum));
	else if (*str == 'c')
		return (ft_putchar(va_arg(args, int), sum));
	else if (*str == 's')
		return (ft_putstr(va_arg(args, char *), 0, sum));
	else if (is_specifier_b(*str, 0))
		str_p = var_to_str(*str, args);
	if (!str_p)
		return (end_ft_printf(sum));
	ft_putstr(str_p, 1, sum);
}

char	*var_to_str(char c, va_list args)
{
	char	*str;

	str = NULL;
	if (c == 'd' || c == 'i')
		str = (ft_itoa(va_arg(args, int)));
	else if (c == 'u')
		str = (ft_itoa_unsigned(va_arg(args, int)));
	else if (c == 'x')
		str = to_base(va_arg(args, int), "0123456789abcdef");
	else if (c == 'X')
		str = to_base(va_arg(args, int), "0123456789ABCDEF");
	else if (c == 'p')
	{
		str = to_base_u(va_arg(args, unsigned long long), "0123456789abcdef");
		if (!str)
			return (str);
		revert_char(str);
		revert_char(ft_strjoin(str, "0x"));
	}
	return (str);
}

void	p_var_bonus(const char *str, va_list args, int *sum)
{
	int	min;

	if (*str == '-')
		return (p_var_minus(str + 1, args, sum));
	if (ft_isdigit(*str) && *str != '0')
	{
		min = ft_atoi(str);
		while (!is_specifier_b(*str, 0))
		{
			if (*str++ == '.')
				return (p_field_max(str, args, min, sum));
		}
		return (p_var_field_minimum(*str, args, min, sum));
	}
	if (*str == '0')
		return (p_var_0(str + 1, args, sum));
	if (*str == '.')
		return (p_var_dot(str + 1, args, sum));
	if (*str == '#')
		return (p_var_pound(str + 1, args, sum));
	if (*str == ' ')
		return (p_var_space(str + 1, args, ' ', sum));
	if (*str == '+')
		return (p_var_space(str + 1, args, '+', sum));
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
