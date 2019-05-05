/*
 *	htbl.c
 *	hast table implementation
 */

#include "htbl.h"

static t_nlink	*htbl_get_nlink(t_htbl *htbl, char *key);

t_nlink		*nlink_new(char *key, 
		void *content,
		size_t content_size)
{
  t_nlink	*new;

  if (!(new = malloc(sizeof(t_nlink))))
    return (NULL);
  new->key = ft_strdup(key);
  new->val = ft_lstnew(content, content_size);
  new->next = NULL;
  return (new);
}

void		nlink_add(t_nlink **link, t_nlink *new)
{
  if (!*link)
    {
      *link = new;
      return ;
    }
  new->next = *link;
  *link = new;
}

void		nlink_delone(t_nlink **link,
		void (*del)(void *, size_t))
{
  t_nlink	*tmp;

  if (!*link)
    return ;
  tmp = (*link)->next;
  free((*link)->key);
  ft_lstdel(&(*link)->val, del);
  free(*link);
  *link = tmp;
}

t_htbl		*htbl_new(size_t n,
		unsigned (*hash_fn)(char *, size_t))
{
  t_htbl	*new;

  if (!(new = malloc(sizeof(t_htbl))))
    return (NULL);
  new->size = n;
  if (!(new->fst = malloc(new->size * sizeof(void *))))
    {
      free(new);
      return (NULL);
    }
  new->hash_fn = hash_fn;
  ft_bzero(new->fst, new->size * sizeof(void *));
  return (new);
}

void		htbl_addkey(t_htbl *htbl,
		char *key, void *content,
		size_t content_size)
{
  t_nlink	*new;
  unsigned	hashval;

  if ((new = htbl_get_nlink(htbl, key)))
    {
      /* UNDER DEVELOPMENT */
      return ;
    }
  hashval = htbl->hash_fn(key, htbl->size);
  new = nlink_new(key, content, content_size);
  nlink_add(htbl->fst + hashval, new);
}

static t_nlink	*htbl_get_nlink(t_htbl *htbl, char *key)
{
  size_t	hashval;
  t_nlink	*ret;

  hashval = htbl->hash_fn(key, htbl->size);
  if ((ret = *(htbl->fst + hashval)))
    {
      while (ret)
	{
	  if (!ft_strcmp(ret->key, key))
	    return (ret);
	  ret = ret->next;
	}
    }
  return (NULL);
}

t_list		*htbl_lookup(t_htbl *htbl, char *key)
{
  t_nlink	*ret;

  ret = htbl_get_nlink(htbl, key);
  return (ret ? ret->val : NULL);
}

t_list		*htbl_keys(t_htbl *htbl)
{
  t_nlink	*it;
  t_list	*ret;
  size_t	i;
  
  ret = NULL;
  i = -1;
  while (++i < htbl->size)
    {
      it = *(htbl->fst + i);
      while (it)
	{
	  ft_lstadd(&ret, ft_lstnew(it->key, ft_strlen(it->key) + 1));
	  it = it->next;
	}
    }
  return (ret);
}

void		htbl_delkey(t_htbl *htbl, char *key,
		void (*del)(void *, size_t)) 
{
  size_t	hashval;
  t_nlink	*it;
  t_nlink	*prv;
  

  hashval = htbl->hash_fn(key, htbl->size);
  prv = NULL;
  if (!(it = *(htbl->fst + hashval)))
    return ;
  while (it)
    {
      if (!ft_strcmp(it->key, key))
	{
	  if (!prv)
	    nlink_delone(htbl->fst + hashval, del);
	  else
	    nlink_delone(&it, del);
	  return ;
	}
      prv = it;
      it = it->next;
    }
}

void		htbl_dealloc(t_htbl **htbl,
		void (*del)(void *, size_t))
{
  t_nlink	*it;
  size_t	i;

  i = (*htbl)->size;
  while (i--)
    {
      it = *((*htbl)->fst + i);
      while (it)
	{
	  ft_putstr("TO DELETE: ");
	  ft_putendl(it->key);
	  nlink_delone(&it, del);
	}
    }
  free(*htbl);
  *htbl = NULL;
}
