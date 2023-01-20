/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_extra.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:02:53 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/20 15:07:56 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	p_var_pound(const char *str, va_list args, int *sum)
{
	int	to_print;

	if (*str == 'x' || *str == 'X')
	{
		to_print = va_arg(args, int);
		if (to_print == 0)
			return (ft_putchar('0', sum));
		if (*str == 'x')
		{
			ft_putstr("0x", 0, sum);
			ft_putstr(to_base(to_print, "0123456789abcdef"), 1, sum);
		}
		if (*str == 'X')
		{
			ft_putstr("0X", 0, sum);
			ft_putstr(to_base(to_print, "0123456789ABCEDF"), 1, sum);
		}
	}
}

void	p_var_space_plus(const char *str, va_list args, char c, int *sum)
{
	int		int_to_print;

	int_to_print = 0;
	if (*str == 'd' || *str == 'i')
	{
		int_to_print = va_arg(args, int);
		if (int_to_print < 0)
			return (ft_putstr(ft_itoa(int_to_print), 1, sum));
		ft_putchar(c, sum);
		return (ft_putstr(ft_itoa(int_to_print), 1, sum));
	}
	if (ft_isdigit(*str))
	{
		int_to_print = ft_atoi(str);
		while (!is_specifier_b(*str, 0) && *str)
			str++;
	}
	if (*str == 's')
		return (p_var_space_plus_s(args, int_to_print, sum));
}

void	p_var_space_plus_s(va_list args, int int_to_print, int *sum)
{
	char	*str_to_print;
	size_t	i;

	i = 0;
	str_to_print = va_arg(args, char *);
	if (ft_strlen(str_to_print) >= (size_t)int_to_print)
		return (ft_putstr(str_to_print, 0, sum));
	while (i++ < (size_t)int_to_print - ft_strlen(str_to_print))
		ft_putchar(' ', sum);
	return (ft_putstr(str_to_print, 0, sum));
}
