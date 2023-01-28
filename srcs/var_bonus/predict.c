/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:42:42 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/28 10:55:11 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

int	predict_len(const char *str, va_list args)
{
	va_list	args_cp;
	char	*base;

	base = "0123456789abcdef";
	va_copy(args_cp, args);
	if (*str == 'c' || *str == '%')
		return (1);
	if (*str == 's')
		return (ft_strlen(va_arg(args_cp, char *)));
	if (*str == 'd' || *str == 'i')
		return (get_int_len(va_arg(args_cp, int)));
	if (*str == 'u')
		return (get_unsigned_len(va_arg(args_cp, unsigned int)));
	if (*str == 'x' || *str == 'X')
		return (get_size_base(va_arg(args_cp, int), base));
	if (*str == 'p')
		return (get_size_base_u(va_arg(args_cp, unsigned long long), base));
	return (0);
}

int	get_size_base(int n, const char *base)
{
	int	str_len;
	int	i;

	i = 0;
	str_len = ft_strlen(base);
	if (n < 0)
		return (get_size_base_u((unsigned) n, base));
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n /= str_len;
		i++;
	}
	return (i);
}

int	get_size_base_u(unsigned long long n, const char *base)
{
	int				str_len;
	unsigned int	i;

	i = 0;
	str_len = ft_strlen(base);
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n /= str_len;
		i++;
	}
	return (i);
}

int	get_int_len(int n)
{
	if (n < 0)
		return (1 + get_int_len(n * -1));
	if (n < 10)
		return (1);
	return (1 + get_int_len(n / 10));
}

int	get_unsigned_len(unsigned int n)
{
	if (n < 10)
		return (1);
	return (1 + get_unsigned_len(n / 10));
}
