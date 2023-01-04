/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_0.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:05:10 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/04 15:19:04 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	print_var_0(const char *str, va_list args)
{
	int		min_print;

	min_print = ft_atoi(str);
	while (!is_specifier_b(*str, 0))
	{
		if (*str == '.')
			return (print_var_field_max(str + 1, args, min_print));
		str++;
	}
	if (*str == 'd' || *str == 'i')
		return (print_var_0_d_or_i(args, min_print));
	if (*str == 'u')
		return (print_var_0_u(args, min_print));
	if (*str == 'x')
		return (print_var_0_hex(args, min_print, 0));
	if (*str == 'X')
		return (print_var_0_hex(args, min_print, 1));
	if (*str == '%')
		return (print_var_0_pound(min_print));
	return (0);
}

int print_var_0_pound(int min_print)
{
	char	to_print;
	int		len_to_print;
	int		i;

	i = 0;
	to_print = '%';
	len_to_print = 1;
	if (len_to_print >= min_print)
		return (i + ft_printf("%c", to_print));
	while (i < (min_print - len_to_print))
		i += ft_printf("0");
	return (i + ft_printf("%c", to_print));
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
		len_to_print = 10;
		if (to_print == -2147483648 && min_print <= 10)
			return (ft_printf("-2147483648"));
		else
			len_to_print = get_int_len(to_print * -1);
		i += ft_printf("-");
		to_print = to_print * -1;
	}
	else
		len_to_print = get_int_len(to_print);
	if (len_to_print >= min_print)
		return (i + ft_printf("%d", to_print));
	while (i < (min_print - len_to_print))
		i += ft_printf("0");
	return (i + ft_printf("%d", to_print));
}

int	print_var_0_u(va_list args, int min_print)
{
	unsigned int	to_print;
	int				len_to_print;
	int				i;

	i = 0;
	to_print = va_arg(args, unsigned int);
	len_to_print = get_unsigned_len(to_print);
	if (len_to_print >= min_print)
		return (i + ft_printf("%u", to_print));
	while (i < (min_print - len_to_print))
		i += ft_printf("0");
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
		i += ft_printf("0");
	ft_printf("%s", to_print);
	i += ft_strlen(to_print);
	return (free (to_print), i);
}
