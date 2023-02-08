/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_field_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:28:18 by llevasse          #+#    #+#             */
/*   Updated: 2023/02/08 16:07:56 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

void	print_field_width(const char *str, va_list args, int *sum)
{
	int		width;
	int		len;

	width = ft_atoi(str);
	if (*str == '*')
		width = va_arg(args, int);
	while (!is_specifier(*str, 0))
	{
		if (*str++ == '.')
			return (print_width_prec(str, args, width, sum));
	}
	len = predict_len(str, args);
	if (is_neg(str, args) == 1)
		ft_putchar('-', sum);
	if (len > 1 && get_spec(str) == 'p')
		len += 2;
	if (len == 1 && get_spec(str) == 'p')
		len = 5;
	while (width-- > len)
	{
		if (get_para(str) != '0')
			ft_putchar(' ', sum);
		else
			ft_putchar('0', sum);
	}
	print_var(str, args, sum);
}

void	print_width_prec(const char *str, va_list args, int width, int *sum)
{
	int		i;
	int		prec;
	int		spec;

	prec = ft_atoi(str);
	spec = ' ';
	i = predict_length_precision(str, args, prec);
	while (width > i++)
		ft_putchar(spec, sum);
	i = 0;
	while (!is_specifier(*str, 0))
	{
		str++;
		i++;
	}
	if (ft_is_in_str("diuxX", *str))
		print_padding((str - i), args, '0', sum);
	if (*str == 's')
		print_width_prec_s(va_arg(args, char *), prec, sum);
}

int	is_neg(const char *str, va_list args)
{
	long long			int_to_print;
	va_list				args_cp;

	va_copy(args_cp, args);
	if (ft_is_in_str("dixXu", get_spec(str)))
	{
		int_to_print = va_arg(args_cp, long long);
		if (get_para(str) == '0')
		{
			if (int_to_print < 0)
				return (1);
		}
		if (int_to_print == 0)
			return (2);
	}
	return (0);
}

void	print_width_prec_s(char *str_to_print, int prec, int *sum)
{
	if (!str_to_print && prec >= 6)
		str_to_print = "(null)";
	while (prec-- > 0 && str_to_print && *str_to_print)
		ft_putchar(*str_to_print++, sum);
}

int	predict_length_precision(const char *str, va_list args, int prec)
{
	int			var_len;
	va_list		args_cp;

	while (!is_specifier(*str, 0))
		str++;
	va_copy(args_cp, args);
	var_len = predict_len(str, args);
	if (*str == 's')
	{
		if (!(va_arg(args_cp, char *)) && prec < 6)
			var_len = 0;
	}
	if (ft_is_in_str("diuxX", *str))
	{
		if (ft_is_in_str("dixX", *str) \
		&& va_arg(args_cp, int) < 0 \
		&& prec > var_len)
			prec++;
		if (prec > var_len)
			var_len = prec;
		return (var_len);
	}
	if (var_len < prec)
		return (var_len);
	return (prec);
}
