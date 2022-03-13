#ifndef AUTOGRADER_H__

int check_longs(long expected, long actual, char* prefix) {
  if (prefix != NULL) {
    printf("%s ", prefix);
  }
  if (expected == actual) {
    printf("PASS\n");
    return 1;
  }
  printf("FAIL [Expected: %ld, Got: %ld]\n", expected, actual);
  return 0;
}

int check_ints(int expected, int actual, char* prefix) {
  if (prefix != NULL) {
    printf("%s ", prefix);
  }
  if (expected == actual) {
    printf("PASS\n");
    return 1;
  }
  printf("FAIL [Expected: %d, Got: %d]\n", expected, actual);
  return 0;
}

#endif // AUTOGRADER_H__
