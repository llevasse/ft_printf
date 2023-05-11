/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:20:39 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/11 16:34:54 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	i;

	i = ft_printf("%");
	ft_printf("(i : %i)\n", i);
	i = printf("%");
	printf("(i : %i)\n", i);
}
