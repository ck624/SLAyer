/**
  Copyright (c) Microsoft Corporation.  All rights reserved.

  Create, reverse, and then destroy a singly-linked list.

  Similar to reverse_leak.c but chooses leaked item nondeterministically.
**/

#include "sll.h"


void reverse(PSLL_ENTRY *l) {
  PSLL_ENTRY c = *l, r = NULL;
  while(c != NULL) {
    PSLL_ENTRY t;
    t = c;
    c = c->Flink;
    if (nondet()) { /* leak t */
      t->Flink = r;
      r = t;
    }
  }
  *l = r;
}

void main() {
  PSLL_ENTRY head;

  head = SLL_create(nondet());

  reverse(&head);

  SLL_destroy(head);
}
