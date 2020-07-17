// Copyright 2020 kkozlov

unsigned long		sdbm(const char *str)
{
  unsigned long	hash;

  hash = 0;
  while (*str)
    hash = *str++ + (hash << 6) + (hash << 16) - hash;
  return (hash);
}
