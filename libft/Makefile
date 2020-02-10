# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 15:14:55 by cgoncalv          #+#    #+#              #
#    Updated: 2020/01/23 15:32:49 by cgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

CFLAGS		=	-W -Wall -Werror -Wextra -c

SRC			=	ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_ll_itoa.c \
				ft_u_itoa.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strcmp.c \
				ft_strjoinfree.c \
				ft_strdup.c \
				ft_strduptoc.c \
				ft_strndup.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strstr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_str_toupper.c \
				ft_toupper.c

SRCBONUS	=	ft_lstadd_back_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstmap_bonus.c \
				ft_lstnew_bonus.c \
				ft_lstsize_bonus.c

OBJ 		=	$(SRC:.c=.o)

OBJBONUS	=	$(SRCBONUS:.c=.o)

LIB 		=	ar rc

NAME		=	libft.a

all:		$(NAME)

$(NAME):
			@$(CC) $(CFLAGS) $(SRC)
			@$(LIB) $(NAME) $(OBJ)
			@echo "\033[32m\n[✓]\033[0m		[$(NAME) compiled]"

clean:
			@rm -f *.o
			@echo "\033[32m\n[✓]\033[0m		[*.o deleted]"

fclean:		clean
			@rm -f $(NAME)
			@echo "\033[32m[✓]\033[0m		[libft.a deleted]"

re:			fclean all

bonus:		$(OBJBONUS)
			$(LIB) $(NAME) $(OBJBONUS)
