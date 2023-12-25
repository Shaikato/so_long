# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: randre <randre@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/24 23:25:05 by randre            #+#    #+#              #
#    Updated: 2023/12/24 23:26:48 by randre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= get_next_line.c \
				get_next_line_utils.c

OBJS		= ${SRCS:.c=.o}

NAME 		= get_next_line.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
	ar -rcs $@ $^

all:		${NAME}

clean:
	rm -f ${OBJS}

fclean:
	rm -f ${OBJS} ${OBJS_BONUS}
	rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re