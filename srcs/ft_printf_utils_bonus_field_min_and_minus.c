/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_field_min_and_minus.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:47:04 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/01 00:41:04 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	print_var_field_minimum(char c, va_list args, int min_print)
{
	char	*str_to_print;
	int		i;
	int		len_print;

	len_print = 1;
	if (c == 's')
	{
		str_to_print = va_arg(args, char *);
		if (!str_to_print)
			len_print = 6;
		else
			len_print = ft_strlen(str_to_print);
	}
	if (c == '%')
		return (ft_printf("%%"));
	i = 0;
	while (i < min_print - len_print)
		i += ft_printf(" ");
	return (i + ft_printf("%s", str_to_print));
}

int	print_var_field_max(const char *str, va_list args, int max)
{
	char	*str_to_print;
	int		i;
	int		str_len;
	int		len_print;

	len_print = ft_atoi(str++);
	if (*str == 's')
	{
		str_to_print = va_arg(args, char *);
		if (!str_to_print)
			str_len = 6;
		else
			str_len = ft_strlen(str_to_print);
	}
	if (str_len < len_print)
		len_print = str_len;
	i = 0;
	while (i < (max - len_print))
		i += ft_printf(" ");
	while (i < max && *str_to_print)
		i += ft_printf("%c", *str_to_print++);
	return (i);
}

int	print_var_field_max_left(const char *str, va_list args, int max)
{
	char	*str_to_print;
	int		i;
	int		str_len;
	int		len_print;

	len_print = ft_atoi(str++);
	if (*str == 's')
	{
		str_to_print = va_arg(args, char *);
		if (!str_to_print)
			str_len = 6;
		else
			str_len = ft_strlen(str_to_print);
	}
	if (str_len < len_print)
		len_print = str_len;
	i = 0;
	while (i < len_print && *str_to_print)
		i += ft_printf("%c", *str_to_print++);
	while (i < max)
		i += ft_printf(" ");
	return (i);
}


int	print_var_minus(const char *str, va_list args)
{
	int	min_print;
	int	sum;

	if (ft_isdigit(*str))
	{
		min_print = ft_atoi(str);
		while (!is_specifier_b(*str, 0))
		{
			if (*str == '.')
				return (print_var_field_max_left(str + 1, args, min_print));
			str++;
		}
	}
	else
		min_print = 0;
	if (*str == '%')
		return (ft_printf("%%"));
	sum = print_var(str, args);
	while (sum < min_print)
	{
		ft_putchar_fd(' ', 1);
		sum++;
	}
	return (sum);
}



int	print_var_field_maximum_left(const char *str, va_list args, int max_print)
{
	char	*str_to_print;
	int		i;
	int		str_len;
	int		len_print;

	len_print = ft_atoi(str++);
	if (*str == 's')
	{
		str_to_print = va_arg(args, char *);
		if (!str_to_print)
			str_len = 6;
		else
			str_len = ft_strlen(str_to_print);
	}
	if (str_len < len_print)
		len_print = str_len;
	i = 0;
	while (i < (max_print - len_print))
		i += ft_printf(" ");
	while (i < max_print && *str_to_print)
		i += ft_printf("%c", *str_to_print++);
	return (i);
}
