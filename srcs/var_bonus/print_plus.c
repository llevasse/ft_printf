/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:38:19 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/27 10:41:48 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

void	print_plus(const char *str, va_list args, int *sum)
{
	int	var;

	while (!is_specifier(*str, 0))
		str++;
	if (*str == 'i' || *str == 'd')
	{
		var = va_arg(args, int);
		if (var >= 0)
			ft_putchar('+', sum);
		return (ft_putnbr(var, sum));
	}
	print_var(str, args, sum);
}
