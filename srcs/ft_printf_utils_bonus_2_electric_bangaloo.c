/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_2_electric_bangaloo.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:39:10 by llevasse          #+#    #+#             */
/*   Updated: 2022/12/29 15:40:20 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	lower_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
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

void	ft_put_unsigned_nbr_fd(unsigned int n, int fd)
{
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_put_unsigned_nbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

int	get_unsigned_len(unsigned int n)
{
	if (n < 10)
		return (1);
	return (1 + get_unsigned_len(n / 10));
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char	*res;
	int		len_int;

	len_int = get_unsigned_len(n);
	res = malloc((len_int + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len_int] = '\0';
	fill_res(res, len_int, n);
	return (res);
}
