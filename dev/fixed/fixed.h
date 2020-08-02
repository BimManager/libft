// Copyright 2020 kkozlov

#ifndef FIXED_H
# define FIXED_H

# include <limits.h>
# include <stdlib.h>
# include <inttypes.h>

# define IS_NEGATIVE(x, width) ((x) >> ((width) * CHAR_BIT - 1))

typedef union	u_fixed24_8
{
  int			bits;
  struct
  {
    unsigned	integer: 24;
    unsigned	fraction: 8;
  }				parts;
}				t_fixed24_8;

t_fixed24_8		*mult24_8(t_fixed24_8 *a, t_fixed24_8 *b);


/*
** fixed = round(float * scaling_factor)
** float = ((double)fixed) / scaling_factor
** (x * s) * (y * s)
** (x * s) / (y * s)
**
** int32_t	fixed_mul16(int32_t x, int32_t y)
** {
**   return (((uint64_t)x * (uint64_t)y) / (1 << 16));
** }
**
** int32_t	fixed_div16(int32_t x, int32_t y)
** {
**   return (((uint64_t)x * (1 << 16)) / y);
** }
*/
  
#endif

