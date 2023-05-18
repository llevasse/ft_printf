# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 15:18:30 by llevasse          #+#    #+#              #
#    Updated: 2023/05/18 11:47:33 by llevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS		:=	-Wall -Wextra -Werror

FILES		:= 	srcs/ft_printf.c \
				srcs/ft_printf_utils.c 

BONUS_FILES	:= 	srcs/ft_printf_bonus.c					\
				srcs/ft_printf_utils_bonus.c			\
				srcs/var_bonus/predict.c				\
				srcs/var_bonus/print_minus.c			\
				srcs/var_bonus/print_pound.c			\
				srcs/var_bonus/print_padding.c			\
				srcs/var_bonus/print_precision.c		\
				srcs/var_bonus/print_space.c			\
				srcs/var_bonus/print_plus.c				\
				srcs/var_bonus/priorities.c				\
				srcs/var_bonus/print_field_width.c		\
				srcs/var_bonus/field_width_utils.c		\
				srcs/var_bonus/get_details.c			\

LIBFT		:=	libft/libft.a

OBJS		:=	${FILES:.c=.o}

OBJS_BONUS	:=	${BONUS_FILES:.c=.o}

NAME		:=	libftprintf.a

all:			${NAME} ${LIBFT}

%.o:%.c includes/ft_printf.h Makefile ${LIBFT}
				cc ${FLAGS} -I ./includes -c $< -o $@

${NAME}:		${OBJS}
				cp libft/libft.a $@
				ar rcs $@ $^

${LIBFT}::
				make -C ./libft

clean::
				rm -rf ${OBJS} ${OBJS_BONUS} libft/*.o 

fclean::		clean
				make -C ./libft fclean
				rm -rf ${NAME}

re:		fclean all

bonus:		${OBJS_BONUS}
				cp libft/libft.a ${NAME}
				ar rcs ${NAME} $^

re_bonus:	fclean bonus

.PHONY:		all	clean	fclean	re bonus