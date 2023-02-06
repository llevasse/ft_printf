/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:44:31 by llevasse          #+#    #+#             */
/*   Updated: 2023/02/06 17:17:02 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

void	print_padding(const char *str, va_list args, char c, int *sum)
{
	int			var_len;
	long long	int_to_print;
	int			padding_len;
	char		*base;

	base = "0123456789abcdef";
	padding_len = ft_atoi(str);
	while (!is_specifier(*str, 0))
		str++;
	var_len = print_odd(str, args, sum, &padding_len);
	while (padding_len-- - var_len > 0)
		ft_putchar(c, sum);
	if (is_neg(str, args) == 2)
		return ;
	if (*str == 'p')
		return (ft_putnbr_base_u(va_arg(args, unsigned long long), base, sum));
	if (*str != 'd' && *str != 'i')
		return (print_var(str, args, sum));
	int_to_print = va_arg(args, int);
	if (int_to_print >= 0 && has_prec(str))
		padding_len--;
	if (int_to_print < 0)
		int_to_print *= -1;
	return (ft_putnbr(int_to_print, 0, sum));
}

int	print_odd(const char *str, va_list args, int *sum, int *padding)
{
	va_list	args_cp;
	int		var_len;
	int		int_to_print;

	va_copy(args_cp, args);
	var_len = predict_len(str, args);
	if (*str == 'p')
	{
		*padding -= 2;
		ft_putstr("0x", sum);
	}
	if (*str == 'd' || *str == 'i')
	{
		int_to_print = va_arg(args_cp, int);
		if (int_to_print < 0)
		{
			if (get_para(str) == '0')
				*padding -= 1;
			var_len--;
			if (get_para(str) != '0')
				ft_putchar('-', sum);
			int_to_print *= -1;
		}
	}
	return (var_len);
}

int	get_para(const char *str)
{
	int	spec;

	spec = 0;
	while (*(str - spec) != '%')
		spec++;
	return (*(str - (spec - 1)));
}

int	has_prec(const char *str)
{
	while (*str != '%')
		str--;
	str++;
	while (!is_specifier(*str, 0))
	{
		if (*str++ == '.')
			return (1);
	}
	return (0);
}

int	get_spec(const char *str)
{
	while (!(is_specifier(*str, 0)) && *str)
		str++;
	return (*str);
}
