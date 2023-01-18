/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:07:27 by levasse           #+#    #+#             */
/*   Updated: 2023/01/18 12:28:46 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*to_base(int n, const char *base)
{
	char	*res;
	int		i;

	if (n < 0)
		return (to_base_u((unsigned) n, base));
	res = malloc((get_size_base(n, base) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	if (n == 0)
		res[i++] = base[0];
	while (n > 0)
	{
		res[i++] = base[n % ft_strlen(base)];
		n = n / ft_strlen(base);
	}
	res[i] = 0;
	revert_char(res);
	return (res);
}

char	*to_base_u(unsigned long long n, const char *base)
{
	int		i;
	char	*res;

	res = malloc((get_size_base_unsigned(n, base) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	if (n == 0)
		res[i++] = base[0];
	while (n > 0)
	{
		res[i++] = base[n % ft_strlen(base)];
		n = n / ft_strlen(base);
	}
	res[i] = 0;
	revert_char(res);
	return (res);
}

int	get_size_base(int n, const char *base)
{
	int	str_len;
	int	i;

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

unsigned int	get_size_base_unsigned(unsigned long long n, const char *base)
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

void	revert_char(char *str)
{
	int		len;
	int		i;
	char	temp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}
