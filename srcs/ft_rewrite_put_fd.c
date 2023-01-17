/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rewrite_put_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:17:45 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/17 15:42:04 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr(char *str, int with_free)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = write(1, str, ft_strlen(str));
	if (with_free)
		return (free(str), i);
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
