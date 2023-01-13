/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:51:01 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/13 11:39:18 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/ft_printf_bonus.h"

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

int	to_address(unsigned long long n)
{
	char	*res;
	char	*base;
	int		i;

	if (n == 0)
		return (ft_printf("0x0"));
	base = "0123456789abcdef";
	res = malloc(17 * sizeof(char));
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
	ft_putstr_fd("0x", 1);
	revert_char(res);
	ft_putstr_fd(res, 1);
	free (res);
	return (i + 2);
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

int	to_hex(int n, int uppercase)
{
	char	*res;
	char	*base;
	int		i;

	if (n < 0)
		return (to_hex_unsigned((unsigned)n, uppercase));
	base = "0123456789ABCDEF";
	res = malloc(get_int_len(n) * sizeof(char) + 1);
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
	revert_char(res);
	if (!uppercase)
		lower_str(res);
	i = ft_putstr(res, 1);
	return (i);
}

int	to_hex_unsigned(unsigned int n, int uppercase)
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
	ft_putstr_fd(res, 1);
	i = ft_strlen(res);
	free(res);
	return (i);
}

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
	revert_char(res);
	if (!uppercase)
		lower_str(res);
	return (res);
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
