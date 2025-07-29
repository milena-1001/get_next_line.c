# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucas <lucas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/12 16:17:06 by milferna          #+#    #+#              #
#    Updated: 2025/07/29 04:19:27 by lucas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Werror -Wextra fsani
NAME = libftprintf.a
SRCS = ft_printf.c utils.c
OBJ_FILES = $(SRCS:.c=.o)
$(NAME) : $(OBJ_FILES)
	ar -rc $(NAME) $(OBJ_FILES)
%.o:%.c libftprintf.h
	$(CC) $(CFLAGS) -c $< -o $@
all: $(NAME)
clean:
	rm -f $(OBJ_FILES)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re