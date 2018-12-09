#if 0

ft_isprint.c

#endif

int	ft_isprint(int c)
{
  if (c >= ' ' && c <= '~') 
    return (c);
  return (0); 
}
