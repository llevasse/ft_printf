/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rewrite_put_fd_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:34:15 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/24 11:17:38 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	ft_putstr(char *str, int with_free, int *sum)
{
	int	secure;

	secure = -1;
	if (!str && *sum != -1)
		secure = write(1, "(null)", 6);
	else if (str && *sum != -1)
		secure = write(1, str, ft_strlen(str));
/* 	if (str && *sum != -1 && str[0] == 0)
		*sum += 1; */
	if (with_free)
		free(str);
	if (secure == -1)
		*sum = -1;
	else
		*sum += secure;
}

void	ft_putchar(char c, int *sum)
{
	int	secure;

	secure = -1;
	if (*sum != -1)
		secure = (write(1, &c, 1));
	if (secure == -1)
		*sum = -1;
	else
		*sum += secure;
}
