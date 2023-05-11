/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:20:39 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/11 17:35:48 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf_bonus.h"
#include <stdio.h>

int	main(void)
{
	int	i;

	i = ft_printf("ddd %kkkkk");
	ft_printf("(i : %i)\n", i);
	i = printf("ddd %kkkkk");
	printf("(i : %i)\n", i);
}
