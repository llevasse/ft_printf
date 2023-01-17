/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_p_field.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:31:54 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/17 12:00:11 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	p_var_field_minimum(char c, va_list args, int min_print)
{
	char	*str_to_print;
	int		i;
	int		len_print;

	len_print = 1;
	if (c == 's')
		len_print = 0;
	str_to_print = return_str(c, args, 0);
	if (!str_to_print)
		return (0);
	i = 0;
	if (str_to_print[0])
		len_print = ft_strlen(str_to_print);
	while (i < min_print - len_print)
		i += ft_printf(" ");
	if (!*str_to_print && c != 's')
		i++;
	i += ft_printf("%s", str_to_print);
	if (c == 's' || (c == 'p' && str_to_print[0] == '('))
		return (i);
	return (free(str_to_print), i);
}

int	p_field_max(const char *str, va_list args, int min, int max_print)
{
	char	*str_to_print;
	int		i;
	int		j;
	int		str_len;

	while (ft_isdigit(*str))
		str++;
	str_to_print = return_str(*str, args, max_print);
	if (!str_to_print)
		return (0);
	i = 0;
	str_len = ft_strlen(str_to_print);
	if ((*str != 's') && is_specifier_b(*str, 0) && str_to_print[0] != '0')
		max_print = str_len;
	if (str_len <= max_print && *str == 's')
		max_print = str_len;
	while (i < (min - max_print))
		i += ft_printf(" ");
	j = 0;
	while (j < max_print && *str_to_print)
		j += ft_printf("%c", *str_to_print++);
	if (*str != 's')
		free(str_to_print - j);
	return (i + j);
}

int	p_field_max_left(const char *str, va_list args, int min, int max_print)
{
	char	*str_to_print;
	int		i;
	int		str_len;

	while (ft_isdigit(*str))
		str++;
	str_to_print = return_str(*str, args, max_print);
	if (!str_to_print)
		return (0);
	str_len = ft_strlen(str_to_print);
	if ((*str != 's') && is_specifier_b(*str, 0) && str_to_print[0] != '0')
		max_print = str_len + 1;
	if (str_len < max_print && *str == 's')
		max_print = str_len;
	i = 0;
	while (i < max_print && *str_to_print)
		i += ft_printf("%c", *str_to_print++);
	while (i < min)
		i += ft_printf(" ");
	if (*str != 's' && max_print == 0)
		free(str_to_print);
	else if (*str != 's')
		free(str_to_print - str_len);
	return (i);
}

int	p_var_field_maximum_left(const char *str, va_list args, int max_print)
{
	char	*str_to_print;
	int		i;
	int		str_len;
	int		len_print;

	len_print = ft_atoi(str++);
	str_len = 0;
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
