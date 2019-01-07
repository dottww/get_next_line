# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weilin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/19 21:23:36 by weilin            #+#    #+#              #
#    Updated: 2019/01/07 14:56:32 by weilin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_tolower.c\
		ft_toupper.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_strlen.c\
		ft_strcpy.c\
		ft_strncpy.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_strlcat.c\
		ft_atoi.c\
		ft_strdup.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_memset.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_bzero.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_itoa.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putnbr.c\
		ft_putendl.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putnbr_fd.c\
		ft_putendl_fd.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_int_len.c\
		ft_sqrt.c\
		ft_count_if.c\
		ft_print_words_tables.c\
		ft_wd.c\
		ft_strreset.c

OBJS = $(SRC:.c=.o)

RM = rm -rf

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(FLAG) $(SRC)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) a.out*

fclean: clean
	$(RM) $(NAME)

re: fclean all
