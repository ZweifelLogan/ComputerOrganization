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
unsigned long fibonacci(long n) { 
    //recursive function
    n = n - 1;

    //base case
    if (n == 1) {
        return n;
    } else if ( n < 1 ) {
        return 0;
    } else {
        //recursive step
        return fibonacci(n-1) + fibonacci(n-2);
    } 
}

/**
 * P2 - compute the greatest common divisor (gcd) of two integers
 *
 * Given two integers, return their greatest common divisor.
 */
int gcd(int a, int b) { 
    //recursive function
    
    //base case
    if (a % b == 0) {
        return b;
    } else {
        //recursive step
        return gcd(b, a % b);
    }
       
}

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
long concatenated_binary(int n) { 
    
    // result of binary concatenation
    long result = 1;

    // calculates and contcatenate's binary 2 to n
    for (int i = 2; i <= n; i++) {
        result = result * powl(10, (floor(log2(i))) + 1); 

        int temp = i;
        long temp2 = 0;
        do {
           temp2 = temp2 + powl(10, floor(log2(temp)));
           temp = temp - powl(2, floor(log2(temp)));
        } while (temp > 0);

        result = result + temp2;    
    }

    // takes concatenated binary number and makes it into decimal representation
    // final result that will be returned
    long finalResult = 0;
    int count = 0;
    while (result != 0) {
        finalResult = finalResult + ((result % 10) * powl(2, count));
        result = result / 10;
        count++;
    }

    return finalResult;
}

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
long add_binary(int bits1[], int bits2[], unsigned int n) { 
    
    // result to be returned
    unsigned long result = 0;

    // loop adds the two arrays and calculates result
    for ( int i = 0; i < n; i++ ) {
        
        // sum of the 'column' being added during current iteration
        // sum can result in 4 different cases
        unsigned int sum = bits1[n-1-i] + bits2[n-1-i];

        if ( sum == 0 ) { // case 1: no actions needed
            result = result;
        
        } else if ( sum == 1 ) { // case 2: add 2^i to result
            result = result + pow(2,i);
        
        } else if ( sum == 2 ) { // case 3: 'carry' the 1 by incrementing one index in the
            // next column iterated, must also determine if final iteration to prevent error
            
            if ( i == (n-1) ) { //final iteration
                result = result + pow(2,(i+1));
            
            } else { //not the final iteration
                bits1[n-1-i]++;
            }
        
        } else { // case 4: sum is 3, 'carry' the 1 and calculate for current column
            //must determine if in final iteration

            if ( i == (n-1) ) { //final iteration
                result = result + pow(2, i);
                result = result + pow(2, (i+1));
            
            } else { // not final iteration
                result = result + pow(2,i);
                bits1[n-1-i]++;
            }
        } 
    }
    return result;
}

#endif // HW1__
