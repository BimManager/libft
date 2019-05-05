/*
 *	htbl.h
 *	hast table implementation
 */

#ifndef HTBL_H
# define HTBL_H

#include "libft.h"

typedef struct		s_nlink
{			
  char			*key;
  t_list		*val;
  struct s_nlink	*next;
}			t_nlink;

typedef struct		s_htbl
{
  size_t		size;
  t_nlink		**fst;
  unsigned		(*hash_fn)(char *, size_t);
}			t_htbl;

t_nlink			*nlink_new(char *key,
			void *content,
			size_t content_size);
void			nlink_add(t_nlink **link, t_nlink *new);
void			nlink_delone(t_nlink **link,
			void (*del)(void *, size_t));

t_htbl			*htbl_new(size_t n,
			unsigned (*hash_fn)(char *, size_t));
void			htbl_addkey(t_htbl *htbl,
			char *key, void *content,
			size_t content_size);
t_list			*htbl_lookup(t_htbl *htbl,
			char *key);
t_list			*htbl_keys(t_htbl *htbl);
void			htbl_delkey(t_htbl *htbl, char *key,  
			void (*del)(void *, size_t));
void			htbl_dealloc(t_htbl **htbl,
			void (*del)(void *, size_t));

#endif
