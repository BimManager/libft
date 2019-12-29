# heaps Makefile
CC = gcc
CFLAGS = -v -g -Wall -Wextra -Werror -I../../include #-fsanitize=address 
LDFLAGS = -v -L../../ -lft

NAME = heaps
SRCS = maxheap.c main.c
OBJS = ${SRCS:.c=.o}

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
