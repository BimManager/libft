# libft Makefile

CC = gcc
AR = ar
SRCDIR := srcs
OBJDIR := objs
NAME = libft.a
HDRS = libft.h
SRCS := $(addprefix $(SRCDIR)/, \
		ft_abs.c ft_assert.c \
		ft_atoi.c ft_bit_manip.c \
		ft_bzero.c ft_dequeue.c \
		ft_enqueue.c ft_gcd.c \
		ft_isalnum.c ft_strsplit_lst.c \
		ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_islower.c \
		ft_isprime.c ft_isprint.c \
		ft_isupper.c ft_iswhitespace.c \
		ft_itoa.c ft_itoa_base.c \
		ft_lstadd.c ft_lstdel.c \
		ft_lstdelif.c ft_lstdelone.c \
		ft_lstiter.c ft_lstmap.c \
		ft_lstnew.c ft_lstrev.c \
		ft_lstsize.c ft_lstsort.c \
		ft_memalloc.c ft_memccpy.c \
		ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memdel.c \
		ft_memmove.c ft_memset.c \
		ft_print_bit_pattern.c \
		ft_putchar.c ft_putchar_fd.c \
		ft_putendl.c ft_putendl_fd.c \
		ft_putnbr.c ft_putnbr_endl.c \
		ft_putnbr_fd.c ft_putstr.c \
		ft_putstr_fd.c ft_qsort.c \
		ft_queuedel.c ft_queuenew.c \
		ft_queuepeek.c ft_queuesize.c \
		ft_rotate.c ft_split_whitespaces.c \
		ft_sqrt.c ft_stackdel.c \
		ft_stacknew.c ft_stackpeek.c \
		ft_stackpop.c ft_stackpush.c \
		ft_stacksize.c ft_str_isalpha.c \
		ft_str_islower.c ft_str_isnumeric.c \
		ft_str_isprint.c ft_str_isupper.c \
		ft_strcapitalize.c ft_strcat.c \
		ft_strchr.c ft_strclr.c \
		ft_strcmp.c ft_strcpy.c \
		ft_strdel.c ft_strdup.c \
		ft_strequ.c ft_striter.c \
		ft_striteri.c ft_strjoin.c \
		ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strlowcase.c \
		ft_strmap.c ft_strmapi.c \
		ft_strncat.c ft_strncmp.c \
		ft_strncpy.c ft_strnequ.c \
		ft_strnew.c ft_strnstr.c \
		ft_strrchr.c ft_strsplit.c \
		ft_strstr.c ft_strsub.c \
		ft_strtrim.c ft_strupcase.c \
		ft_swap.c ft_tolower.c \
		ft_toupper.c ft_strndup.c \
		get_next_line.c ft_putaddr.c \
		ft_putsizet.c)
OBJS := ft_abs.o ft_assert.o \
		ft_atoi.o ft_bit_manip.o \
		ft_bzero.o ft_dequeue.o \
		ft_enqueue.o ft_gcd.o \
		ft_isalnum.o ft_strsplit_lst.o \
		ft_isalpha.o ft_isascii.o \
		ft_isdigit.o ft_islower.o \
		ft_isprime.o ft_isprint.o \
		ft_isupper.o ft_iswhitespace.o \
		ft_itoa.o ft_itoa_base.o \
		ft_lstadd.o ft_lstdel.o \
		ft_lstdelif.o ft_lstdelone.o \
		ft_lstiter.o ft_lstmap.o \
		ft_lstnew.o ft_lstrev.o \
		ft_lstsize.o ft_lstsort.o \
		ft_memalloc.o ft_memccpy.o \
		ft_memchr.o ft_memcmp.o \
		ft_memcpy.o ft_memdel.o \
		ft_memmove.o ft_memset.o \
		ft_print_bit_pattern.o \
		ft_putchar.o ft_putchar_fd.o \
		ft_putendl.o ft_putendl_fd.o \
		ft_putnbr.o ft_putnbr_endl.o \
		ft_putnbr_fd.o ft_putstr.o \
		ft_putstr_fd.o ft_qsort.o \
		ft_queuedel.o ft_queuenew.o \
		ft_queuepeek.o ft_queuesize.o \
		ft_rotate.o ft_split_whitespaces.o \
		ft_sqrt.o ft_stackdel.o \
		ft_stacknew.o ft_stackpeek.o \
		ft_stackpop.o ft_stackpush.o \
		ft_stacksize.o ft_str_isalpha.o \
		ft_str_islower.o ft_str_isnumeric.o \
		ft_str_isprint.o ft_str_isupper.o \
		ft_strcapitalize.o ft_strcat.o \
		ft_strchr.o ft_strclr.o \
		ft_strcmp.o ft_strcpy.o \
		ft_strdel.o ft_strdup.o \
		ft_strequ.o ft_striter.o \
		ft_striteri.o ft_strjoin.o \
		ft_strlcat.o ft_strlcpy.o \
		ft_strlen.o ft_strlowcase.o \
		ft_strmap.o ft_strmapi.o \
		ft_strncat.o ft_strncmp.o \
		ft_strncpy.o ft_strnequ.o \
		ft_strnew.o ft_strnstr.o \
		ft_strrchr.o ft_strsplit.o \
		ft_strstr.o ft_strsub.o \
		ft_strtrim.o ft_strupcase.o \
		ft_swap.o ft_tolower.o \
		ft_toupper.o ft_strndup.o \
		get_next_line.o ft_putaddr.o \
		ft_putsizet.o

CFLAGS = -Wall -Wextra -Werror -Iincludes/
ARFLAGS = -q -c

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $^

.PHONY : clean
clean :
	@rm -f $(OBJS)

.PHONY : fclean
fclean : clean
	@rm -f $(NAME)

.PHONY : re 
re : fclean all