/* Copyright (c) Microsoft Corporation.  All rights reserved. */

/* Similar to remove, but does not destroy the list. */

#include "../../csll/csll.h"


void CSLL_remove(PSLL_ENTRY head, int fo) {
  PSLL_ENTRY prev, entry, tmp;

  prev = head;
  entry = head->Flink;
  while( entry != head ) {
    if( entry->Data == fo ) {
      /* remove entry */
      free(entry);
      tmp = entry->Flink;
      prev->Flink = tmp;
      entry = tmp;
    } else {
      prev = entry;
      entry = entry->Flink;
    }
  }
}


void main() {
  PSLL_ENTRY head, tail;

  tail = (PSLL_ENTRY)malloc(sizeof(SLL_ENTRY));
  head = SLL_create_seg(nondet(), tail);
  tail->Flink = head;

  CSLL_remove(head, 42);

/*   CSLL_destroy(head); */
}
