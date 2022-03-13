#include <stdio.h>

#include "autograder.h"
#include "hw1_sol.h"

int main() {
  int score = 0;
  int n_questions = 6;

  // Fibonacci
  score += check_longs(0, fibonacci(1), "fib1");
  score += check_longs(1, fibonacci(2), "fib2");

  // GCD
  score += check_ints(2, gcd(4, 2), "gcd1");
  score += check_ints(21, gcd(21, 42), "gcd2");

  // Concatenated Binary
  score += check_longs(220, concatenated_binary(4), "concat_binary1");

  // Sum binary
  int b1[] = {1, 1, 0};
  int b2[] = {0, 0, 1};
  score += check_longs(7, add_binary(b1, b2, 3), "sum_binary1");

  printf("%d/%d (%f %%)\n", score, n_questions, score / 6.0f);
  return 0;
}
