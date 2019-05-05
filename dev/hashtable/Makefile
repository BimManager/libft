# hashtable Makefile
CC = gcc
CFLAGS = -v -g -Wall -Wextra -Werror -I/Users/kkozlov/programming/c/libft/includes #-fsanitize=address 
LDFLAGS = -v -L/Users/kkozlov/programming/c/libft -lft

NAME = hashtable
HDRS = libft.h htbl.h
SRCS = htbl.c  main.c
OBJS = htbl.o  main.o

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $^

.PHONY : clean fclean all re

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
