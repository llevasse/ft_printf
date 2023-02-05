/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_field_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:28:18 by llevasse          #+#    #+#             */
/*   Updated: 2023/02/05 11:54:26 by llevasse         ###   ########.fr       */
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
	while (width-- > len)
		ft_putchar(' ', sum);
	print_var(str, args, sum);
}

void	print_width_prec(const char *str, va_list args, int width, int *sum)
{
	int		i;
	int		prec;

	prec = ft_atoi(str);
	i = predict_length_precision(str, args, prec);
	while (width > i++)
		ft_putchar(' ', sum);
	i = 0;
	while (!is_specifier(*str, 0))
	{
		str++;
		i++;
		if (ft_is_in_str("diuxX", *str))
			return (print_padding((str - i), args, '0', sum));
	}
	if (*str == 's')
		print_width_prec_s(va_arg(args, char *), prec, width, sum);
}

void	print_width_prec_s(char *str_to_print, int prec, int width, int *sum)
{
	if (prec == 0)
		return (ft_putstr(str_to_print, sum));
	if ((size_t)width > ft_strlen(str_to_print))
	{
		while ((size_t)prec > ft_strlen(str_to_print))
		{
			ft_putchar(' ', sum);
			prec -= 1;
		}
	}
	while (prec-- > 0 && *str_to_print)
		ft_putchar(*str_to_print++, sum);
}

int	predict_length_precision(const char *str, va_list args, int prec)
{
	int	var_len;

	var_len = predict_len(str, args);
	if (var_len < prec)
		return (prec);
	return (var_len);
}
