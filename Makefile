# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Wei <Wei@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/19 21:23:36 by weilin            #+#    #+#              #
#    Updated: 2018/12/31 14:33:17 by Wei              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.out

SRC = get_next_line.c

OBJS = $(SRC:.c=.o)

RM = rm -rf

LIBFT=libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT)
	gcc -g -o $(NAME) $(FLAG) $(SRC) -I libft/ -L libft/ -lft
#to use outside lib, must have that lib already compiled to .a so be able to use it
# -I is to tell the current project header the place where to find ouside header
# -L is to tell the current project header the place where to find ouside lib
# -l tells please use/read lib"ft".a

$(LIBFT):
	make -C libft all
#it will call the makefile in the destination

clean:
	$(RM) $(OBJS)
	$(RM) *.out*

fclean: clean
	$(RM) $(NAME)

re: fclean all
