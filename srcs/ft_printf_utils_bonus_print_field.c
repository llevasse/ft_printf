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

void	p_var_field_minimum(char c, va_list args, int min, int *sum)
{
	char	*str_to_print;
	int		i;
	int		len_print;

	len_print = 1;
	if (c == 's')
		len_print = 0;
	str_to_print = return_str(c, args, 0, 1);
	if (!str_to_print)
		return (end_ft_printf(sum));
	i = 0;
	if (str_to_print[0])
		len_print = ft_strlen(str_to_print);
	while (i++ < min - len_print)
		ft_putchar(' ', sum);
	if (!*str_to_print && c != 's')
		i++;
	if (c == 's' || (c == 'p' && str_to_print[0] == '('))
		ft_putstr(str_to_print, 0, sum);
	else
		ft_putstr(str_to_print, 1, sum);
}

void	p_field_max(const char *str, va_list args, int min, int *sum)
{
	char	*str_to_print;
	int		i;
	int		j;
	int		max;

	max = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	str_to_print = return_str(*str, args, max, 1);
	if (!str_to_print)
		return (end_ft_printf(sum));
	i = 0;
	if ((*str != 's') && is_specifier_b(*str, 0) && str_to_print[0] != '0')
		max = ft_strlen(str_to_print);
	if (ft_strlen(str_to_print) <= (size_t)max && *str == 's')
		max = ft_strlen(str_to_print);
	while (i++ < (min - max))
		ft_putchar(' ', sum);
	j = 0;
	while (j++ < max && *str_to_print)
		ft_putchar(*str_to_print++, sum);
	if (*str != 's')
		free(str_to_print - j);
}

void	p_f_max_left(const char *str, va_list args, int min, int *sum)
{
	char	*str_to_print;
	int		str_len;
	int		max;

	max = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	str_to_print = return_str(*str, args, max, 1);
	if (!str_to_print)
		return (end_ft_printf(sum));
	if (*str == 's')
		return (p_f_max_left_s(str_to_print, min, max, sum));
	str_len = ft_strlen(str_to_print);
	if ((*str != 's') && is_specifier_b(*str, 0) && str_to_print[0] != '0')
		max = str_len + 1;
	max += *sum;
	while (*sum < max && *str_to_print)
		ft_putchar(*str_to_print, sum);
	while (*sum < (min + max) - 1)
		ft_putchar(' ', sum);
	if (*str != 's' && max == 0)
		free(str_to_print);
	else if (*str != 's')
		free(str_to_print - str_len);
}

void	p_f_max_left_s(const char *str_to_print, int min, int max, int *sum)
{
	int		str_len;

	str_len = ft_strlen(str_to_print);
	if (str_len < max)
		max = str_len;
	max += *sum;
	min += *sum;
	while (*sum < max && *str_to_print)
		ft_putchar(*(str_to_print++), sum);
	while (*sum < min)
		ft_putchar(' ', sum);
}
