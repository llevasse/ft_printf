/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:39:11 by llevasse          #+#    #+#             */
/*   Updated: 2022/12/16 08:09:03 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "../libft/libft.h"

# define INT_MAX INT32_MAX
# define INT_MIN -INT32_MAX-1
# define LONG_MAX __LONG_MAX__
# define LONG_MIN -__LONG_MAX__-1L
# define UINT_MAX INT32_MAX*2U+1U
# define ULONG_MAX __LONG_MAX__*2UL+1UL

int		ft_printf(const char *string, ...);
int		print_var(char c, va_list args);
void	ft_put_unsigned_nbr_fd(unsigned int n, int fd);
int		get_len_int(int n);
void	revert_char(char *str);
void	lower_str(char *str);
int		to_hex(int n, int uppercase);
int		to_hex_unsigned(unsigned int n, int uppercase);
int		to_address(unsigned long long n);
char	*ft_itoa(int n);
void	fill_res(char *res, int len_int, long n);
char	*set_minus(char *s, int len);
void	ft_strcat(char *dst, const char *src);
void	*ft_memset(void *b, int c, size_t len);
int		get_unsigned_len(unsigned int n);
char	*ft_itoa_unsigned(unsigned int n);

#endif