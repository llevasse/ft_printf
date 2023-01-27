# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 15:18:30 by llevasse          #+#    #+#              #
#    Updated: 2023/01/27 11:51:25 by llevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS		=	-Wall -Wextra -Werror

FILES		= 	srcs/ft_printf.c \
				srcs/ft_printf_utils.c 

BONUS_FILES	= 	srcs/ft_printf_bonus.c				\
				srcs/ft_printf_utils_bonus.c		\
				srcs/var_bonus/predict.c			\
				srcs/var_bonus/print_minus.c		\
				srcs/var_bonus/print_pound.c		\
				srcs/var_bonus/print_padding.c		\
				srcs/var_bonus/print_precision.c	\
				srcs/var_bonus/print_space.c		\
				srcs/var_bonus/print_plus.c			\
				srcs/var_bonus/priorities.c			\
				
				
LIBFT_FILES	= 	libft/ft_atoi.c \
				libft/ft_striteri.c \
				libft/ft_bzero.c \
				libft/ft_strjoin.c \
				libft/ft_calloc.c \
				libft/ft_strlcat.c \
				libft/ft_isalnum.c \
				libft/ft_memchr.c \
				libft/ft_strlcpy.c \
				libft/ft_isalpha.c \
				libft/ft_memcmp.c \
				libft/ft_strlen.c \
				libft/ft_isascii.c \
				libft/ft_memcpy.c \
				libft/ft_strmapi.c \
				libft/ft_isdigit.c \
				libft/ft_memmove.c \
				libft/ft_strncmp.c \
				libft/ft_isprint.c \
				libft/ft_memset.c \
				libft/ft_strnstr.c \
				libft/ft_itoa.c \
				libft/ft_putchar_fd.c \
				libft/ft_putnbr_fd.c \
				libft/ft_strrchr.c \
				libft/ft_putendl_fd.c \
				libft/ft_strtrim.c \
				libft/ft_substr.c \
				libft/ft_putstr_fd.c \
				libft/ft_tolower.c \
				libft/ft_split.c \
				libft/ft_toupper.c \
				libft/ft_strchr.c \
				libft/ft_strdup.c \
				libft/ft_is_in_str.c \

MAIN_FILE	= 	srcs/main.c

EXECUTABLE	:= main

OBJS		= ${FILES:.c=.o}

LIBFT_OBJS	= ${LIBFT_FILES:.c=.o}

OBJS_BONUS	= ${BONUS_FILES:.c=.o}

MAIN_OBJ	= ${MAIN_FILE:.c=.o}

NAME		= libftprintf.a

.c.o:
				gcc ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				cd libft; make libft.a; cd ..; ar rcs ${NAME} ${LIBFT_OBJS} ${OBJS}

bonus:		fclean ${OBJS_BONUS}
				cd libft; make libft.a; cd ..; ar rcs ${NAME} ${LIBFT_OBJS} ${OBJS_BONUS}

all:		${NAME}


clean:
				rm -f ${OBJS} ${OBJS_BONUS} ${LIBFT_OBJS}

fclean:		clean
				rm -f ${NAME}

re:			fclean all

alldebug:	bin/$(EXECUTABLE)

run: cleandebug alldebug
	clear
	./bin/$(EXECUTABLE)

bin/$(EXECUTABLE): ${BONUS_FILES} ${MAIN_FILE} ${LIBFT_FILES}
	gcc -ggdb -fsanitize=address ${FLAGS} $^ -o $@ 

cleandebug:
	-rm bin/*

.PHONY:		all	clean	fclean	re bonus
