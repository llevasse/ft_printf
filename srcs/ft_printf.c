/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:33:53 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/21 14:42:55 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *string, ...)
{
	va_list		args;
	int			i;

	if (!string)
		return (-1);
	va_start(args, string);
	i = 0;
	while (*string && i != -1)
	{
		while (*string != '%' && *string)
			ft_putchar(*string++, &i);
		if (*string == '%')
		{
			string++;
			if (*string)
				print_var(*string, args, &i);
			else
				i = -1;
		}
		if (*string)
			string++;
	}
	return (va_end(args), i);
}

void	print_var(char c, va_list args, int *sum)
{
	unsigned long long	address;

	if (c == '%')
		return (ft_putchar('%', sum));
	else if (c == 'c')
		return (ft_putchar(va_arg(args, int), sum));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *), sum));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int), sum));
	else if (c == 'u')
		return (ft_putnbr(va_arg(args, unsigned int), sum));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(args, int), "0123456789abcdef", sum));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", sum));
	else if (c == 'p')
	{
		address = va_arg(args, unsigned long long);
		if (!address)
			return (ft_putstr("(nil)", sum));
		ft_putstr("0x", sum);
		return (ft_putnbr_base_u(address, "0123456789abcdef", sum));
	}
	return ((void)(ft_putchar('%', sum), ft_putchar(c, sum)));
}

int	is_specifier(char c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'd' || c == 'i' \
	|| c == 'u' || c == 'x' || c == 'X' || c == 'p')
		return (1);
	return (0);
}
