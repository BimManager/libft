#if 0

ft_isalpha.c

#endif

int	ft_isalpha(int c)
{
  if ((c >= 'A' && c <= 'Z') 
	|| (c >= 'a' && c <= 'z'))
    return (c);
  return (0); 
}
