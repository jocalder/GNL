# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocalder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 19:34:02 by jocalder          #+#    #+#              #
#    Updated: 2024/11/18 21:37:43 by jocalder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftgnl.a

SRCS	= get_next_line.c \
	get_next_line_utils.c \

BNS_SRCS = get_next_line_bonus.c \
	   get_next_line_utils_bonus.c \

OBJS	= $(SRCS:.c=.o)

BNS_OBJS = $(BNS_SRCS:.c=.o)

CC	= cc

FLAGS	= -Wall -Werror -Wextra

all: $(NAME)

$(OBJS): %.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(BNS_OBJS): %.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

bonus: $(BNS_OBJS)
	ar rc $(NAME) $(BNS_OBJS)

clean:
	rm -f $(OBJS) $(BNS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
