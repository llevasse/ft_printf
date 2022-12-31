/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_extra.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:02:53 by llevasse          #+#    #+#             */
/*   Updated: 2022/12/29 15:40:55 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	print_var_pound(const char *str, va_list args)
{
	int	to_print;

	if (*str == 'x' || *str == 'X')
	{
		to_print = va_arg(args, int);
		if (to_print == 0)
			return (ft_printf("0"));
		if (*str == 'x')
			return (ft_printf("0x%x", to_print));
		if (*str == 'X')
			return (ft_printf("0X%X", to_print));
	}
	return (0);
}

int	print_var_space_plus(const char *str, va_list args, char c)
{
	int		int_to_print;

	int_to_print = 0;
	if (*str == 'd' || *str == 'i')
	{
		int_to_print = va_arg(args, int);
		if (int_to_print < 0)
			return (ft_printf("%d", int_to_print));
		return (ft_printf("%c%d", c, int_to_print));
	}
	if (ft_isdigit(*str))
	{
		int_to_print = ft_atoi(str);
		while (!is_specifier_b(*str, 0) && *str)
			str++;
	}
	if (*str == 's')
		return (print_var_space_plus_s(args, int_to_print));
	return (0);
}

int	print_var_space_plus_s(va_list args, int int_to_print)
{
	char	*str_to_print;
	size_t	i;

	i = 0;
	str_to_print = va_arg(args, char *);
	if (ft_strlen(str_to_print) >= (size_t)int_to_print)
		return (ft_printf("%s", str_to_print));
	while (i < (size_t)int_to_print - ft_strlen(str_to_print))
		i += ft_printf(" ");
	return (i + ft_printf("%s", str_to_print));
}
