#if 0

ft_strchr.c

#endif

char *ft_strchr(char *s, int c)
{
  while ((*s != (char)c) && *s)
    ++s;
  return (*s == (char)c ? s : 0);
} 
