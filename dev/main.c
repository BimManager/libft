/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 10:25:40 by kkozlov           #+#    #+#             */
/*   Updated: 2018/11/15 15:07:36 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "ft_lib.h"
#include "ft_tqueue.h"

int		ft_del_substr(char *str, char const *substr);
void	ft_swap_gen(void *pv1, void *pv2, unsigned int elem_size); 
void	ft_str_reverse(char *str);

typedef struct s_stack
{
	int top;
	unsigned int size;
	int *elems;
} t_stack;

void	free_str(void *pv)
{
	free(*(char**)pv);
}

int		main(void)
{
#if 0
	while ((ret = read(0, buf, 254)))
	{
		if (buf[0] == '\n')
			break ;
		buf[ret] = 0x00;
		ft_strcapitalize(buf);
		write(1, buf, ret);
	}
	int a = 42;
	int *pa = &a;
	int *p = (int*)0x7ffeed285854;
#endif
#if 0


	char *s2 = "bar";
	char *s3 = "baz";

	char s1[] = "ABCDEFG";
	char *s1 = 0;
	char *s2 = "foo";
	ft_del_substr(s1, s2);
	ft_putstr(s1);
	ft_putchar('\n');
#endif
	char s3[] = "man";
	char s4[] = "cook";
	char s5[] = "reverse";
	ft_swap_gen(s3, s4, 3);
	ft_putstr(s3);
	ft_putchar('\n');
	ft_putstr(s4);
	ft_putchar('\n');
	ft_str_reverse(s5);
	ft_putstr(s5);
	ft_putchar('\n');
	return (0);
}
