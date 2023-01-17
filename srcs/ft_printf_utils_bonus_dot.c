/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_dot.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:50:00 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/17 12:02:08 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	p_var_dot(const char *str, va_list args)
{
	int		precision;

	if (*str == '*')
		precision = va_arg(args, int);
	else
		precision = ft_atoi(str);
	while (!is_specifier_b(*str, 0))
		str++;
	if (*str == 'c')
		return (ft_printf("%c", va_arg(args, int)));
	if (*str == 's')
		return (p_var_dot_s(args, precision));
	if (*str == 'd' || *str == 'i')
		return (p_var_dot_int(args, precision));
	if (*str == 'u')
		return (p_var_dot_u(args, precision));
	if (*str == 'x')
		return (p_var_dot_hex(args, precision, 0));
	if (*str == 'X')
		return (p_var_dot_hex(args, precision, 1));
	return (0);
}

int	p_var_dot_s(va_list args, int precision)
{
	int			i;
	const char	*str_print;

	i = 0;
	if (precision == 0)
		return (0);
	str_print = va_arg(args, char *);
	if (!str_print)
		str_print = "(null)";
	while (i < precision && *str_print)
		i += ft_printf("%c", *str_print++);
	return (i);
}

int	p_var_dot_int(va_list args, int precision)
{
	long	to_print;
	int		len_to_print;
	int		i;

	i = 0;
	to_print = (long)va_arg(args, int);
	if (to_print == 0 && precision == 0)
		return (0);
	if (to_print < 0)
	{
		len_to_print = get_int_len(to_print * -1);
		i += ft_printf("-");
		to_print *= -1;
		if (precision > len_to_print)
			len_to_print--;
	}
	else
		len_to_print = get_int_len(to_print);
	if (len_to_print >= precision)
		return (i + ft_printf("%u", to_print));
	while (i < (precision - len_to_print))
		i += ft_printf("0");
	return (i + ft_printf("%u", to_print));
}

int	p_var_dot_u(va_list args, int precision)
{
	unsigned int	to_print;
	int				len_to_print;
	int				i;

	i = 0;
	to_print = va_arg(args, unsigned int);
	if (to_print == 0 && precision == 0)
		return (0);
	len_to_print = get_unsigned_len(to_print);
	if (len_to_print >= precision)
		return (i + ft_printf("%u", to_print));
	while (i < (precision - len_to_print))
		i += ft_printf("0");
	return (i + ft_printf("%u", to_print));
}

int	p_var_dot_hex(va_list args, int precision, int uppercase)
{
	char	*to_print;
	int		len_to_print;
	int		i;

	i = 0;
	to_print = get_hex(va_arg(args, int), uppercase);
	if (to_print[0] == '0' && precision == 0)
		return (0);
	if (to_print[0] == '0' && precision == 0)
		return (free(to_print), 0);
	len_to_print = ft_strlen(to_print);
	if (len_to_print >= precision)
	{	
		ft_printf("%s", to_print);
		i += ft_strlen(to_print);
		return (free (to_print), i);
	}
	while (i < (precision - len_to_print))
		i += ft_printf("0");
	ft_printf("%s", to_print);
	i += ft_strlen(to_print);
	return (free (to_print), i);
}
