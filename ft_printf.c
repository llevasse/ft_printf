/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:33:53 by llevasse          #+#    #+#             */
/*   Updated: 2022/12/04 18:50:58 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf(const char *string, ...)
{
	const char	*to_print_str;
	va_list		args;

	va_start(args, string);
	to_print_str = string;
	while (*to_print_str)
	{
		while (*to_print_str != '%' && *to_print_str)
		{
			ft_putchar_fd(*to_print_str, 1);
			to_print_str++;
		}
		if (*to_print_str == '%')
		{
			to_print_str++;
			print_var(*to_print_str, args);
		}
		to_print_str++;
	}
	va_end(args);
	return (1);
}

void	print_var(char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd((char *) va_arg(args, char *), 1);
}

int main()
{
	ft_printf("sss%cscs%s", 'c', "Coucou");
}




/* void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
 */