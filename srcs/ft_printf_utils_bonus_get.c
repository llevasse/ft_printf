/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_get.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:42:19 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/17 10:43:29 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

char	*get_hex(int n, int uppercase)
{
	char	*res;
	char	*base;
	int		i;

	if (n < 0)
		return (get_hex_unsigned((unsigned) n, uppercase));
	base = "0123456789ABCDEF";
	res = malloc(get_int_len(n) * sizeof(char) + 1);
	if (!res)
		return (0);
	i = 0;
	res[0] = '0';
	res[1] = '\0';
	if (n == 0)
		return (res);
	while (n > 0)
	{
		res[i] = base[n % 16];
		n = n / 16;
		i++;
	}
	res[i] = 0;
	if (!uppercase)
		lower_str(res);
	return (revert_char(res), res);
}

char	*get_hex_unsigned(unsigned int n, int uppercase)
{
	char	*res;
	char	*base;
	int		i;

	base = "0123456789ABCDEF";
	res = malloc(get_unsigned_len(n) * sizeof(char) + 1);
	if (!res)
		return (0);
	i = 0;
	while (n > 0)
	{
		res[i] = base[n % 16];
		n = n / 16;
		i++;
	}
	res[i] = 0;
	revert_char(res);
	if (!uppercase)
		lower_str(res);
	return (res);
}

char	*get_address(unsigned long long n)
{
	char	*res;
	char	*base;
	int		i;

	base = "0123456789abcdef";
	res = malloc(19 * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	if (n == 0)
		res[i++] = '0';
	while (n > 0)
	{
		res[i] = base[n % 16];
		n = n / 16;
		i++;
	}
	res[i] = 0;
	ft_strcat(res, "x0");
	revert_char(res);
	return (res);
}

char	*get_char(int c)
{
	char	*res;

	res = malloc(2 * sizeof(char));
	if (!res)
		return (NULL);
	if (c == 0)
	{
		res[0] = 0;
		return (res);
	}
	res[0] = c;
	res[1] = 0;
	return (res);
}
