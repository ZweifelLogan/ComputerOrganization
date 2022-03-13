#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* create_byte_array(long size) {
  char* xs = (char*) malloc(sizeof(char) * size);
  for (long i = 0; i < size; i++) xs[i] = (char) 1;
  return xs;
}

struct TimeResult {
  uint64_t elapsed_ns;
  long result;
  long block_sz;
  int n_ops_per_block;
};

void fisher_yates_shuffle(long* xs, long sz) {
  srand(time(NULL));
  for (long i = 0; i < sz; i++) {
    long idx = (long) ((rand() / RAND_MAX) * (sz - i)) + i;
    xs[i] = idx;
  }
}

/**
 * This function sums the values of `xs` in blocks of size `block_sz`.
 * For each block, it will sum `n_ops` values. The values are chosen at
 * random and the indices are pre-generated. The goal is not to
 * compute any specific sum but to time the random sampling within the
 * block. The larger the block, the more spread out the sampling.
 *
 * @param array_sz size of the array being sample-summed. This is set
 *                 at 100 * block_sz.
 * @param block_sz size of the block from which samples are drawn.
 * @param n_ops numbs of values to sample from the block.
 * @param xs the array of values
 * @return the sum sampled.
 *
 */
long strided_sum(long array_sz, long block_sz, long n_ops, char* xs) {
  long total = 0;

  long* offsets = (long*) malloc(sizeof(long) * block_sz);
  for (unsigned int i = 0; i < block_sz; i++) offsets[i] = i;
  fisher_yates_shuffle(offsets, block_sz);

  for (long i = 0; i < array_sz; i += block_sz) {
    for (long j = 0; j < n_ops; j++) {
      total += xs[offsets[j % block_sz]];
    }
  }
  return (long )total / n_ops;
}

/**
 * Times the call to `strided_sum`.
 */
struct TimeResult time_strided_sum(long block_sz, int n_ops) {
  long array_sz = block_sz * 100;
  char* xs = create_byte_array(array_sz);
  struct timespec start, end;
  clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  long result = strided_sum(array_sz, block_sz, n_ops, xs);
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);
  uint64_t elapsed_ns = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
  struct TimeResult tr = { elapsed_ns, result, block_sz, n_ops };
  return tr;
}

struct TimeResult average_timed_strided_sum(long stride_sz, int n_ops, int n_trials) {
  long total_time = 0;
  long result;
  for (int i = 0; i < n_trials; i++) {
    struct TimeResult t = time_strided_sum(stride_sz, n_ops);
    total_time += t.elapsed_ns;
    result = t.result;
  }
  struct TimeResult tr = { (long) total_time / n_trials, result, stride_sz, n_ops };
  return tr;
}

void print_time_result(struct TimeResult tr) {
  double avg_elapsed_s = tr.elapsed_ns / tr.n_ops_per_block;
  printf("TimeResult{ elapsed_ns (avg per block): %lf, result: %ld, stride_sz: %ld, n_ops: %d }\n",
      avg_elapsed_s, tr.result, tr.block_sz, tr.n_ops_per_block);
}

int main() {
  int n_trials = 64;
  int max_block_size = 1028;
  for (int n_ops = 100; n_ops < 10000; n_ops *= 10) {
    for (long block_sz = 16; block_sz <= max_block_size; block_sz *= 2) {
      struct TimeResult tr = average_timed_strided_sum(block_sz, n_ops, n_trials);
      print_time_result(tr);
    }
  }
  return 0;
}
