/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_field_min_and_minus.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:47:04 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/04 17:08:13 by llevasse         ###   ########.fr       */
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

	str_to_print = NULL;
	if (c == 's')
	{
		str_to_print = va_arg(args, char *);
		if (!str_to_print)
			str_to_print = "(null)";
	}
	if (c == 'c')
		str_to_print = get_char(va_arg(args, int));
	if (c == 'p')
		str_to_print = get_address(va_arg(args, unsigned long long));
	if (c == 'i' || c == 'd')
		str_to_print = ft_itoa(va_arg(args, int));
	if (c == 'u')
		str_to_print = ft_itoa_unsigned(va_arg(args, unsigned int));
	if (c == 'x')
		str_to_print = get_hex(va_arg(args, int), 0);
	if (c == 'X')
		str_to_print = get_hex(va_arg(args, int), 1);
	if ((c == 'i' || c == 'd' || c == 'u' || c == 'x' || c == 'X') && max_print)
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
	i = 0;
	if	(str_to_print && (str_to_print[0] != '\0' || c == 's'))
		len_print = ft_strlen(str_to_print);
	while (i < min_print - len_print)
		i += ft_printf(" ");
	if (c == '%')
		return (i + ft_printf("%%"));
	if (str_to_print[0] == 0 && c != 's')
		i++;
	i += ft_printf("%s", str_to_print);
	if (c == 's')
		return (i);
	return (free(str_to_print), i);
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
	while (ft_isdigit(*str))
		str++;
	str_to_print = return_str(*str, args, max_print);
	if (!str_to_print)
		return (0);
	i = 0;
	str_len = ft_strlen(str_to_print);
	if (*str != 's' && str_to_print[0] != '0')
		max_print = str_len;
	if (str_len <= max_print && *str == 's')
		max_print = str_len;
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
	while (ft_isdigit(*str))
		str++;
	str_to_print = return_str(*str, args, max_print);
	str_len = ft_strlen(str_to_print);
	if ((*str == 'i' || *str == 'd' || *str == 'u' || *str == 'x' || *str == 'X') && str_to_print[0] != '0')
		max_print = str_len;
	if (str_len < max_print && *str == 's')
		max_print = str_len;
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
