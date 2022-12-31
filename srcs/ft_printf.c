/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:33:53 by llevasse          #+#    #+#             */
/*   Updated: 2022/12/30 14:36:44 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *string, ...)
{
	va_list		args;
	int			i;

	va_start(args, string);
	i = 0;
	while (*string)
	{
		while (*string != '%' && *string)
		{
			ft_putchar_fd(*string, 1);
			string++;
			i++;
		}
		if (*string == '%')
		{
			string++;
			while (!is_specifier(*string))
				string++;
			i += print_var(*string, args);
		}
		if (*string)
			string++;
	}
	va_end(args);
	return (i);
}

int	print_var(char c, va_list args)
{
	if (c == '%')
		return (ft_printf("%c", '%'));
	else if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *), 0));
	else if (c == 'd' || c == 'i')
		return (ft_putstr(ft_itoa(va_arg(args, int)), 1));
	else if (c == 'u')
		return (ft_putstr(ft_itoa_unsigned(va_arg(args, int)), 1));
	else if (c == 'x')
		return (to_hex(va_arg(args, int), 0));
	else if (c == 'X')
		return (to_hex(va_arg(args, int), 1));
	else if (c == 'p')
		return (to_address(va_arg(args, unsigned long long)));
	return (0);
}

int	is_specifier(char c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'd' || c == 'i' \
	|| c == 'u' || c == 'x' || c == 'X' || c == 'p')
		return (1);
	return (0);
}
