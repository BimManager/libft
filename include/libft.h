/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:38:10 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/09 15:09:50 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>
# include <time.h>
# include <limits.h>

# ifdef NDEBUG

#  define FT_ASSERT(exp) ((void)0)
# else

void				ft_assert(const char *expr, const char *file, int nline);
#  define FT_ASSERT(e) ((e) ? (void)0 : ft_assert(#e, __FILE__, __LINE__))
# endif

# define FT_UINT64_2PART(a, b) ((size_t)a << 32 + 0x##b##u)

# define SET_BIT(x, n)	((x) | (1 << (n)))
# define CLEAR_BIT(x, n) ((x) & ~(1 << (n)))
# define TOGGLE_BIT(x, n) ((x) ^ (1 << (n)))
# define TEST_BIT(x, n) ((x >> n) & 1)

# define IS_ODD(x) ((x) & 1)
# define ARE_EQUAL(a, b) ((a) ^ (b))
# define ZERO_OUT(a) ((a) ^ (a))

# define PARENT(n) ((n) & 1 ? (n) >> 1 : ((n) >> 1) - 1)
# define LEFT(n) (((n) << 1) + 1)
# define RIGHT(n) (((n) << 1) + 2)

# define M1		0x5555555555555555
# define M2		0x3333333333333333
# define M4		0x0f0f0f0f0f0f0f0f

# define BYTE 			8
# define BUFF_SIZE		1

# define STDOUT			0
# define STDIN			1
# define STDERR			2

# define MAX_FDS		4864
# define PSEUDO_NULL	-1
# define NSIN			8
# define TRIE_SIZE		256

# define SIGN_SIZE		1
# define EXP_SIZE		15
# define SIG_SIZE		63
# define EXP_BIAS		16383
# define EXP_ALL_ONES	32767
# define EXP_MAX		16383
# define EXP_MIN		-16382

typedef struct		s_format
{
	char			align : 1;
	char			plus : 1;
	char			space : 1;
	char			zero : 1;
	char			hash : 1;
	char			done : 1;
	char			neg : 1;
	char			null : 1;
	int				width;
	int				prec;
	int				length;
}					t_format;

typedef unsigned short	t_uint16;
typedef unsigned int	t_uint32;
typedef size_t			t_uint64;

typedef struct		s_ext80bits
{
	t_uint64		man : 64;
	t_uint32		exp : 15;
	t_uint32		sign : 1;
}					t_ext80bits;

typedef union		u_ext80
{
	long double		value;
	t_ext80bits		bits;
}					t_ext80;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_stack
{
	t_list			*top;
}					t_stack;

typedef struct		s_queue
{
	t_list			*head;
	t_list			*tail;
}					t_queue;

typedef struct		s_deque
{
	t_list			*head;
	t_list			*tail;
}					t_deque;

typedef struct		s_data
{
	void			*content;
	size_t			size;
}					t_data;

typedef struct		s_dbnode
{
	t_data			*data;
	struct s_dbnode	*prev;
	struct s_dbnode	*next;
}					t_dbnode;

typedef struct		s_trie
{
	struct s_trie	*next[TRIE_SIZE];
	t_data			*data;
}					t_trie;

typedef struct		s_btrnd
{
	t_data			*data;
	struct s_btrnd	*left;
	struct s_btrnd	*right;
	char			red;
}					t_btrnode;

typedef struct		s_hpnode
{
	t_data			*data;
	struct s_hpnode	*parent;
	struct s_hpnode	*left;
	struct s_hpnode	*right;
}					t_hpnode;

typedef struct		s_maxheap
{
	t_hpnode		*max;
}					t_maxheap;

typedef struct		s_dblst
{
	t_dbnode		*head;
	int				elems;
}					t_dblst;

typedef char		*(*t_pfmtfn)(va_list pa, t_format *data, const char **sfmt);

int					get_next_line(const int fd, char **line);

void				ft_die(const char *msg, int status);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_iswhitespace(char c);
int					ft_isdec(const char *str);

char				*ft_strncpy(char *dst, const char *src, size_t n);
char				**ft_split_whitespaces(char *str);
t_list				*ft_splitws_lst(char *str);
int					ft_str_isalpha(char *str);
int					ft_str_islower(char *str);
int					ft_str_isnumeric(char *str);
int					ft_str_isprint(char *str);
int					ft_str_isupper(char *str);
int					ft_str_isanagram(const char *s1, const char *s2);
char				*ft_strcapitalize(char *str);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strcat(char *dest, char *src);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, char *src);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
int					ft_strlen(const char *s);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
							size_t len);
char				*ft_strlowcase(char *str);
char				*ft_strncat(char *dest, char *src, int nb);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strupcase(char *str);

char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);

int					ft_atoi(const char *str);
long				ft_strtol(const char *str, int base);
void				*ft_fndmax(void *base, size_t nel, size_t width,
						int (*cmp)(const void *, const void *));

unsigned int		ft_abs(int x);
double				ft_sqrt(double x);
size_t				ft_fac(t_uint16 n);
size_t				ft_gcd(size_t a, size_t b);
int					**ft_permute(int *nums, int nsize,
								int *outsize, int **outcsizes);
int					ft_isprime(unsigned int nb);
int					ft_ispow2(size_t x);

void				ft_print_bit_pattern(void *pv, size_t elem_size);
void				ft_set_bit(void *pv, size_t elem_size, size_t bit_pos);
void				ft_zero_bit(void *pv, size_t elem_size, size_t bit_pos);
int					ft_test_bit(void *pv, size_t elem_size, size_t bit_pos);
void				ft_reverse_bits(void *pv, size_t elem_size);
int					ft_hamming_weight(const void *pb, size_t elem_size);
int					ft_popcount64(uint64_t x);

void				ft_swap(void *pv1, void *pv2, size_t elem_size);
void				ft_endcvt(void *pv, size_t width, size_t nel);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memdup(const void *src, size_t n);
void				ft_memrot(void *front, void *middle, void *end);

char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f) (char *));
void				ft_striteri(char *s, void (*f) (unsigned int, char *));
char				*ft_strmap(char const *s, char (*f) (char));
char				*ft_strmapi(char const *s, char (*f) (unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
t_list				*ft_strsplit_lst(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_itoa_base(int value, int base);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int nb);
void				ft_putnbr_endl(int nb);
void				ft_putaddr(size_t addr);
void				ft_putsizet(size_t nb);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del) (void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del) (void *, size_t));
void				ft_lstdelif(t_list **alst, void *ref_data,
						int (*cmp)(const void *, const void *),
						void (*del) (void *, size_t));
t_list				*ft_lstdupdel(t_list *head,
						int (*cmp)(const void *, const void *),
						void (*del) (void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f) (t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem));
void				ft_lstrev(t_list **alst);
size_t				ft_lstsize(t_list *lst);
t_list				*ft_lstsort(t_list *lst, int (*cmp)(void *, void *));

t_stack				*ft_stacknew(void const *content, size_t content_size);
void				ft_stackdel(t_stack **stack, void (*del) (void *, size_t));
void				ft_stackpush(t_stack *stack, void *content,
						size_t content_size);
t_list				*ft_stackpop(t_stack *stack);
t_list				*ft_stackpeek(t_stack *stack);
size_t				ft_stacksize(t_stack *stack);

t_queue				*ft_queuenew(void const *content, size_t content_size);
void				ft_queuedel(t_queue **queue, void (*del) (void *, size_t));
void				ft_enqueue(t_queue *queue, void *content,
						size_t content_size);
t_list				*ft_dequeue(t_queue *queue);
t_list				*ft_queuepeek(t_queue *queue);
size_t				ft_queuesize(t_queue *queue);
int					ft_queue_isempty(t_queue *queue);

t_deque				*ft_dequenew(void);
void				ft_dequedel(t_deque **deque, void (*del)(void *, size_t));
void				ft_dequecons(t_deque *deque, const void *data, size_t size);
void				ft_dequesnoc(t_deque *deque, const void *data, size_t size);
t_list				*ft_dequepeek(const t_deque *deque);
t_list				*ft_dequekeep(const t_deque *deque);
t_list				*ft_dequepop(t_deque *deque);
t_list				*ft_dequeeject(t_deque *deque);
int					ft_deque_isempty(const t_deque *deque);

t_data				*ft_datanew(const void *content, size_t size);
void				ft_datadel(t_data **data, void (*del)(void *, size_t));

t_dbnode			*ft_dbnodenew(t_data *data, t_dbnode *prv, t_dbnode *nxt);
void				ft_dbnodedel(t_dbnode **node, void (*del)(void *, size_t));

t_dblst				*ft_dblstnew(void);
void				ft_dblstdel(t_dblst **lst, void (*del)(void *, size_t));
void				ft_dblstsnoc(t_dblst *lst, t_data *data);
void				ft_dblstcons(t_dblst *lst, t_data *data);
t_data				*ft_dblstpop(t_dblst *lst);
t_data				*ft_dblsteject(t_dblst *lst);
void				ft_dblstiter(t_dblst *lst, void (*fn)(t_dbnode *));
t_data				*ft_dblstmax(t_dblst *lst,
								int (*cmp)(const void *, const void *));
int					ft_dblsthas(t_dblst *lst, const void *content,
								int (*cmp)(const void *, const void *));
int					ft_dblst_issorted(t_dblst *lst, int (*cmp)(const void *,
						const void *), int asc);

t_trie				*ft_trienew(t_data *data);
void				ft_triedel(t_trie **trie, void (*del)(void *, size_t));
void				ft_trieadd(t_trie *trie, const char *query, t_data *data);
t_data				*ft_triefind(t_trie *trie, const char *query);

int					ft_btrdiam(t_btrnode *root);

int					*ft_cntsort(int *arr, size_t n);
void				ft_insrtsort(void *base, size_t nel, size_t width,
						int (*cmp)(const void *, const void *));
void				ft_qsort(void *base, size_t nel, size_t width,
						int (*compar)(const void *, const void *));
void				ft_heapsort(void *base, size_t nel, size_t width,
						int (*compar)(const void *, const void *));

int					ft_dprintf(int fd, const char *fmt, ...);
int					ft_printf(const char *fmt, ...);

int					ft_xprintf(int fd, const char *fmt, va_list pa);

int					ft_printsf(int fd, const char **sfmt, va_list pa);

char				*ft_strrev(char *str);
t_format			*ft_formatnew(void);

long double			ft_getldb(va_list pa, t_format *fmt);
long double			ft_powl(long double x, long double y);
long double			ft_round(long double x, int prc);
char				*ft_feg(va_list pa, t_format *fmt, const char **sfmt,
							char *(*pfn)(const void *pnb, size_t prec));

t_stack				*ft_decrad(const void *pnb, size_t size,
								const char *digits, size_t rad);

char				*ft_radstr(const void *pnb, size_t size,
								const char *digits, size_t rad);

char				*ft_nbitstr(const void *pv, size_t nbits);
char				*ft_decstr(const void *pnb, size_t size);
char				*ft_octstr(const void *pnb, size_t size);
char				*ft_hexstr(const void *pnb, size_t size);
char				*ft_ldbstr(const void *pnb, size_t prc);
char				*ft_expstr(const void *pnb, size_t prc);

char				*ft_genstr(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_bstr(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_cstr(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_dstr(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_fstr(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_istr(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_xstr(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_cxstr(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_sstr(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_ustr(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_custr(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_pstr(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_ostr(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_estr(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_cestr(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_gstr(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_cgstr(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_rstr(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_kstr(va_list pa, t_format *fmt, const char **sfmt);

char				*ft_percent(va_list pa, t_format *fmt, const char **sfmt);

char				*ft_alignflag(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_plusflag(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_spaceflag(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_zeroflag(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_hashflag(va_list pa, t_format *fmt, const char **sfmt);

char				*ft_asterisk(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_width(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_prec(va_list pa, t_format *fmt, const char **sfmt);

char				*ft_hhlength(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_hlength(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_llength(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_lllength(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_cllength(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_tlength(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_jlength(va_list pa, t_format *fmt, const char **sfmt);
char				*ft_zlength(va_list pa, t_format *fmt, const char **sfmt);

size_t				ft_cvtarg(va_list pa, t_format *fmt);
char				*ft_fixprec_dioux(char *snb, t_format *fmt);

char				*ft_fixsign(char *s, t_format *fmt);
char				*ft_fixhash_boxp(char *snb, t_format *fmt, char *hash);
char				*ft_fixwidth(char *s, t_format *fmt);
char				*ft_mvsign(char	*snb, t_format *fmt);
char				*ft_mvhash(char *snb, t_format *fmt, char hash);

int					ft_nullguard(const void *pv, char **msg);
char				*ft_infnan(long double ldb);
int					ft_fmtnb(const char **sfmt);

#endif
