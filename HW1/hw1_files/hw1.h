#ifndef HW1__

#include <math.h>

/**
 * P1 - compute the nth fibonacci number
 *
 * The first fibonacci number is 0, the second fibonacci number is 1,
 * and every subsequent fibonacci number is defined via the relation
 *
 * F(n+1) = F(n) + F(n-1)
 */
unsigned long fibonacci(long n) { return 0L; }

/**
 * P2 - compute the greatest common divisor (gcd) of two integers
 *
 * Given two integers, return their greatest common divisor.
 */
int gcd(int a, int b) { return -1; }

/**
 * P3 - compute the value of concatenated binary numbers.
 *
 * You are given a number n. Concatenate the binary representations
 * of all numbers from 1 to n, inclusive. Return the result modulo
 * 10^9 + 7.
 *
 * Ex.
 * n = 4 yields 11011100, which is equal to 220. Return 220.
 * The number 11011100 was consturcted via the binary representations:
 * [1 = 1][2 = 10][3 = 11][4 = 100] = 11011100
 *
 * Hint: you may find the following functions useful:
 *   - floor
 *   - log2
 *   - powl
 */
long concatenated_binary(int n) { return -1L; }

/**
 * P4 - sum binary numbers
 *
 * You are given to arrays of 1s and 0s representing binary numbers
 * in big endian (index 0 is the most significant). Return the result
 * of adding these two binary numbers together.
 *
 * Ex. Given [1, 1, 0] and [1], return 7 (= [1, 1, 1]).
 *
 * Note: you can assume both arrays are of the same length n
 */
long add_binary(int bits1[], int bits2[], unsigned int n) { return -1L; }

#endif // HW1__
