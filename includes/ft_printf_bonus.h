/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:39:11 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/01 16:11:33 by llevasse         ###   ########.fr       */
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
int		ft_putstr(char *str, int with_free);
int		ft_putchar(char c);

int		print_var_field_minimum(char c, va_list args, int min_print);
int		print_var_field_max(const char *str, va_list args, int max);
int		print_var_field_max_left(const char *str, va_list args, int min);
int		print_var_minus(const char *str, va_list args);

int		print_var_0(const char *str, va_list args);
int		print_var_0_d_or_i(va_list args, int min_print);
int		print_var_0_u(va_list args, int min_print);
int		print_var_0_hex(va_list args, int min_print, int uppercase);

int		print_var_dot(const char *str, va_list args);
int		print_var_dot_int(va_list args, int precision);
int		print_var_dot_s(va_list args, int precision);
int		print_var_dot_u(va_list args, int precision);
int		print_var_dot_hex(va_list args, int precision, int uppercase);

int		print_var_pound(const char *str, va_list args);

int		print_var_space_plus(const char *str, va_list args, char c);
int		print_var_space_plus_s(va_list args, int int_to_print);

int		print_var_bonus(const char *str, va_list args);
int		print_var(const char *str, va_list args);

int		get_int_len(int n);
int		to_hex(int n, int uppercase);
int		to_hex_unsigned(unsigned int n, int uppercase);
int		to_address(unsigned long long n);
int		get_unsigned_len(unsigned int n);
int		is_specifier_b(char c, int is_bonus);
int		ft_atoi(const char *str);
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

#endif