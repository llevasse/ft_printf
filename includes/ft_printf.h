/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:39:11 by llevasse          #+#    #+#             */
/*   Updated: 2022/12/07 12:14:28 by leo              ###   ########.fr       */
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
int		print_var(char c, va_list args);
void	ft_put_unsigned_nbr_fd(unsigned int n, int fd);
int		get_int_len(int n);
void	revert_char(char *str);
void	lower_str(char *str);
int		to_hex(int n, int uppercase);
int		to_address(long long n);

#endif