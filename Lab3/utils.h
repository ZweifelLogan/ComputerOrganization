#ifndef LAB3_UTILS_H__
#define LAB3_UTILS_H__

#include <stdio.h>

#include "list.h"

void print_array(int*, int);

/**
 * Fails to swap the values of the given ints.
 */
void broken_swap(int, int);

/**
 * Swaps the values of the given pointers.
 */
void swap(int*, int*);

/**
 * Given an IList pointer storing the binary representation
 * of a number in big endian, return the value of the number.
 *
 * You may assume you are always given valid input.
 */
int value_from_ilist(struct IList*);

#endif // LAB3_UTILS_H__
