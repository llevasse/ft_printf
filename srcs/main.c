/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:06:02 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/27 00:10:45 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	int		i;
	char	*s;
	int		var;
	char	*varstr;

	s = "%.4z";
	varstr = "coucou";
	var = 20;
	(void)var;
	ft_printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	ft_printf("\ntest for %s |", s);
	i = ft_printf(s, varstr);
	ft_printf("| (ft_printf : %i)\n", i);
	printf("test for %s |", s);
	i = printf(s, varstr);
	printf("| (printf : %i)\n", i);

	return (0);
}
