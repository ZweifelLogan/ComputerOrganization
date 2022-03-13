#include <stdio.h>
#include <sys/time.h>

#include "perf.h"
#include "vector.h"

// TODO: You should modify this for your computer.
#define VEC_SIZE 1000000

// Note: this doesn't actually compute true CPE but is close enough
// for our purposes. What this _really_ prints is nanoseconds per element.
// These numbers _should not_ be compared directly with the numbers from
// the book!
double compute_cpe(long nanos) {
  return (double) nanos / VEC_SIZE;
}

double average(double* vals, int n) {
  double total = 0.0;
  for (int i = 0; i < n; i++) total += vals[i];
  return total / n;
}

int main() {
  int N_REPEATS = 5;
  struct Vector v1 = random_vec(VEC_SIZE);
  struct Vector v2 = random_vec(VEC_SIZE);

  print_vector(&v1);
  print_vector(&v2);

  // It is generally a good idea to run your "benchmark" code a number
  // of times. There are a number of things that can impact your results
  // such as cache effects and fluctuations to CPU clock speed (e.g.,
  // Intel's TurboBoost is not always on - it takes time for it to speed
  // up).
  printf("Standard inner product.\n");
  double results[N_REPEATS];
  for (int i = 0; i < N_REPEATS; i++) {
    data_t result;
    long t1 = time_product_nanos(&v1, &v2, &result, INNER);
    printf("Execution took %ld nanoseconds\n", t1);
    results[i] = compute_cpe(t1);
  }
  printf("Average CPE: %lf\n", average(results, N_REPEATS));

  return 0;
}
