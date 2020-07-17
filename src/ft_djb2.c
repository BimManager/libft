// Copyright 2020 kkozlov

unsigned long		djb2(const char *str)
{
  unsigned long	hash;

  hash = 5381;
  while (*str)
    hash = ((hash << 5) + hash) + *str++;
  return (hash);
}
