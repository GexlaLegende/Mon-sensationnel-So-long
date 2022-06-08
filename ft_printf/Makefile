# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apercebo <apercebo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 11:37:27 by apercebo          #+#    #+#              #
#    Updated: 2022/03/24 18:09:11 by apercebo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS = ft_printf.c \
	   ft_putstr.c \
	   ft_putnbr.c \
	   ft_putnbrunsign.c \
	   ft_putnbrhexa.c \
	   ft_putaddress.c \
	   ft_strchr.c \

OBJS	= $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

%.o:		%.c ft_printf.h
			${CC} ${CFLAGS} -I includes -c $< -o $@

${NAME}:	${OBJS}
			ar rcs $(NAME) $(OBJS)

all:		${NAME}

clean:
			${RM} ${OBJS}
			
fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re 
