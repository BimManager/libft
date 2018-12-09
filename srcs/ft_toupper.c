#if 0

ft_toupper.c

#endif

int	ft_toupper(int c)
{
  if (c >= 'a' && c <= 'z')
    return (c - ('a' - 'A'));
  return (c); 
}
