/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:53:50 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/31 14:01:43 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

void	print_prec(const char *str, va_list args, int *sum)
{
	int		i;
	int		prec;
	char	*str_to_print;

	i = 0;
	prec = ft_atoi(str);
	while (!is_specifier(*str, 0))
	{
		str++;
		i++;
		if (ft_is_in_str("diuxX", *str))
			return (print_padding((str - i), args, '0', sum));
	}
	if (*str == 's' && prec > 0)
	{
		i = 0;
		str_to_print = va_arg(args, char *);
		if (!str_to_print)
			str_to_print = "(null)";
/* 		if (prec == 0)
			return (ft_putstr(str_to_print, sum));
 */		while (i < prec && str_to_print[i])
			ft_putchar(str_to_print[i++], sum);
	}
}

void	print_padding_prec(const char *str, va_list args, char c, int *sum)
{
	int		var_len;
	int		int_to_print;
	int		padding_len;

	padding_len = ft_atoi(str);
	while (!is_specifier(*str, 0))
		str++;
	var_len = print_odd_prec(str, args, sum);
	while (padding_len-- - var_len > 0)
		ft_putchar(c, sum);
	if (*str != 'd' && *str != 'i')
		return (print_var(str, args, sum));
	int_to_print = va_arg(args, int);
	if (int_to_print < 0)
		int_to_print *= -1;
	return (ft_putnbr(int_to_print, sum));
}

int	print_odd_prec(const char *str, va_list args, int *sum)
{
	va_list	args_cp;
	int		var_len;
	int		int_to_print;

	va_copy(args_cp, args);
	var_len = predict_len(str, args);
	if (*str == 'd' || *str == 'i')
	{
		int_to_print = va_arg(args_cp, int);
		if (int_to_print < 0)
		{
			var_len--;
			ft_putchar('-', sum);
			int_to_print *= -1;
		}
	}
	return (var_len);
}
