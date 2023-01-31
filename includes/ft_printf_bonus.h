/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:39:11 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/28 15:45:30 by llevasse         ###   ########.fr       */
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

void	print_padding(const char *str, va_list args, char c, int *sum);

void	print_prec(const char *str, va_list args, int *sum);
void	print_padding_prec(const char *str, va_list args, char c, int *sum);
int		print_odd_prec(const char *str, va_list args, int *sum);

void	print_space(const char *str, va_list args, int *sum);

void	print_plus(const char *str, va_list args, int *sum);

void	print_field_width(const char *str, va_list args, int *sum);
void	print_width_prec(const char *str, va_list args, int width, int *sum);
int		predict_length_precision(const char *str, va_list args, int prec);
void	print_width_prec_s(char *str_to_print, int prec, int *sum);

int		predict_len(const char *str, va_list args);
int		get_size_base_u(unsigned long long n, const char *base);
int		get_size_base(int n, const char *base);
int		get_int_len(int n);
int		get_unsigned_len(unsigned int n);
int		print_odd(const char *str, va_list args, int *sum, int *padding);

int		check_priorities(const char *str, va_list args, int *sum);

#endif