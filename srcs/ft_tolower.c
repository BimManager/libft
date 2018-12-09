#if 0

ft_tolower.c

#endif

int	ft_tolower(int c)
{
  if (c >= 'A' && c <= 'Z')
    return (c + ('a' - 'A'));
  return (c); 
}
