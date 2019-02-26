# libft Makefile

CC = gcc
AR = ar
NAME = libft.a
HDRS = *.h
SRCS := $(wildcard *.c)
OBJDIR = objs
OBJS := *.o

CFLAGS = -Wall -Wextra -Werror
ARFLAGS = -v -q

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $^

.PHONY : clean
clean :
	rm -f $(OBJS)

.PHONY : fclean
fclean : clean
	rm -f $(NAME)

.PHONY : re 
re : fclean all 