/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:39:11 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/26 13:49:36 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "../libft/libft.h"

int		ft_printf(const char *string, ...);
void	ft_putstr(char *str, int *sum);
void	ft_putchar(char c, int *sum);
void	ft_putnbr(long long n, int *sum);
void	ft_putnbr_base(int n, const char *base, int *sum);
void	ft_putnbr_base_u(unsigned long long n, const char *base, int *sum);
void	print_var(const char *str, va_list args, int *sum);
void	print_var_bonus(const char *str, va_list args, int *sum);
int		is_specifier(char c, int bonus);

void	print_pound(const char *str, va_list args, int *sum);

void	print_minus(const char *str, va_list args, int *sum);

#endif