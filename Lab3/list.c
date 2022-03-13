#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct INode* inode_new(int v) {
  struct INode* n = (struct INode*) malloc(sizeof(struct INode));
  if (n == NULL) {
    perror("Failed to allocated INode node.");
    exit (EXIT_FAILURE);
  }
  n->value = v;
  return n;
}

struct IList* ilist_new() {
  struct IList* l = (struct IList*) malloc(sizeof(struct IList));
  if (l == NULL) {
    perror("Failed to allocate IList node.");
    exit (EXIT_FAILURE);
  }
  l->root = NULL;
  l->size = 0;
  return l;
}

void ilist_insert(struct IList* l, int v) {
  struct INode* n = inode_new(v);
  n->next = l->root;
  l->root = n;
  l->size++;
}

struct IList* bit_list_from_value(int v) {
  struct IList* l = ilist_new();

  int mask = 1;
  while (mask < v) {
    ilist_insert(l, v & mask ? 1 : 0);
    mask <<= 1;
  }
  return l;
}

void ilist_print(struct IList* l) {
  printf("[ ");
  struct INode* runner = l->root;
  while (runner != NULL) {
    printf("%d ", runner->value);
    runner = runner->next;
  }
  printf("]\n");
}
