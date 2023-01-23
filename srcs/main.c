/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:06:02 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/23 16:19:44 by llevasse         ###   ########.fr       */
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

	(void)argc;
	(void)argv;
	s = " %-2c";
	varstr = "";
	var = '0';
	ft_printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	ft_printf("test for %s |", s);
	i = ft_printf(" %-1c %-2c %-3c ", '0', 0, '1');
	ft_printf("| (ft_printf : %i)\n", i);
	printf("test for %s |", s);
	i = printf(" %-1c %-2c %-3c ", '0', 0, '1');
	printf("| (printf : %i)\n", i);
	return (0);
}
