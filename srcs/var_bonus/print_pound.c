/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pound.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:37:28 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/26 13:42:57 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

void	print_pound(const char *str, va_list args, int *sum)
{
	while (!is_specifier(*str, 0))
		str++;
	if (*str == 'x')
	{
		ft_putstr("0x", sum);
		return (ft_putnbr_base(va_arg(args, int), "0123456789abcdef", sum));
	}
	else if (*str == 'X')
	{
		ft_putstr("0x", sum);
		return (ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", sum));
	}
}
