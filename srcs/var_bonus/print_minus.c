/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:49:53 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/30 11:07:00 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

void	print_minus(const char *str, va_list args, int *sum)
{
	int	min;

	while (!ft_isdigit(*str) && !is_specifier(*str, 0))
		str++;
	min = *sum + ft_atoi(str);
	while (!is_specifier(*str, 0))
		str++;
	print_var(str, args, sum);
	while (*sum < min)
		ft_putchar(' ', sum);
}
