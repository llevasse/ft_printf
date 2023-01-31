/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:06:02 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/31 14:01:31 by llevasse         ###   ########.fr       */
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

	s = "%-1c";
	varstr = "0";
	var = '0';
	(void)s;
	(void)var;	
	(void)varstr;
	ft_printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	ft_printf("\ntest for %s |", s);
	i = ft_printf("%1.s, %1.s, %1.s, %1.s", (char *)NULL, "", "test", 
"joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6");
	ft_printf("| (ft_printf : %i)\n", i);
	printf("test for %s |", s);
	i = printf("%1.s, %1.s, %1.s, %1.s", (char *)NULL, "", "test", 
"joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6");
	printf("| (printf : %i)\n", i);

	return (0);
}
