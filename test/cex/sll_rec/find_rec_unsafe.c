/* Copyright (c) Microsoft Corporation.  All rights reserved. */

#include "sll.h"

// return first link of x greater than n
PSLL_ENTRY find(PSLL_ENTRY x, int n) {
  PSLL_ENTRY r;

  if (x == NULL) return NULL;
  if (x->Data > n) return x;
  r = find(x->Flink, n);
  return r;
}

void main() {
  PSLL_ENTRY x = NULL, y = NULL;
  x = cons(4, x);
  x = cons(3, x);
  x = cons(2, x);
  assert( x==NULL);
  x = cons(1, x);
  y = find(x, 2);
  print_list(y);
}
