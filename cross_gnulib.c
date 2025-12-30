typedef void rtx;
#include "bogus-flags.h"
#include <stdlib.h>

#if (HAVE_umulsi3 == 0)
unsigned long
__umulsi3 (a, b)
     unsigned long a, b;
{
#if HAVE_umulhisi3
  unsigned short ahi,alow,bhi,blow;
  unsigned long acc;

  ahi = (a >> 16);
  alow = ( a & 0xFFFF);
  bhi = (b >> 16);
  blow = ( b & 0xFFFF);

  acc = (ahi * blow);
  acc += (alow * bhi);
  acc <<= 16;
  acc += alow * blow;
#else
  unsigned long acc,ent,bitsel;

  acc = 0;
  bitsel = 1;
  ent = a;
  while ( bitsel && (bitsel <= b) ) {
      if ( b & bitsel ) acc += ent;
      ent += ent;
      bitsel += bitsel;
  }
#endif
  return acc;
}
#endif

