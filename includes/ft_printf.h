/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:39:11 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/23 14:39:05 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "../libft/libft.h"

int				ft_printf(const char *string, ...);
void			ft_putstr(char *str, int with_free, int *sum);
void			ft_putchar(char c, int *sum);
void			print_var(char c, va_list args, int *sum);
int				get_int_len(int n);
void			to_hex(int n, int uppercase, int *sum);
void			to_hex_unsigned(unsigned int n, int uppercase, int *sum);
void			to_address(unsigned long long n, int *sum);
int				get_unsigned_len(unsigned int n);
int				is_specifier(char c);
char			*ft_itoa(int n);
char			*set_minus(char *s, int len);
char			*ft_itoa_unsigned(unsigned int n);
void			fill_res(char *res, int len_int, long n);
void			ft_strcat(char *dst, const char *src);
void			*ft_memset(void *b, int c, size_t len);
void			ft_put_unsigned_nbr_fd(unsigned int n, int fd);
void			revert_char(char *str);
void			lower_str(char *str);

char			*to_base(int n, const char *base);
char			*to_base_u(unsigned long long n, const char *base);
int				get_size_base(int n, const char *base);
unsigned int	get_size_base_unsigned(unsigned long long n, const char *base);

#endif