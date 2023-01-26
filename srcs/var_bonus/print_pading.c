/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:44:31 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/26 17:56:12 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

void	print_pading(const char *str, va_list args, char c, int *sum)
{
	int		var_len;
	int		int_to_print;
	int		pading_len;
	char	*base;

	base = "0123456789abcdef";
	pading_len = ft_atoi(str);
	while (!is_specifier(*str, 0))
		str++;
	var_len = print_odd(str, args, sum, &pading_len);
	while (pading_len-- - var_len > 0)
		ft_putchar(c, sum);
	if (*str == 'p')
		return (ft_putnbr_base_u(va_arg(args, unsigned long long), base, sum));
	if (*str == 'd' || *str == 'i')
	{
		int_to_print = va_arg(args, int);
		if (int_to_print < 0)
			int_to_print *= -1;
		return (ft_putnbr(int_to_print, sum));
	}
	print_var(str, args, sum);
}

int	print_odd(const char *str, va_list args, int *sum, int *padding)
{
	va_list	args_cp;
	int		var_len;
	int		int_to_print;

	va_copy(args_cp, args);
	var_len = predict_len(str, args);
	if (*str == 'p')
	{
		*padding -= 2;
		ft_putstr("0x", sum);
	}
	if (*str == 'd' || *str == 'i')
	{
		int_to_print = va_arg(args_cp, int);
		if (int_to_print < 0)
		{
			*padding -= 1;
			var_len--;
			ft_putchar('-', sum);
			int_to_print *= -1;
		}
	}
	return (var_len);
}
