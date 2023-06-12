# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orazafy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 17:50:18 by orazafy           #+#    #+#              #
#    Updated: 2022/07/24 21:45:43 by orazafy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -Wall -Werror -Wextra -c ft_putchar.c  ft_putstr.c  ft_strcmp.c	ft_strlen.c  ft_swap.c
ar rc libft.a ft_putchar.o  ft_putstr.o  ft_strcmp.o	ft_strlen.o  ft_swap.o
rm ft_putchar.o  ft_putstr.o  ft_strcmp.o   ft_strlen.o  ft_swap.o
