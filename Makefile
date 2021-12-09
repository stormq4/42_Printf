# -*- Makefile -*-

NAME := libftprintf.a

CFLAGS := -Wall -Wextra -Werror

CC := gcc

SRCS := \
ft_printf.c \
pf_put.c \
pf_putnbr.c \
pf_putnbr_h.c \

OBJS := ${SRCS:%.c=%.o}

HEADFILES := ft_printf.h

all : $(NAME)

%.o : %.c $(HEADFILES) 
	$(CC) -c $(CFLAGS) -o $@ $<

$(NAME) : $(OBJS)
	ar -ru $(NAME) $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean flcean, re
