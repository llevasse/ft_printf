/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priorities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:46:32 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/27 11:51:52 by llevasse         ###   ########.fr       */
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
	if (*str == '0')
	{
		while (!is_specifier(*str, 0) && *str)
		{
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
			if (*str++ == '+')
				return (print_plus((str - 1), args, sum), 1);
		}
	}
	return (0);
}
