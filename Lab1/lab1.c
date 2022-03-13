#include <stdio.h>

// Lab 1

/**
 * Prints an array of `n` elements as:
 *  [ 1 2 3 4 ]
 * with a newline after the closing ]
 */
void print_array(short arr[], unsigned int n) {



	printf("[ ");
	for (int i=0; i < n; i++) {
		arr[i] = i + 1;
		printf("%d ", arr[i]);
	}
	printf("]\n");

}


/**
:* Populates `arr` with the bits of n.
 *
 * For example, the short 9 has the representation 0b0000000000001001
 * so the array should be populated as [ 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 ].
 *
 * Note that this is a void function. We are somehow passing a
 * reference to the array into this function. We will learn more about this
 * in the coming weeks.
 */
void populate_bits(short arr[], short n) {
	for (int i = 0; i < n; i++){
		arr[i] = 1 << (15 - i);
		if (arr[i] & n) {
			arr[i] = 1;
		} else {
			arr[i] = 0;
		}
	}
	printf("[ ");
	for (int i = 0; i < 16; i++) {
		printf("%hi ", arr[i]);
	}	
	printf("]\n");

}

int main() {
	
	short i = 0b1001;
	short arr[16];
	populate_bits(arr, i);
	print_array(arr, 16);

	return 0;
}
