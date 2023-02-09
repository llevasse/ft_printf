/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:06:02 by llevasse          #+#    #+#             */
/*   Updated: 2023/02/09 16:08:06 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int	main(int argc, char *argv[])
{
	int		i;
	char	*s;
	int		var;
	char	*varstr;

	s = " %01x ";
	varstr = "yolo";
	var = 0;
	ft_printf("\n\n\n\n\n\n\n\n\n\n");
	ft_printf("\ntest for %s |", s);
	i = ft_printf(" %014d %015d", 0, -42);
	ft_printf("| (ft_printf : %i)\n", i);
	printf("test for %s |", s);
	i = printf(" %014d %015d", 0, -42);
	printf("| (printf : %i)\n", i);
	(void)argc;
	(void)argv;
	(void)s;
	(void)var;
	(void)varstr;
	return (0);
}
