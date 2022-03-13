#ifndef LAB3_LIST_H__
#define LAB3_LIST_H__

struct INode {
  int value;
  struct INode* next;
};

struct INode* inode_new(int);

struct IList {
  struct INode* root;
  int size;
};

/**
 * Creates an IList representing the bit representation
 * of the given value in big endian. Note that the root
 * of the IList points to the most significant bit in
 * the list.
 */
struct IList* bit_list_from_value(int);

/**
 * Prints the IList values to stdout.
 */
void ilist_print(struct IList*);

struct IList* ilist_new();
void ilist_insert(struct IList*, int);

#endif // LAB3_LIST_H__
