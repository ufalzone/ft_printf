# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 19:50:55 by ufalzone          #+#    #+#              #
#    Updated: 2024/11/17 20:03:43 by ufalzone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
FLAG = -Wall -Werror -Wextra

FILE = ft_printf.c ft_printf_utils.c
OBJ = ${FILE:.c=.o}

all:${NAME}

${NAME}:${OBJ}
	ar -rcs ${NAME} ${OBJ}
%.o:%.c
	${CC} -c ${FLAG} $<
clean:
	rm -f ${OBJ}
fclean:clean
	rm -f ${NAME}
re:fclean all

.PHONY: all clean fclean re