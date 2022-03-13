#include <stdio.h>
#include <sys/time.h>

#include "perf.h"

/**
 * Returns the runtime in nanoseconds to compute the inner product to the given
 * vectors using the specified product type.
 *
 * @param u Pointer to the first vector
 * @param v Pointer to the second vector
 * @param dest Pointer to the result
 * @param type Type of inner product to compute.
 *
 * @return the time in nanoseconds to compute the inner product.
 */
long time_product_nanos(vec_ptr u, vec_ptr v, data_t* dest, enum ProductType type) {
  struct timespec start, end;
  clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  switch (type) {
    case INNER:
      inner(u, v, dest);
      break;
    case INNER6x1:
      inner6x1(u, v, dest);
      break;
    case INNER6x6:
      inner6x6(u, v, dest);
      break;
    case INNER6x1a:
      inner6x1a(u, v, dest);
      break;
    default:
      fprintf(stderr, "Unknown ProductType - this should not happen\n");
  }
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);

  return (long) ((end.tv_sec - start.tv_sec) * 1000000000 +
        (end.tv_nsec - start.tv_nsec));
}


