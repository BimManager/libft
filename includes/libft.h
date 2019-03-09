/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:38:10 by kkozlov           #+#    #+#             */
/*   Updated: 2019/03/08 16:33:54 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# ifdef NDEBUG

#  define FT_ASSERT(exp) ((void)0)

# else

void				ft_assert(const char *expr, const char *file, int nline);

#  define FT_ASSERT(e) ((e) ? (void)0 : ft_assert(#e, __FILE__, __LINE__))

# endif

# define BYTE 8
# define BUFF_SIZE	42
# define MAX_FDS	4864

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

typedef struct		s_tnode
{
	struct s_tnode	*left;
	struct s_tnode	*right;
	size_t			black_red : 1;
	void			*content;
	size_t			content_size;
}					t_tnode;

int					get_next_line(const int fd, char **line);

int					ft_atoi(const char *str);
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

char				*ft_strncpy(char *dst, const char *src, size_t n);
char				**ft_split_whitespaces(char *str);
int					ft_str_isalpha(char *str);
int					ft_str_islower(char *str);
int					ft_str_isnumeric(char *str);
int					ft_str_isprint(char *str);
int					ft_str_isupper(char *str);
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
void				ft_swap(void *pv1, void *pv2, size_t elem_size);
void				ft_rotate(void *front, void *middle, void *end);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);

unsigned int		ft_abs(int x);
double				ft_sqrt(double x);
size_t				ft_gcd(size_t a, size_t b);
int					ft_isprime(unsigned int nb);

void				ft_print_bit_pattern(void *pv, size_t elem_size);
void				ft_set_bit(void *pv, size_t elem_size, size_t bit_pos);
void				ft_zero_bit(void *pv, size_t elem_size, size_t bit_pos);
int					ft_test_bit(void *pv, size_t elem_size, size_t bit_pos);
void				ft_reverse_bits(void *pv, size_t elem_size);

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

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
void				ft_lstdelone(t_list **alst, void (*del) (void *, size_t));
void				ft_lstdelif(t_list **alst, void *ref_data,
						int (*cmp)(const void *, const void *),
						void (*del) (void *, size_t));
void				ft_lstdel(t_list **alst, void (*del) (void *, size_t));
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

void				ft_qsort(void *base, size_t nel, size_t width,
						int (*compar)(const void *, const void *));

#endif
