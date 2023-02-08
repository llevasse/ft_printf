/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:06:02 by llevasse          #+#    #+#             */
/*   Updated: 2023/02/08 14:39:17 by llevasse         ###   ########.fr       */
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

	s = "%08.5i";
	varstr = NULL;
	var = 34;
	(void)s;
	(void)var;	
	(void)varstr;
	ft_printf("\n\n\n\n\n\n\n\n\n\n");
	ft_printf("\ntest for %s |", s);
	i = ft_printf(s, var);
	ft_printf("| (ft_printf : %i)\n", i);
	printf("test for %s |", s);
	i = printf(s, var);
	printf("| (printf : %i)\n", i);

	s = "%010.5i";
	var = -216;
	ft_printf("\ntest for %s |", s);
	i = ft_printf(s, var);
	ft_printf("| (ft_printf : %i)\n", i);
	printf("test for %s |", s);
	i = printf(s, var);
	printf("| (printf : %i)\n", i);

	s = "%.0u";
	var = 0;
	ft_printf("\ntest for %s |", s);
	i = ft_printf(s, var);
	ft_printf("| (ft_printf : %i)\n", i);
	printf("test for %s |", s);
	i = printf(s, var);
	printf("| (printf : %i)\n", i);

	return (0);
}
