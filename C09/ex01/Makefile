# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orazafy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 18:02:59 by orazafy           #+#    #+#              #
#    Updated: 2022/07/25 20:04:15 by orazafy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs

SOURCES	= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

OBJS 	= ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o

HEADERS = ../includes

NAME	= libft.a

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror 

${NAME}:
		cd ${SRCS} && ${CC} ${CFLAGS} -c -I${HEADERS} ${SOURCES}
		cd ${SRCS} && ar rc ${NAME} ${OBJS}
		cd ${SRCS} && mv ${NAME} ..

all:	${NAME}

clean:
		cd ${SRCS} && ${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re libft.a
