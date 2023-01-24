/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_field_min_and_minus.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:50:11 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/24 16:08:51 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

char	*return_str(char c, va_list args, int max_print, int put_0)
{
	char	*str_to_print;

	str_to_print = NULL;
	if (c == '%')
		return (get_char('%'));
	if (c == 's')
	{
		str_to_print = va_arg(args, char *);
		if (!str_to_print)
			str_to_print = "(null)";
		return (str_to_print);
	}
	if (c == 'c')
		return (get_char(va_arg(args, int)));
	else if (is_specifier_b(c, 0))
		str_to_print = var_to_str(c, args);
	if (put_0)
		str_to_print = put_zeros(str_to_print, max_print);
	return (str_to_print);
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
	int			i;
	long long	tempnbr;
	int			strlen;
	char		*temp;

	if (ft_strncmp(str_to_print, "-2147483648", ft_strlen(str_to_print)))
		tempnbr = ft_atoi(str_to_print);
	else
		tempnbr = 2147483648;
	free (str_to_print);
	str_to_print = ft_itoa_unsigned(tempnbr * -1);
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

void	p_var_minus(const char *str, va_list args, int *sum)
{
	int	min;

	min = 0;
	if (ft_isdigit(*str))
	{
		min = ft_atoi(str);
		while (!is_specifier_b(*str, 0))
		{
			if (*str++ == '.')
				return (p_f_max_left(str, args, min, sum));
		}
	}
	min += *sum;
	p_var(str, args, sum);
	while (*sum < min)
		ft_putchar(' ', sum);
}
