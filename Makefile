# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apercebo <apercebo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 15:42:38 by apercebo          #+#    #+#              #
#    Updated: 2022/03/27 17:22:24 by apercebo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC		= gcc
RM		= rm -f
SOURCES = solong.c \
          get_next_line.c \
		  get_next_line_utils.c \
		  soinput.c \
		  soutils.c \
		  socollec.c
OBJS = $(SOURCES:.c=.o)
MINILIBX = -L. -lmlx

CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g3

all:		mlx printf ${NAME}

%.o:	%.c Makefile solong.h ./ft_printf/libftprintf.a
	${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS} solong.h Makefile
			${CC} ${CFLAGS} ${OBJS} ft_printf/libftprintf.a -o ${NAME} ${MINILIBX}

printf:
		@make -C ./ft_printf

mlx:
		@make -C minilibx
		@cp minilibx/libmlx.dylib .

clean:
			${RM} ${OBJS}
			make -C minilibx clean
			make clean -C ./ft_printf

fclean:		clean
			make fclean -C ./ft_printf
			${RM} libmlx.dylib
			${RM} so_long

re:			fclean all

.PHONY:		all clean fclean re