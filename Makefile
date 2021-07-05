# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngpar <youngpar@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/15 22:15:09 by youngpar          #+#    #+#              #
#    Updated: 2021/07/03 03:24:26 by youngpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LNAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -rf

SRCS = $(addprefix ./srcs/, \
	   ft_check_obj.c \
	   ft_check_opt.c \
	   ft_is_checker.c \
	   ft_printf.c \
	   ft_print_char.c \
	   ft_print_num.c \
	   )
BSRCS = $(addprefix ./srcs/, \
		ft_check_obj_bonus.c \
		ft_check_opt_bonus.c \
		ft_is_checker_bonus.c \
		ft_printf_bonus.c \
		ft_print_char_bonus.c \
		ft_print_num.c \
		)
OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

LIBFT_DIR = ./libft

OBJ = $(OBJS)

ifdef BONUS
	OBJ = $(BOBJS)
endif

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

all:		$(NAME)

bonus:
	BONUS=1 $(MAKE)

$(NAME):	$(OBJ)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LNAME) $(NAME)
	$(AR) $(NAME) $(OBJ)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS) $(BOBJS)

fclean:		clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

test:		all
	$(CC) $(CFLAGS) main.c -lftprintf -L.
	./a.out | cat -e

.PHONY : all clean fclean re bonus test
