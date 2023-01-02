/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_field_min_and_minus.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:47:04 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/02 19:48:10 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

char	*return_str(char c, va_list args, int max_print)
{
	char	*str_to_print;
	char	*temp;
	int		strlen;
	int		i;
	int		j;

	if (c == 's')
	{
		str_to_print = va_arg(args, char *);
		if (!str_to_print)
			str_to_print = "(null)";
	}
	if (c == 'i' || c == 'd')
		str_to_print = ft_itoa(va_arg(args, int));
	if (c == 'u')
		str_to_print = ft_itoa_unsigned(va_arg(args, unsigned int));
	if ((c == 'i' || c == 'd' || c == 'u') && max_print)
	{
		strlen = ft_strlen(str_to_print);
		if (str_to_print[0] == '-')
			strlen--;
		if (strlen < max_print)
		{
			i = 0;
			j = 0;
			if (str_to_print[0] != '-')
				temp = malloc((max_print + 1) * sizeof(char));
			else
			{
				temp = malloc((max_print + 2) * sizeof(char));
				if (!temp)
					return (NULL);
				str_to_print = ft_itoa(ft_atoi(str_to_print) * -1);
				max_print++;
				temp[i++] = '-';
			}
			while (i < (max_print - strlen))
				temp[i++] = '0';
			while (i < max_print && *str_to_print)
				temp[i++] = str_to_print[j++];
			temp[i] = '\0';
			return (temp);
		}
	}
	return (str_to_print);
}

int	print_zeros(char *str, int max_print)
{
	int	i;
	int	str_len;

	i = 0;
	str_len = ft_strlen(str);
	if (str_len < max_print)
	{
		while (i < (max_print - str_len))
			i += ft_printf("0");
	}
	return (i);
}

int	print_var_field_minimum(char c, va_list args, int min_print)
{
	char	*str_to_print;
	int		i;
	int		len_print;

	len_print = 1;
	str_to_print = return_str(c, args, 0);
	if (!str_to_print)
		return (0);
	if (c == '%')
		return (ft_printf("%%"));
	i = 0;
	len_print = ft_strlen(str_to_print);
	while (i < min_print - len_print)
		i += ft_printf(" ");
	return (i + ft_printf("%s", str_to_print));
}

int	print_var_field_max(const char *str, va_list args, int min)
{
	char	*str_to_print;
	int		i;
	int		j;
	int		str_len;
	int		max_print;

	max_print = 0;
	if (ft_isdigit(*str))
		max_print = ft_atoi(str++);
	str_to_print = return_str(*str, args, max_print);
	if (!str_to_print)
		return (0);
	i = 0;
	str_len = ft_strlen(str_to_print);
	if ((*str == 'i' || *str == 'd' || *str == 'u') && str_to_print[0] != '0')
		max_print = str_len;
	if (str_len <= max_print && *str == 's')
		max_print = str_len;
	else if (!ft_strncmp("(null)", str_to_print, str_len))
		max_print = 0;
	while (i < (min - max_print))
		i += ft_printf(" ");
	j = 0;
	while (j < max_print && *str_to_print)
		j += ft_printf("%c", *str_to_print++);
	return (i + j);
}


int	print_var_field_max_left(const char *str, va_list args, int min)
{
	char	*str_to_print;
	int		i;
	int		str_len;
	int		max_print;

	max_print = 0;
	if (ft_isdigit(*str))
		max_print = ft_atoi(str++);
	str_to_print = return_str(*str, args, max_print);
	str_len = ft_strlen(str_to_print);
	if ((*str == 'i' || *str == 'd' || *str == 'u') && str_to_print[0] != '0')
		max_print = str_len;
	if (str_len < max_print && *str == 's')
		max_print = str_len;
	else if (!ft_strncmp("(null)", str_to_print, str_len))
		max_print = 0;
	i = 0;
	while (i < max_print && *str_to_print)
		i += ft_printf("%c", *str_to_print++);
	while (i < min)
		i += ft_printf(" ");
	return (i);
}

int	print_var_minus(const char *str, va_list args)
{
	int	min_print;
	int	sum;

	min_print = 0;
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
