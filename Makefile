# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocalder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 19:34:02 by jocalder          #+#    #+#              #
#    Updated: 2024/11/06 21:57:59 by jocalder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftgnl.a

SRCS	= get_next_line.c get_next_line_utils.c 

OBJS	= $(SRCS:.c=.o)

CC	= cc

FLAGS	= -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
	cc $(FLAGS) -c $< -o $@ -I ./

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re
