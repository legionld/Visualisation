# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschille <jschille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 12:09:02 by jschille          #+#    #+#              #
#    Updated: 2019/06/25 13:14:50 by lgigi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= vis-hex
FLAGS		= -Wall -Werror -Wextra -lmlx -framework OpenGL -framework AppKit
INCLUDES	= ../libft/includes

all: $(NAME)

$(NAME):
	make -C ../libft
	gcc $(FLAGS) *.c  -o $(NAME)  -I $(INCLUDES) -L ../libft/ -lft

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
