/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priorities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:46:32 by llevasse          #+#    #+#             */
/*   Updated: 2023/02/06 15:24:03 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

int	check_priorities(const char *str, va_list args, int *sum)
{
	int		spec;

	spec = 0;
	while (!is_specifier(*(str + spec), 0))
		spec++;
	spec = *(str + spec);
	if (spec == '%')
		return (ft_putchar('%', sum), 1);
	if (*str == '0')
	{
		while (!is_specifier(*str, 0) && *str)
		{
			if (ft_isdigit(*str) && *str != '0')
				return (print_field_width(str, args, sum), 1);
			if (*str == '-')
				return (print_minus(str, args, sum), 1);
			if (*str++ == '.' && ft_is_in_str("diuxX", spec))
				return (print_prec((str), args, sum), 1);
		}
	}
	if (*str == ' ')
	{
		while (!is_specifier(*str, 0) && *str)
		{
			if (*str == '+')
				return (print_plus((str), args, sum), 1);
			if (ft_is_in_str("132456789", *str))
				return (print_field_width(str, args, sum), 1);
			str++;
		}
	}
	return (0);
}
