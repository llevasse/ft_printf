# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 15:18:30 by llevasse          #+#    #+#              #
#    Updated: 2023/03/03 10:31:34 by llevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS		=	-Wall -Wextra -Werror

FILES		= 	srcs/ft_printf.c \
				srcs/ft_printf_utils.c 

BONUS_FILES	= 	srcs/ft_printf_bonus.c						\
				srcs/ft_printf_utils_bonus.c				\
				srcs/var_bonus/predict_bonus.c				\
				srcs/var_bonus/print_minus_bonus.c			\
				srcs/var_bonus/print_pound_bonus.c			\
				srcs/var_bonus/print_padding_bonus.c		\
				srcs/var_bonus/print_precision_bonus.c		\
				srcs/var_bonus/print_space_bonus.c			\
				srcs/var_bonus/print_plus_bonus.c			\
				srcs/var_bonus/priorities_bonus.c			\
				srcs/var_bonus/print_field_width_bonus.c	\
				srcs/var_bonus/field_width_utils_bonus.c	\
				srcs/var_bonus/get_details_bonus.c			\
				
OBJS		= ${FILES:.c=.o}

OBJS_BONUS	= ${BONUS_FILES:.c=.o}

NAME		= libftprintf.a

%.o: %.c
				gcc ${FLAGS} -I includes -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} includes/ft_printf.h Makefile
				make -C libft
				ar rcs ${NAME} libft/libft.a ${OBJS}

bonus:		${OBJS_BONUS} includes/ft_printf_bonus.h Makefile
				make -C libft
				ar rcs ${NAME} libft/libft.a ${OBJS_BONUS}

all:		${NAME}

clean:
				make -C libft clean
				rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean
				rm -f libft/libft.a
				rm -f ${NAME}

re:			fclean all

.PHONY:		all	clean	fclean	re bonus
