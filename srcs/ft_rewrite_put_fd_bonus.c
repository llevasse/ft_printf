/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rewrite_put_fd_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:34:15 by llevasse          #+#    #+#             */
/*   Updated: 2022/12/30 14:13:39 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	ft_putstr(char *str, int with_free)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = ft_strlen(str);
	write(1, str, i);
	if (with_free)
		return (free(str), i);
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
