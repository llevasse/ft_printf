/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rewrite_put_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:17:45 by llevasse          #+#    #+#             */
/*   Updated: 2022/12/30 14:14:35 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
