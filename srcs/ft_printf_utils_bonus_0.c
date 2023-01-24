/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_0.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:05:10 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/24 11:50:08 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	p_var_0(const char *str, va_list args, int *sum)
{
	int		min;

	min = ft_atoi(str);
	while (!is_specifier_b(*str, 0))
	{
		if (*str++ == '.')
			return (p_field_max(str, args, min, sum));
	}
	if (*str == '%')
		return (ft_putchar('%', sum));
	if (*str == 'd' || *str == 'i')
		return (p_var_0_d_or_i(args, min, sum));
	if (*str == 'u')
		return (p_var_0_u(args, min, sum));
	if (*str == 'x')
		return (p_var_0_hex(args, min, "0123456789abcdef", sum));
	if (*str == 'X')
		return (p_var_0_hex(args, min, "0123456789ABCDEF", sum));
	if (*str == '%')
		return (p_var_0_pound(min, sum));
}

void	p_var_0_pound(int min, int *sum)
{
	char	to_print;
	int		len_to_print;
	int		i;

	i = 0;
	to_print = '%';
	len_to_print = 1;
	if (len_to_print >= min)
		return (ft_putchar('%', sum));
	while (i++ < (min - len_to_print))
		ft_putchar('0', sum);
	return (ft_putchar('%', sum));
}

void	p_var_0_d_or_i(va_list args, int min, int *sum)
{
	int	to_print;
	int	len_to_print;
	int	i;

	i = 0;
	to_print = va_arg(args, int);
	if (to_print < 0)
	{
		len_to_print = 10;
		if (to_print == -2147483648 && min <= 10)
			return (ft_putstr("-2147483648", 0, sum));
		else
			len_to_print = get_int_len(to_print * -1) + 1;
		ft_putchar('-', sum);
		to_print = to_print * -1;
	}
	else
		len_to_print = get_int_len(to_print);
	if (len_to_print >= min)
		return (ft_putstr(ft_itoa(to_print), 1, sum));
	while (i++ < (min - len_to_print))
		ft_putchar('0', sum);
	return (ft_putstr(ft_itoa(to_print), 1, sum));
}

void	p_var_0_u(va_list args, int min, int *sum)
{
	unsigned int	to_print;
	int				len_to_print;
	int				i;

	i = 0;
	to_print = va_arg(args, unsigned int);
	len_to_print = get_unsigned_len(to_print);
	if (len_to_print >= min)
		return (ft_putstr(ft_itoa_unsigned(to_print), 1, sum));
	while (i++ < (min - len_to_print))
		ft_putchar('0', sum);
	return (ft_putstr(ft_itoa_unsigned(to_print), 1, sum));
}

void	p_var_0_hex(va_list args, int min, const char *base, int *sum)
{
	char	*to_print;
	int		len_to_print;
	int		i;

	i = 0;
	to_print = to_base(va_arg(args, int), base);
	if (!to_print)
		return ;
	len_to_print = ft_strlen(to_print);
	if (len_to_print >= min)
		return (ft_putstr(to_print, 1, sum));
	while (i++ < (min - len_to_print))
		ft_putchar('0', sum);
	return (ft_putstr(to_print, 1, sum));
}
