/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:06:02 by llevasse          #+#    #+#             */
/*   Updated: 2023/02/08 17:03:08 by llevasse         ###   ########.fr       */
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


	s = "%---91.148s";
	varstr = NULL;
	var = -1355834522;
	(void)s;
	(void)var;	
	(void)varstr;
	ft_printf("\n\n\n\n\n\n\n\n\n\n");
	
	ft_printf("\ntest for %s |", s);
	i = ft_printf(s,"\nmD^8<.q*'\rD");
	ft_printf("| (ft_printf : %i)\n", i);
	printf("test for %s |", s);
	i = printf(s, "\nmD^8<.q*'\rD");
	printf("| (printf : %i)\n", i);

	return (0);
}
