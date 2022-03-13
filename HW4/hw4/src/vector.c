#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "vector.h"

data_t* get_vec_start(vec_ptr p) {
  return p->data;
}

long vec_length(vec_ptr p) {
  return p->size;
}

struct Vector random_vec(long size) {
  static bool once_token = false;
  if (!once_token) {
    srand((unsigned int) time(NULL));
    once_token = true;
  }

  data_t* data = (data_t*) malloc(sizeof(data_t) * size);
  struct Vector v = { data, size };

  for (long i = 0; i < size; i++) {
    data[i] = (data_t  )(((double) rand() / RAND_MAX) * 100.0);
  }
  return v;
}

void print_vector(vec_ptr p) {
  long size = vec_length(p);
  data_t* d = get_vec_start(p);
  printf("[ ");
  if (size <= 10) {
    for (long i = 0; i < size; i++)
      printf("%lf ", (double) d[i]);
  } else {
    for (long i = 0; i < 9; i++)
      printf("%lf ", (double) d[i]);
    printf("... ");
    printf("%lf ", (double) d[size - 1]);
  }
  printf("]\n");
}

// This function is implemented for you to give you an idea of how
// the other functions will look.
void inner(vec_ptr u, vec_ptr v, data_t* dest) {
   assert(vec_length(u) == vec_length(v));

   long size = vec_length(u);
   data_t* du = get_vec_start(u);
   data_t* dv = get_vec_start(v);
   data_t sum = (data_t) 0;

   for (long i = 0; i < size; i++)
     sum = sum + du[i] * dv[i];

   *dest = sum;
}

// Problem 5.14
void inner6x1(vec_ptr u, vec_ptr v, data_t* dest) {
  // You can assume your vectors are the same length (as required by this assert)
  assert(vec_length(u) == vec_length(v));
}

// Problem 5.15
void inner6x6(vec_ptr u, vec_ptr v, data_t* dest) {
  // You can assume your vectors are the same length (as required by this assert)
  assert(vec_length(u) == vec_length(v));
}

// Problem 5.16
void inner6x1a(vec_ptr u, vec_ptr v, data_t* dest) {
  // You can assume your vectors are the same length (as required by this assert)
  assert(vec_length(u) == vec_length(v));
}

