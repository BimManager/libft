/*
	main.c
	To test my hashtable
	implementation and 
	the ft_memdup function
*/

#include "htbl.h"

#define HASH_SIZE 128

static unsigned		ft_hash(char *s, size_t size);
static void		free_content(void *, size_t);
static void		lstprnt(t_list *node);
static void		test_htbl();

int			main(void)
{
  char		*car_model;
  char		*dup;
  char		*str;
  size_t	len;
  
  str = "foo, bar, baz";
  len = ft_strlen(str) + 1;
  car_model = malloc(len * sizeof(char));
  ft_strlcpy(car_model, str, len);
  dup = ft_memdup(car_model, len);
  free(car_model);
  ft_putendl(dup);
  free(dup);
  test_htbl();
  return (0);
}

static unsigned		ft_hash(char *s, size_t size)
{
  unsigned	hashval;

  hashval = 0;
  while (*s)
    hashval = *s++ + 31 * hashval;
  return (hashval % size);
}

static void	free_content(void *content, size_t content_size)
{
  if (content_size)
    free(content);
}

static void	lstprnt(t_list *node)
{
  ft_putstr("key: ");
  if (node && node->content_size)
    ft_putendl((char *)node->content);

}

static void	test_htbl()
{
  char		*key1;
  char		*key2;
  char		*key3;
  char		*content1;
  char		*content2;
  t_list	*ret;
  t_htbl	*htbl;

  htbl = htbl_new(HASH_SIZE, &ft_hash);
  key1 = "foo";
  key2 = "bar";
  key3 = "rubbush";
  content1 = "quantum computing";
  content2 = "functional programming";
  htbl_addkey(htbl, key1, content1, ft_strlen(content1) + 1);
  htbl_addkey(htbl, key2, content2, ft_strlen(content2) + 1);
  ret = htbl_lookup(htbl, key1);
  if (ret)
    ft_putendl((char *)ret->content);
  ret = htbl_lookup(htbl, key2);
  if (ret)
    ft_putendl((char *)ret->content);
  ret = htbl_lookup(htbl, key3);
  if (ret)
    ft_putendl((char *)ret->content);
  else
    ft_putendl("No key");
  htbl_addkey(htbl, "wow", "What\'s up?", 10);
  t_list	*keys;

  keys = htbl_keys(htbl);
  if (keys)
    ft_lstiter(keys, &lstprnt);
  ft_lstdel(&keys, &free_content);
  ft_putendl("__________________________");
  htbl_delkey(htbl, key1, &free_content);
  keys = htbl_keys(htbl);
  if (keys)
    ft_lstiter(keys, &lstprnt);
  ft_putendl("__________________________");
  ft_lstdel(&keys, &free_content);
  htbl_delkey(htbl, key2, &free_content);
  keys = htbl_keys(htbl);
  if (keys)
    ft_lstiter(keys, &lstprnt);
  ft_putendl("__________________________");
  ft_lstdel(&keys, &free_content);
  htbl_addkey(htbl, "wow", "What\'s up?", 10);
  htbl_addkey(htbl, "wow", "How is tricks?", 10);
  htbl_addkey(htbl, "wow", "What\'s up?", 10);
  ft_putendl(htbl_lookup(htbl, "wow")->content);
  keys = htbl_keys(htbl);
  if (keys)
    ft_lstiter(keys, &lstprnt);
  ft_putendl("__________________________");
  ft_lstdel(&keys, &free_content);
  htbl_dealloc(&htbl, &free_content);
}


