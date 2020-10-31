/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmergesort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 16:28:22 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/17 11:41:52 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		lstsplit(t_list *head, t_list **a, t_list **b)
{
  t_list	*fast;
  t_list	*slow;

  fast = head;
  slow = head;
  while ((fast = fast->next))
  {
    if (!(fast = fast->next))
      break ;
    slow = slow->next;
  }
  *a = head;
  *b = slow->next;
  slow->next = NULL;
}

static t_list	*lstmerge(t_list *a, t_list *b, int (*cmp)(void *, void*))
{
  t_list	*ret;

  if (!a)
    return (b);
  if (!b)
    return (a);
  if (cmp(a->content, b->content) <= 0)
  {
    ret = a;
    ret->next = lstmerge(a->next, b, cmp);
  }
  else
  {
    ret = b;
    ret->next = lstmerge(a, b->next, cmp);
  }
  return (ret);
}

static void		lstsort(t_list **head, int (*cmp)(void *, void *))
{
  t_list	*a;
  t_list	*b;

  if (!*head || !(*head)->next)
    return ;
  lstsplit(*head, &a, &b);
  lstsort(&a, cmp);
  lstsort(&b, cmp);
  *head = lstmerge(a, b, cmp);
}

t_list			*ft_lstmergesort(t_list *head, int (*cmp)(void *, void *))
{
  if (!head)
    return (head);
  lstsort(&head, cmp);
  return (head);
}
