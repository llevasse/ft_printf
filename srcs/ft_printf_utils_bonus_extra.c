/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_extra.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:02:53 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/24 17:13:29 by llevasse         ###   ########.fr       */
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
		ft_putchar('0', sum);
		ft_putchar(*str, sum);
		if (*str == 'x')
			ft_putstr(to_base(to_print, "0123456789abcdef"), 1, sum);
		if (*str == 'X')
			ft_putstr(to_base(to_print, "0123456789ABCDEF"), 1, sum);
	}
}

void	p_var_space(const char *str, va_list args, char c, int *sum)
{
	int		int_to_print;
	int		len_to_print;

	len_to_print = ft_atoi(str);
	while (!is_specifier_b(*str, 0) && *str)
	{
		if (*str++ == '.')
		{
			if (*str == '*')
				return (p_var_s_dot(va_arg(args, int), va_arg(args, int), sum));
			return (p_var_s_dot(ft_atoi(str), va_arg(args, int), sum));
		}
	}
	if (*str == 's')
		return (p_var_space_s(args, len_to_print, sum));
	int_to_print = va_arg(args, int);
	put_space(int_to_print, len_to_print, sum, c);
	return (ft_putstr(ft_itoa(int_to_print), 1, sum));
}

void	put_space(int int_to_print, int len_to_print, int *sum, char c)
{
	if (int_to_print < 0)
	{
		while (len_to_print-- > get_unsigned_len(int_to_print * -1) + 1)
			ft_putchar(' ', sum);
	}
	else
	{
		while (len_to_print-- > get_int_len(int_to_print) + 1)
			ft_putchar(' ', sum);
	}
	if (int_to_print >= 0)
		ft_putchar(c, sum);
}

void	p_var_s_dot(int prec, int to_print, int *sum)
{
	int		len_to_print;
	int		i;

	i = 0;
	if (to_print == 0 && prec == 0)
		return ;
	if (to_print < 0)
	{
		len_to_print = get_int_len(to_print * -1);
		ft_putchar('-', sum);
		i++;
		to_print *= -1;
		if (prec > len_to_print)
			len_to_print--;
	}
	else
		len_to_print = get_int_len(to_print);
	if (len_to_print >= prec)
		return (ft_putstr(ft_itoa_unsigned(to_print), 1, sum));
	while (i++ < (prec - len_to_print))
		ft_putchar('0', sum);
	return (ft_putstr(ft_itoa_unsigned(to_print), 1, sum));
}

void	p_var_space_s(va_list args, int int_to_print, int *sum)
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
