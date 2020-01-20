# libft Makefile

CC = gcc
AR = ar

CFLAGS = -Wall -Wextra -Werror -c -g -Iinclude/
ARFLAGS = -q -c

HDRS = libft.h
SRCDIR := src
OBJDIR := build
NAME = libft.a

SRCS := $(addprefix $(SRCDIR)/, \
		ft_abs.c ft_alignflag.c ft_assert.c \
		ft_asterisk.c ft_atoi.c ft_bit_manip.c \
		ft_bstr.c ft_bzero.c ft_cestr.c ft_cgstr.c \
		ft_cllength.c ft_cstr.c ft_custr.c \
		ft_cvtarg.c ft_cxstr.c ft_decrad.c \
		ft_decstr.c ft_dequeue.c ft_dprintf.c \
		ft_dstr.c ft_enqueue.c ft_estr.c \
		ft_expstr.c ft_feg.c ft_fixhash_boxp.c \
		ft_fixprec_dioux.c ft_fixsign.c ft_fixwidth.c \
		ft_fmtnb.c ft_formatnew.c ft_fstr.c \
		ft_gcd.c ft_genstr.c ft_getldb.c \
		ft_gstr.c ft_hashflag.c ft_hexstr.c \
		ft_hlength.c ft_infnan.c ft_isalnum.c \
		ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_islower.c ft_ispow2.c ft_isprime.c \
		ft_isprint.c ft_istr.c ft_isupper.c \
		ft_iswhitespace.c ft_itoa.c ft_itoa_base.c \
		ft_jlength.c ft_kstr.c ft_ldbstr.c \
		ft_llength.c ft_lstadd.c ft_lstdel.c \
		ft_lstdelif.c ft_lstdelone.c ft_lstiter.c \
		ft_lstmap.c ft_lstnew.c ft_lstrev.c \
		ft_lstsize.c ft_lstsort.c ft_memalloc.c \
		ft_memccpy.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memdel.c ft_memdup.c \
		ft_memmove.c ft_memset.c ft_mvshash.c \
		ft_nbitstr.c ft_nullguard.c ft_octstr.c \
		ft_ostr.c ft_percent.c ft_plusflag.c \
		ft_powl.c ft_prec.c ft_print_bit_pattern.c \
		ft_printf.c ft_printsf.c ft_pstr.c \
		ft_putaddr.c ft_putchar.c ft_putchar_fd.c \
		ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
		ft_putnbr_endl.c ft_putnbr_fd.c ft_putsizet.c \
		ft_putstr.c ft_putstr_fd.c ft_qsort.c \
		ft_queuedel.c ft_queue_isempty.c ft_queuenew.c \
		ft_queuepeek.c ft_dequenew.c ft_dequedel.c \
		ft_dequecons.c ft_dequesnoc.c ft_dequepeek.c \
		ft_dequekeep.c ft_dequepop.c ft_dequeeject.c \
		ft_deque_isempty.c ft_hamming_weight.c \
		ft_queuesize.c ft_radstr.c ft_rotate.c \
		ft_round.c ft_rstr.c ft_spaceflag.c \
		ft_split_whitespaces.c ft_splitws_lst.c ft_sqrt.c \
		ft_sstr.c ft_stackdel.c ft_stacknew.c \
		ft_stackpeek.c ft_stackpop.c ft_stackpush.c \
		ft_stacksize.c ft_str_isalpha.c ft_str_islower.c \
		ft_str_isnumeric.c ft_str_isprint.c ft_str_isupper.c \
		ft_strcapitalize.c ft_strcat.c ft_strchr.c \
		ft_strclr.c ft_strcmp.c ft_strcpy.c \
		ft_strdel.c ft_strdup.c ft_strequ.c \
		ft_striter.c ft_striteri.c ft_strjoin.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c \
		ft_strlowcase.c ft_strmap.c ft_strmapi.c \
		ft_strncat.c ft_strncmp.c ft_strncpy.c \
		ft_strndup.c ft_strnequ.c ft_strnew.c \
		ft_strnstr.c ft_strrchr.c ft_strrev.c \
		ft_strsplit.c ft_strsplit_lst.c ft_strstr.c \
		ft_strsub.c ft_strtrim.c ft_strupcase.c \
		ft_swap.c ft_tlength.c ft_tolower.c \
		ft_toupper.c ft_ustr.c ft_width.c \
		ft_xprintf.c ft_xstr.c ft_zeroflag.c \
		ft_zlength.c get_next_line.c ft_strtol.c \
		ft_fndmax.c ft_datanew.c ft_datadel.c \
		ft_dbnodenew.c ft_dbnodedel.c \
		ft_dblstnew.c ft_dblstdel.c ft_dblstcons.c \
		ft_dblstsnoc.c ft_dblstpop.c ft_dblsteject.c \
		ft_dblstiter.c ft_isdec.c ft_dblst_issorted.c \
		ft_dblsthas.c ft_dblstmax.c \
		ft_die.c ft_cntsort.c ft_insrtsort.c \
		ft_trienew.c ft_trieadd.c ft_triefind.c \
		ft_triedel.c ft_fac.c ft_permute.c \
		ft_btrdiam.c)

OBJS := $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

mkdir :
	@if [[ ! -e $(OBJDIR) ]]; then mkdir $(OBJDIR); fi

$(OBJDIR)/%.o : $(SRCDIR)/%.c mkdir
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@if [[ -e $(OBJDIR) ]]; then rm -rf $(OBJDIR); fi

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re mkdir

