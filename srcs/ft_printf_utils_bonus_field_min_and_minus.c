/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_field_min_and_minus.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:50:11 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/17 12:59:20 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

char	*return_str(char c, va_list args, int max_print)
{
	char	*str_to_print;

	str_to_print = NULL;
	if (c == 's')
	{
		str_to_print = va_arg(args, char *);
		if (!str_to_print)
			str_to_print = "(null)";
		return (str_to_print);
	}
	if (c == '%')
		str_to_print = get_char('%');
	if (c == 'c')
		return (get_char(va_arg(args, int)));
	if (c == 'i' || c == 'd')
		str_to_print = ft_itoa(va_arg(args, int));
	if (c == 'u')
		str_to_print = ft_itoa_unsigned(va_arg(args, unsigned int));
	if (c == 'x')
		str_to_print = get_hex(va_arg(args, int), 0);
	if (c == 'X')
		str_to_print = get_hex(va_arg(args, int), 1);
	if (c == 'p')
		str_to_print = get_address(va_arg(args, unsigned long long));
	return (put_zeros(str_to_print, max_print));
}

char	*put_zeros(char *str_to_print, int max_print)
{
	int		i;
	int		strlen;
	char	*temp;

	strlen = ft_strlen(str_to_print);
	if (str_to_print[0] == '-')
		strlen--;
	if (strlen >= max_print)
		return (str_to_print);
	if (str_to_print[0] == '-')
		return (put_zeros_neg(str_to_print, max_print + 1));
	i = 0;
	temp = malloc((max_print + 1) * sizeof(char));
	if (!temp)
		return (free(str_to_print), NULL);
	while (i < (max_print - strlen))
		temp[i++] = '0';
	while (i < max_print && *str_to_print)
		temp[i++] = *str_to_print++;
	temp[i] = '\0';
	return (free(str_to_print - strlen), temp);
}

char	*put_zeros_neg(char *str_to_print, int max_print)
{
	int		i;
	int		strlen;
	char	*temp;

	str_to_print = ft_itoa(ft_atoi(str_to_print) * -1);
	strlen = ft_strlen(str_to_print);
	i = 0;
	temp = malloc((max_print + 1) * sizeof(char));
	if (!temp)
		return (free(str_to_print), NULL);
	temp[i++] = '-';
	while (i < (max_print - strlen))
		temp[i++] = '0';
	while (i < max_print && *str_to_print)
		temp[i++] = *str_to_print++;
	temp[i] = '\0';
	return (free(str_to_print - strlen), str_to_print = NULL, temp);
}

void	del_minus_from_char(char *str)
{
	int	i;

	i = 0;
	while (str[i++] != 0)
		str[i - 1] = str[i];
	str[i - 1] = 0;
}

int	p_var_minus(const char *str, va_list args)
{
	int	min_print;
	int	sum;

	min_print = 0;
	if (ft_isdigit(*str))
	{
		min_print = ft_atoi(str);
		while (!is_specifier_b(*str, 0))
		{
			if (*str++ == '.')
				return (p_field_max_left(str, args, min_print, ft_atoi(str)));
		}
	}
	sum = p_var(str, args);
	while (sum < min_print)
	{
		ft_putchar_fd(' ', 1);
		sum++;
	}
	return (sum);
}
