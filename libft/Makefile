# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 12:03:39 by jmichaud          #+#    #+#              #
#    Updated: 2016/11/28 11:57:40 by jmichaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## V A R I A B L E S
#####################
NAME			=	libft.a

SRC_NAME		=	ft_atoi.c				\
					ft_bzero.c				\
					ft_intlen.c				\
					ft_isalnum.c			\
					ft_isalpha.c			\
					ft_isascii.c			\
					ft_isblank.c			\
					ft_iscntrl.c			\
					ft_isdigit.c			\
					ft_isgraph.c			\
					ft_islower.c			\
					ft_isprint.c			\
					ft_isspace.c			\
					ft_isupper.c			\
					ft_isxdigit.c			\
					ft_itoa.c				\
					ft_lstadd.c				\
					ft_lstdel.c				\
					ft_lstdelone.c			\
					ft_lstiter.c			\
					ft_lstmap.c				\
					ft_lstnew.c				\
					ft_memalloc.c			\
					ft_memccpy.c			\
					ft_memchr.c				\
					ft_memcmp.c				\
					ft_memcpy.c				\
					ft_memdel.c				\
					ft_memmove.c			\
					ft_memset.c				\
					ft_nbwords.c			\
					ft_putchar.c			\
					ft_putchar_fd.c			\
					ft_putendl.c			\
					ft_putendl_fd.c			\
					ft_putnbr.c				\
					ft_putnbr_fd.c			\
					ft_putstr.c				\
					ft_putstr_fd.c			\
					ft_str_is_alpha.c		\
					ft_str_is_lowercase.c	\
					ft_str_is_numeric.c		\
					ft_str_is_printable.c	\
					ft_str_is_uppercase.c	\
					ft_strcat.c				\
					ft_strcapitalize.c		\
					ft_strchr.c				\
					ft_strclr.c				\
					ft_strcmp.c				\
					ft_strcpy.c				\
					ft_strdel.c				\
					ft_strdup.c				\
					ft_strequ.c				\
					ft_striter.c			\
					ft_striteri.c			\
					ft_strjoin.c			\
					ft_strlcat.c			\
					ft_strlcpy.c			\
					ft_strlen.c				\
					ft_strlowcase.c			\
					ft_strmap.c				\
					ft_strmapi.c			\
					ft_strncat.c			\
					ft_strncmp.c			\
					ft_strncpy.c			\
					ft_strnequ.c			\
					ft_strnew.c				\
					ft_strnstr.c			\
					ft_strrchr.c			\
					ft_strsplit.c			\
					ft_strstr.c				\
					ft_strsub.c				\
					ft_strtrim.c			\
					ft_strupcase.c			\
					ft_tolower.c			\
					ft_toupper.c			\
					ft_wordlen.c

SRC_PATH		=	./srcs/
INC_PATH		=	./includes/
OBJ_PATH		=	./obj/

## C O M P I L E R
###################
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
CPPFLAGS		=	-I$(INC_PATH)

## A U T O M A T I C
#####################
OBJ_NAME		=	$(SRC_NAME:.c=.o)
OBJ				=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC				=	$(addprefix $(SRC_PATH), $(SRC_NAME))

## R U L E S
#############
.PHONY			:	all clean fclean re

all				:	$(NAME)

$(NAME)			:	$(OBJ)
	ar rc $@ $^
	ranlib $@

$(OBJ_PATH)%.o	:	$(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean			:
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean			:	clean
	rm -f $(NAME)

re				:	fclean all
