// Copyright 2020 kkozlov

#include "fixed.h"

t_fixed24_8		*mult24_8(t_fixed24_8 *a, t_fixed24_8 *b)
{
  char			sign;
  unsigned		tmp;
  t_fixed24_8	*product;

  sign = IS_NEGATIVE(a->bits, sizeof(int))
      ^ IS_NEGATIVE(b->bits, sizeof(int));
  product = malloc(sizeof(t_fixed24_8));
  tmp = ((uint64_t)(a->bits) * (uint64_t)(b->bits)) >> CHAR_BIT;
  if (sign)
    tmp |= (1U << (sizeof(int) * CHAR_BIT - 1));
  product->bits = tmp;
  return (product);
}
