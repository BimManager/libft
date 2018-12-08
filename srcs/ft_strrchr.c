#if 0

ft_strrchr.c

#endif

char *ft_strrchr(char *s, int c)
{
  char *pb;

  pb = s;
  while (*s)
    ++s;
  while ((*s != (char)c) && s > pb)
    --s;
  return (*s == (char)c ? s : 0);
} 
