/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:38:10 by kkozlov           #+#    #+#             */
/*   Updated: 2018/11/14 15:03:01 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int				ft_atoi(char *str);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
int				ft_is_whitespace(char c);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
char			**ft_split_whitespaces(char *str);
int				ft_is_alpha(char c);
int				ft_str_is_alpha(char *str);
int				ft_is_lowercase(char c);
int				ft_str_is_lowercase(char *str);
int				ft_is_digit(char c);
int				ft_str_is_numeric(char *str);
int				ft_is_printable(char c);
int				ft_str_is_printable(char *str);
int				ft_is_uppercase(char c);
int				ft_str_is_uppercase(char *str);
char			*ft_strcapitalize(char *str);
char			*ft_strdup(char *str);
char			*ft_strcat(char *dest, char *src);	
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcpy(char *dest, char *src);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
int				ft_strlen(char *str);
char			*ft_strstr(char *str, char *to_find);
char			*ft_strlowcase(char *str);
char			*ft_strncat(char *dest, char *src, int nb);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strupcase(char *str);
void			ft_swap(int *a, int *b);

int				ft_is_prime(unsigned int nb);

void			ft_print_bit_pattern(void *pv, unsigned int elem_size);
void			ft_set_bit(void *pv, unsigned int elem_size, unsigned int bit_pos);
void			ft_zero_bit(void *pv, unsigned int elem_size, unsigned int bit_pos);
int				ft_test_bit(void *pv, unsigned int elem_size, unsigned int bit_pos);
void			ft_reverse_bits(void *pv, unsigned int elem_size);

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

#endif 
