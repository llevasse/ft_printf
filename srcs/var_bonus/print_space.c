/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:18:02 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/28 16:06:20 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

void	print_space(const char *str, va_list args, int *sum)
{
	int		var;
	char	*str_to_print;

	while (!is_specifier(*str, 0))
		str++;
	if (*str == 'i' || *str == 'd')
	{
		var = va_arg(args, int);
		if (var >= 0)
			ft_putchar(' ', sum);
		return (ft_putnbr(var, sum));
	}
	if (*str == 's')
	{
		str_to_print = va_arg(args, char *);
		if (!*str_to_print)
			return (ft_putchar(' ', sum));
		ft_putstr(str_to_print, sum);
	}
	print_var(str, args, sum);
}
