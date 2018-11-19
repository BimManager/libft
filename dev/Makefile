#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 09:17:07 by kkozlov           #+#    #+#              #
#    Updated: 2018/11/15 11:29:35 by kkozlov          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I..
LDFLAGS = -L. -lft

OBJDIR = objs

PROG = a.out
HDRS = ft_lib.h ft_tqueue.h
SRCS = main.c\
		ft_tqueue.c ft_mems.c ft_del_substr.c
#OBJS = $(addprefix $(OBJDIR)/, main.o\
#		ft_tqueue.o ft_mems.o)

OBJS = main.o\
		ft_tqueue.o ft_mems.o ft_del_substr.o

vpath %.c srcs
vpath %.h includes
vpath %.o /srcs/objs

all : $(PROG)

$(PROG) : $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $^

#$(OBJDIR)/%.o : %.c
#	$(CC) $(CFLAGS) -c $^

.PHONY : clean
clean :
	rm -f $(OBJS)

.PHONY : fclean
fclean : clean
	rm -f $(PROG)

.PHONY : re 
re : fclean all