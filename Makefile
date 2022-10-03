# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 19:03:31 by lagonzal          #+#    #+#              #
#    Updated: 2022/10/03 20:39:34 by lagonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Makefile project printf
NAME = libftprintf.a

SRCS = ft_printf.c\
	   ft_putchar_n.c\
	   ft_putnbr_base_n.c\
	   ft_putnbr_baseh_n.c\
	   ft_putptr.c\
	   ft_putstr_n.c\
	   ft_putunbr_n.c

OBJS = ft_printf.o\
	   ft_putchar_n.o\
	   ft_putnbr_base_n.o\
	   ft_putnbr_baseh_n.o\
	   ft_putptr.o\
	   ft_putstr_n.o\
	   ft_putunbr_n.o

CC = gcc

RM = rm -f

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

flclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
