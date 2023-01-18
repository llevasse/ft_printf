/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:33:53 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/18 12:31:05 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *string, ...)
{
	va_list		args;
	int			i;

	va_start(args, string);
	i = 0;
	while (*string && i != -1)
	{
		while (*string != '%' && *string)
		{
			ft_putchar(*string, &i);
			string++;
		}
		if (*string == '%')
		{
			string++;
			while (!is_specifier(*string))
				string++;
			print_var(*string, args, &i);
		}
		if (*string)
			string++;
	}
	va_end(args);
	return (i);
}

void	print_var(char c, va_list args, int *sum)
{
	char	*str;

	str = NULL;
	if (c == '%')
		return (ft_putchar('%', sum));
	else if (c == 'c')
		return (ft_putchar(va_arg(args, int), sum));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *), 0, sum));
	else if (c == 'd' || c == 'i')
		str = (ft_itoa(va_arg(args, int)));
	else if (c == 'u')
		str = (ft_itoa_unsigned(va_arg(args, int)));
	else if (c == 'x')
		str = to_base(va_arg(args, int), "0123456789abcdef");
	else if (c == 'X')
		str = to_base(va_arg(args, int), "0123456789ABCDEF");
	else if (c == 'p')
	{
		ft_putstr("0x", 0, sum);
		str = to_base_u(va_arg(args, unsigned long long), "0123456789abcdef");
	}
	if (!str)
		*sum = -1;
	ft_putstr(str, 1, sum);
}

int	is_specifier(char c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'd' || c == 'i' \
	|| c == 'u' || c == 'x' || c == 'X' || c == 'p')
		return (1);
	return (0);
}
