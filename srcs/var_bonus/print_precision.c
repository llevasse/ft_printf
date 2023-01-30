/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:53:50 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/30 11:26:17 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

void	print_prec(const char *str, va_list args, int *sum)
{
	int		i;
	int		prec;
	char	*str_to_print;

	i = 0;
	prec = ft_atoi(str);
	while (!is_specifier(*str, 0))
	{
		str++;
		i++;
		if (ft_is_in_str("diuxX", *str))
			return (print_padding((str - i), args, '0', sum));
	}
	if (*str == 's')
	{
		i = 0;
		str_to_print = va_arg(args, char *);
		if (!str_to_print)
			str_to_print = "(null)";
/* 		if (prec == 0)
			return (ft_putstr(str_to_print, sum));
 */		while (i < prec && str_to_print[i])
			ft_putchar(str_to_print[i++], sum);
	}
}
