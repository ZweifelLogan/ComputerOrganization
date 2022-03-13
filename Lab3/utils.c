#include <stdlib.h>

#include "list.h"
#include "utils.h"

void print_array(int* arr, int n) {
  printf("[ ");
  for (int i = 0; i < n; i++) printf("%d ", arr[i]);
  printf("]\n");
}


