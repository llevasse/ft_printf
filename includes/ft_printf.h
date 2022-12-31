/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:39:11 by llevasse          #+#    #+#             */
/*   Updated: 2022/12/30 14:27:10 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "../libft/libft.h"

int		ft_printf(const char *string, ...);
int		ft_putstr(char *str, int with_free);
int		ft_putchar(char c);
int		print_var(char c, va_list args);
int		get_int_len(int n);
int		to_hex(int n, int uppercase);
int		to_hex_unsigned(unsigned int n, int uppercase);
int		to_address(unsigned long long n);
int		get_unsigned_len(unsigned int n);
int		is_specifier(char c);
char	*ft_itoa(int n);
char	*set_minus(char *s, int len);
char	*ft_itoa_unsigned(unsigned int n);
void	fill_res(char *res, int len_int, long n);
void	ft_strcat(char *dst, const char *src);
void	*ft_memset(void *b, int c, size_t len);
void	ft_put_unsigned_nbr_fd(unsigned int n, int fd);
void	revert_char(char *str);
void	lower_str(char *str);

#endif