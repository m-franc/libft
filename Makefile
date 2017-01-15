# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfranc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 18:43:40 by mfranc            #+#    #+#              #
#    Updated: 2017/01/15 19:36:32 by mfranc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -fsanitize=address

INCLUDES = includes

SRCS = 	ft_memset.c				\
		ft_bzero.c 				\
		ft_memcpy.c				\
		ft_memccpy.c 			\
		ft_memmove.c			\
		ft_memchr.c				\
		ft_memcmp.c				\
		ft_strlen.c				\
		ft_strdup.c				\
		ft_strcpy.c				\
		ft_strncpy.c			\
		ft_strcat.c				\
		ft_strncat.c			\
		ft_strlcat.c			\
		ft_strchr.c				\
		ft_strrchr.c			\
		ft_strstr.c				\
		ft_strnstr.c			\
		ft_strncmp.c			\
		ft_strcmp.c				\
		ft_atoi.c				\
		ft_isalpha.c			\
		ft_isdigit.c			\
		ft_isalnum.c			\
		ft_isprint.c			\
		ft_isascii.c			\
		ft_toupper.c			\
		ft_tolower.c			\
		ft_memalloc.c			\
		ft_memdel.c				\
		ft_strnew.c				\
		ft_strdel.c				\
		ft_strclr.c				\
		ft_striter.c			\
		ft_striteri.c			\
		ft_strmap.c				\
		ft_strmapi.c			\
		ft_strequ.c				\
		ft_strnequ.c			\
		ft_strsub.c				\
		ft_strjoin.c			\
		ft_strtrim.c			\
		ft_putstr.c				\
		ft_puttab.c				\
		ft_strsplit.c			\
		ft_putendl.c			\
		ft_putchar_fd.c			\
		ft_putchar.c			\
		ft_putstr_fd.c			\
		ft_putendl_fd.c			\
		ft_putint_fd.c			\
		ft_lstnew.c				\
		ft_lstdelone.c			\
		ft_lstdel.c				\
		ft_lstadd.c				\
		ft_lstiter.c			\
		ft_lstmap.c				\
		ft_countword.c			\
		ft_isword.c				\
		ft_tabnew.c				\
		ft_sqrt.c				\
		ft_strsplit_tolist.c	\
		ft_putlist.c			\
		ft_listcount.c			\
		get_next_line.c			\
		ft_itoa.c				\
		ft_uitoa.c				\
		ft_ilen.c				\
		ft_uilen.c				\
		ft_putint.c				\
		ft_putuint.c			\
		ft_putaddr.c			\
		ft_ftoa.c				\
		ft_strspn.c				\
		ft_strcspn.c

OBJECTS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	$(CC) -c $< -o $@ -I $(INCLUDES)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
