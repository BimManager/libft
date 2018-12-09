#if 0

ft_isalnum.c

#endif

int	ft_isalnum(int c)
{
  if ((c >= 'A' && c <= 'Z') 
	|| (c >= 'a' && c <= 'z')
	|| (c >= '0' && c <= '9'))
    return (c);
  return (0); 
}
