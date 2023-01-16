# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blevrel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 10:11:38 by blevrel           #+#    #+#              #
#    Updated: 2022/11/25 17:27:35 by blevrel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= account_output

SRCS	=	tests.cpp	\
			Account.cpp	\

OBJS	= ${SRCS:.cpp=.o}

CC		= c++

CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g

RM		= rm -f

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.cpp.o:
	${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

.PHONY: all clean fclean re
