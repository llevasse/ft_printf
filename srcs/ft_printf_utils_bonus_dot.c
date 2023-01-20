/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_dot.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:50:00 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/20 14:57:06 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	p_var_dot(const char *str, va_list args, int *sum)
{
	int		precision;

	if (*str == '*')
		precision = va_arg(args, int);
	else
		precision = ft_atoi(str);
	while (!is_specifier_b(*str, 0))
		str++;
	if (*str == 'c')
		return (ft_putchar(va_arg(args, int), sum));
	if (*str == 's')
		return (p_var_dot_s(args, precision, sum));
	if (*str == 'd' || *str == 'i')
		return (p_var_dot_int(args, precision, sum));
	if (*str == 'u')
		return (p_var_dot_u(args, precision, sum));
	if (*str == 'x')
		return (p_var_dot_hex(args, precision, "0123456789abcdef", sum));
	if (*str == 'X')
		return (p_var_dot_hex(args, precision, "0123456789ABCDEF", sum));
	return (0);
}

void	p_var_dot_s(va_list args, int precision, int *sum)
{
	int			i;
	const char	*str_print;

	i = 0;
	if (precision == 0)
		return ;
	str_print = va_arg(args, char *);
	if (!str_print)
		str_print = "(null)";
	while (i++ < precision && *str_print)
		ft_putchar(*str_print++, sum);
}

void	p_var_dot_int(va_list args, int precision, int *sum)
{
	long	to_print;
	int		len_to_print;
	int		i;

	i = 0;
	to_print = (long)va_arg(args, int);
	if (to_print == 0 && precision == 0)
		return ;
	if (to_print < 0)
	{
		len_to_print = get_int_len(to_print * -1);
		ft_putchar('-', sum);
		i++;
		to_print *= -1;
		if (precision > len_to_print)
			len_to_print--;
	}
	else
		len_to_print = get_int_len(to_print);
	if (len_to_print >= precision)
		return (ft_putstr(ft_itoa_unsigned(to_print), 1, sum));
	while (i++ < (precision - len_to_print))
		ft_putchar('0', sum);
	return (ft_putstr(ft_itoa_unsigned(to_print), 1, sum));
}

void	p_var_dot_u(va_list args, int precision, int *sum)
{
	unsigned int	to_print;
	int				len_to_print;
	int				i;

	i = 0;
	to_print = va_arg(args, unsigned int);
	if (to_print == 0 && precision == 0)
		return ;
	len_to_print = get_unsigned_len(to_print);
	if (len_to_print >= precision)
		return (ft_putstr(ft_itoa_unsigned(to_print), 1, sum));
	while (i < (precision - len_to_print))
		ft_putchar('0', sum);
	return (ft_putstr(ft_itoa_unsigned(to_print), 1, sum));
}

void	p_var_dot_hex(va_list args, int precision, const char *base, int *sum)
{
	char	*to_print;
	int		len_to_print;
	int		i;

	i = 0;
	to_print = to_base(va_arg(args, int), base);
	if (to_print[0] == '0' && precision == 0)
		return (free(to_print), 0);
	len_to_print = ft_strlen(to_print);
	if (len_to_print >= precision)
		return (ft_putstr(to_print, 1, sum));
	i = ft_strlen(to_print);
	while (i++ < (precision - len_to_print))
		ft_putchar('0', sum);
	return (ft_putstr(to_print, 1, sum));
}
