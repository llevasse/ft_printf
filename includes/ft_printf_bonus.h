/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:39:11 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/20 15:16:28 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "../libft/libft.h"

void	ft_putstr(char *str, int with_free, int *sum);
void	ft_putchar(char c, int *sum);
void	p_var(const char *str, va_list args, int *sum);

int		ft_printf(const char *string, ...);

void	p_var_field_minimum(char c, va_list args, int min_print, int *sum);
void	p_field_max(const char *str, va_list args, int min, int *sum);
void	p_f_max_left(const char *str, va_list args, int min, int *sum);
void	p_var_minus(const char *str, va_list args, int *sum);
char	*put_zeros(char *str_to_print, int max_print);
char	*put_zeros_neg(char *str_to_print, int max_print);

int		p_var_0_pound(int min_print, int *sum);
int		p_var_0(const char *str, va_list args, int *sum);
int		p_var_0_d_or_i(va_list args, int min_print);
int		p_var_0_u(va_list args, int min_print);
int		p_var_0_hex(va_list args, int min_print, int uppercase);

void	p_var_dot(const char *str, va_list args, int *sum);
void	p_var_dot_int(va_list args, int precision, int *sum);
void	p_var_dot_s(va_list args, int precision, int *sum);
void	p_var_dot_u(va_list args, int precision, int *sum);
void	p_var_dot_hex(va_list args, int precision, const char *base, int *sum);

void	p_var_pound(const char *str, va_list args, int *sum);

void	p_var_space_plus(const char *str, va_list args, char c, int *sum);
void	p_var_space_plus_s(va_list args, int int_to_print, int *sum);

void	p_var_bonus(const char *str, va_list args, int *sum);

int		get_int_len(int n);
int		to_hex(int n, int uppercase);
int		to_hex_unsigned(unsigned int n, int uppercase);
int		to_address(unsigned long long n);
int		get_unsigned_len(unsigned int n);
int		is_specifier_b(char c, int is_bonus);
int		ft_atoi(const char *str);
void	del_minus_from_char(char *str);
void	ft_put_unsigned_nbr_fd(unsigned int n, int fd);
void	revert_char(char *str);
void	lower_str(char *str);
void	fill_res(char *res, int len_int, long n);
void	ft_strcat(char *dst, const char *src);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_itoa_unsigned(unsigned int n);
char	*ft_itoa(int n);
char	*set_minus(char *s, int len);
char	*get_hex(int n, int uppercase);
char	*get_hex_unsigned(unsigned int n, int uppercase);
char	*get_address(unsigned long long n);
char	*get_char(int c);
char	*return_str(char c, va_list args, int max_print);

char	*var_to_str(char c, va_list args, int *sum);
char	*to_base(int n, const char *base);

#endif