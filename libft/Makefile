# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 16:33:32 by leo               #+#    #+#              #
#    Updated: 2023/05/11 16:47:04 by llevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FLAGS			= -Wall -Wextra -Werror

CC				= cc

FILES			= ft_atoi.c ft_striteri.c ft_bzero.c ft_strjoin.c ft_calloc.c ft_strlcat.c ft_isalnum.c ft_memchr.c ft_strlcpy.c ft_isalpha.c ft_memcmp.c ft_strlen.c ft_isascii.c ft_memcpy.c ft_strmapi.c ft_isdigit.c ft_memmove.c ft_strncmp.c ft_isprint.c ft_memset.c ft_strnstr.c ft_itoa.c ft_putchar_fd.c ft_putnbr_fd.c ft_strrchr.c ft_putendl_fd.c ft_strtrim.c ft_substr.c ft_putstr_fd.c ft_tolower.c ft_split.c ft_toupper.c ft_strchr.c ft_strdup.c  ft_is_in_str.c
BONUS			= ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
FILES_GNL		= get_next_line.c get_next_line_utils.c

OBJS		= ${FILES:.c=.o}

BONUS_OBJS	= ${BONUS:.c=.o}

GNL_OBJS	= ${FILES_GNL:.c=.o}


NAME		= libft.a

HEADER		= libft.h

%.o:		%.c ${HEADER}
				${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${GNL_OBJS}
				ar rcs ${NAME} ${OBJS}

bonus:		$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

all:		${NAME}

clean:
				rm -f ${OBJS} ${BONUS_OBJS} ${GNL_OBJS}

fclean:		clean
				rm -f ${NAME}
				
re:			fclean all

.PHONY:		all	clean	fclean	re	bonus