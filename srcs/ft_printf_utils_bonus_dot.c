/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_dot.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:50:00 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/23 14:28:02 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	p_var_dot(const char *str, va_list args, int *sum)
{
	int		prec;

	if (*str == '*')
		prec = va_arg(args, int);
	else
		prec = ft_atoi(str);
	while (!is_specifier_b(*str, 0))
		str++;
	if (*str == 'c')
		return (ft_putchar(va_arg(args, int), sum));
	if (*str == 's')
		return (p_var_dot_s(args, prec, sum));
	if (*str == 'd' || *str == 'i')
		return (p_var_dot_int(args, prec, sum));
	if (*str == 'u')
		return (p_var_dot_u(args, prec, sum));
	if (*str == 'x')
		return (p_var_dot_x(args, prec, "0123456789abcdef", sum));
	if (*str == 'X')
		return (p_var_dot_x(args, prec, "0123456789ABCDEF", sum));
}

void	p_var_dot_s(va_list args, int prec, int *sum)
{
	int			i;
	const char	*str_print;

	i = 0;
	if (prec == 0)
		return ;
	str_print = va_arg(args, char *);
	if (!str_print)
		str_print = "(null)";
	while (i++ < prec && *str_print)
		ft_putchar(*str_print++, sum);
}

void	p_var_dot_int(va_list args, int prec, int *sum)
{
	long	to_print;
	int		len_to_print;
	int		i;

	i = 0;
	to_print = (long)va_arg(args, int);
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

void	p_var_dot_u(va_list args, int prec, int *sum)
{
	unsigned int	to_print;
	int				len_to_print;
	int				i;

	i = 0;
	to_print = va_arg(args, unsigned int);
	if (to_print == 0 && prec == 0)
		return ;
	len_to_print = get_unsigned_len(to_print);
	if (len_to_print >= prec)
		return (ft_putstr(ft_itoa_unsigned(to_print), 1, sum));
	while (i < (prec - len_to_print))
		ft_putchar('0', sum);
	return (ft_putstr(ft_itoa_unsigned(to_print), 1, sum));
}

void	p_var_dot_x(va_list args, int prec, const char *base, int *sum)
{
	char	*to_print;
	int		len_to_print;
	int		i;

	i = 0;
	to_print = to_base(va_arg(args, int), base);
	if (to_print[0] == '0' && prec == 0)
		return (free(to_print));
	len_to_print = ft_strlen(to_print);
	if (len_to_print >= prec)
		return (ft_putstr(to_print, 1, sum));
	i = ft_strlen(to_print);
	while (i++ < (prec - len_to_print))
		ft_putchar('0', sum);
	return (ft_putstr(to_print, 1, sum));
}
