# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 15:14:55 by cgoncalv          #+#    #+#              #
#    Updated: 2020/02/10 16:51:19 by cgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

SRC			=	ft_printf.c ft_printf_utils.c ft_args_1.c ft_args_2.c \
				ft_flags.c ft_flags_options.c

LIBFTMAKEFILE = libft/Makefile

OBJ 		=	$(SRC:.c=.o)

NAME		=	libftprintf.a

LIB			=	ar rcs

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C ./libft
			@cp ./libft/libft.a $(NAME)
			@$(LIB) $(NAME) ${OBJ}
			@echo "\033[32m\n[✓]\033[0m		[$(NAME) compiled]"

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
			@rm -f *.o
			@echo "\033[32m\n[✓]\033[0m		[*.o deleted]"

fclean:		clean
			@rm -f $(NAME)
			@rm -f libft/libft.a
			@rm -f libft/*.o
			@echo "\033[32m[✓]\033[0m		[libft.a deleted]"
			@echo "\033[32m[✓]\033[0m		[libftprintf.a deleted]"

re:			fclean all
