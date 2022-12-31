/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_field_min_and_minus.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:47:04 by llevasse          #+#    #+#             */
/*   Updated: 2022/12/31 17:51:23 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	print_var_field_minimum(char c, va_list args, int min_print)
{
	char	*str_to_print;
	int		i;
	int		len_print;

	if (c == 's')
		str_to_print = va_arg(args, char *);
	if (!str_to_print)
		len_print = 6;
	else
		len_print = ft_strlen(str_to_print);
	i = 0;
	while (i < min_print - len_print)
		i += ft_printf(" ");
	return (i + ft_printf("%s", str_to_print));
}

int	print_var_minus(const char *str, va_list args)
{
	int	min_print;
	int	sum;

	str++;
	min_print = ft_atoi(str);
	while (!is_specifier_b(*str, 0))
		str++;
	sum = print_var(str, args);
	while (sum < min_print)
	{
		ft_putchar_fd(' ', 1);
		sum++;
	}
	return (sum);
}
