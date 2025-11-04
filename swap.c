#include <stdio.h>

int main() {
	// Define them numbers
	int a = 4;
	int b = 6;
	printf("a = %d\n", a);
	printf("b = %d\n", b);

	// Magic stuff - Swap
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;

	// Print the magic
	printf("\na = %d\n", a);
	printf("b = %d\n", b);

	return 0;
}
