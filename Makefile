# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocalder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 19:34:02 by jocalder          #+#    #+#              #
#    Updated: 2024/10/29 19:34:14 by jocalder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftgnl.a

SRCS	= ft_get_next_line.c \

OBJS	= $(SRCS:.c=.o)

CC	= cc

FLAGS	= -Wall -Werror -Wextra

all: $(NAME)

%.c: %.c
	cc $(FLAGS) -c $< -o $@ -I ./

$(NAME):
	cc $(FLAGS) -c $(SRCS) -I ./
	ar rc(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY all clean fclean re
