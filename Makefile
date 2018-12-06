# libft Makefile

CC = gcc
AR = ar
NAME = libft.a
HDRS = *.h
#SRCS = $(shell find ./srcs -name "*.c")
SRCS := $(wildcard srcs/*.c)
OBJDIR = objs
OBJS := *.o

CFLAGS = -Wall -Wextra -Werror -Iincludes
ARFLAGS = -v -q

vpath %.h includes
vpath %.c srcs

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $^

.PHONY : clean
clean :
	rm -f *.o

.PHONY : fclean
fclean : clean
	rm -f $(NAME)

.PHONY : re 
re : fclean all 