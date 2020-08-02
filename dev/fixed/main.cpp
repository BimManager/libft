// Copyright 2020 kkozlov

#include <stdio.h>

#include "fixed.h"

int	main(void)
{
  t_fixed24_8	fixed;

  fixed.bits = 32;
  printf("integer: %d fraction: %d\n",
         fixed.parts.integer,
         fixed.parts.fraction);
  return (0);
}
