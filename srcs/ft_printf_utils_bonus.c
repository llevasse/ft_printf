/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:51:01 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/23 14:38:17 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

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

	res = malloc((get_size_base_u(n, base) + 1) * sizeof(char));
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

unsigned int	get_size_base_u(unsigned long long n, const char *base)
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

void	end_ft_printf(int *sum)
{
	*sum = -1;
}
