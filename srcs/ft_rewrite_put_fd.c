/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rewrite_put_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:17:45 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/18 10:22:46 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstr(char *str, int with_free, int *sum)
{
	int	secure;

	secure = -1;
	if (!str && *sum != -1)
		secure = write(1, "(null)", 6);
	else if (str && *sum != -1)
		secure = write(1, str, ft_strlen(str));
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
