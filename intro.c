// Standard input/output
#include <stdio.h>

int main() {
	// Chars should only be wrapped in single quotes
	char g = 'g';
	printf("%c\n", g); // The format specifier for char is %c, %d or %i for int, %f or %F for float, %s for strings, %lf for double

	// \n for new line, \t to insert tab, \" to insert double quotes
	printf("Hello C\n");

	// Declaring multiple variables at the same time
	int x = 5, y = 6, z = 50; // Dont forget your semicolons
	// Add all them values
	printf("%d\n", x + y + z);

	// Student data
	int studentID = 15;
	int studentAge = 23;
	float studentFee = 75.25;
	char studentGrade = 'B';

	// Print variables
	printf("Student id: %d\n", studentID);
	printf("Student age: %d\n", studentAge);
	printf("Student fee: %f\n", studentFee);
	printf("Student grade: %c\n", studentGrade);

	// Calculate the area of a rectangle
	int length = 4;
	int width = 3;

	// Get the area
	int area = length * width;

	// Print the output
	printf("Area is %d\n", area);

	// Using ASCII values with chars - Note this do not need quotes as they are numbers
	char a = 65, b = 66, c = 67;
	printf("%c\n", a);
	printf("%c\n", b);
	printf("%c\n", c);

	// Note that if you try to print more than one character in a char variable, it will print the last character, orrrr just print an error
	// a = 'Hello' - Prints an error
	a = 'H';
	printf("%c\n", a);

	// To store multiple characters, use strings which is just a list of characters and you can use double quotes
	char mystr[] = "Hello";
	printf("%s\n", mystr);

	// Doubles have a higher precision than floats, but takes up more memory
  double myNum = 19.99;
	printf("%lf\n", myNum);

	// In C, you can write very large or very small floating-point numbers using scientific notation.

	// This is done using the letter e (or E), which stands for "times 10 to the power of".

	// For example, 35e3 means 35 × 10³ = 35000.

	// This is useful for writing numbers in a shorter way. Especially when working with scientific values or large-scale data.

	float f1 = 35e3;   // 35 * 10^3 = 35000
	double d1 = 12E4;  // 12 * 10^4 = 120000

	printf("%f\n", f1);
	printf("%lf\n", d1);

	// Doubles show many more numbers after the floating point that floats because it has a higher precision
	// E.g.
	float myFloatNum = 3.5;
	double myDoubleNum = 19.99;

	printf("%f\n", myFloatNum); // Outputs 3.500000
	printf("%lf\n", myDoubleNum); // Outputs 19.990000

	// If you want to remove the extra zeros (set decimal precision), you can use a dot (.) followed by a number that specifies how many digits that should be shown after the decimal point:
	float myFloatNumber = 3.5;

	printf("%f\n", myFloatNumber);   // Default will show 6 digits after the decimal point
	printf("%.1f\n", myFloatNum); // Only show 1 digit
	printf("%.2f\n", myFloatNum); // Only show 2 digits
	printf("%.4f\n", myFloatNum);   // Only show 4 digits
	//
	// %zu should be used when returning size_t values, from like sizeof()
	int size = 10;
	printf("%zu\n", sizeof(size));

	// Here's a real-life example of using different data types, to calculate and output the total cost of a number of items:

	// Create variables of different data types
	int items = 50;
	float cost_per_item = 9.99;
	float total_cost = items * cost_per_item;
	char currency = '$';

	// Print variables
	printf("Number of items: %d\n", items);
	printf("Cost per item: %.2f %c\n", cost_per_item, currency);
	printf("Total cost = %.2f %c\n", total_cost, currency);

	// Manual conversion: int to float
	float sum = (float) 5 / 2;

	printf("%f\n", sum); // 2.500000
	// Without the explicit conversion the output would have been 2.00000
	//
	// Set the maximum possible score in the game to 500
	int maxScore = 500;

	// The actual score of the user
	int userScore = 423;

	/* Calculate the percantage of the user's score in relation to the maximum available score.
Convert userScore to float to make sure that the division is accurate */
	float percentage = (float) userScore / maxScore * 100.0;

	// Print the percentage
	printf("User's percentage is %.2f\n", percentage);

	int normalInt = 1000;                       // standard int
	double normalDouble = 3.14;                 // standard double

	short int small = -100;                     // smaller int
	unsigned int count = 25;                    // only positive int
	long int big = 1234567890;                  // larger int
	long long int veryBig = 9223372036854775807; // very large int
	unsigned long long int huge = 18446744073709551615U; // very large, only positive
	long double precise = 3.141592653589793238L; // extended precision

	printf("Normal int: %d\n", normalInt);
	printf("Normal double: %lf\n", normalDouble);
	printf("Small: %hd\n", small);
	printf("Count: %u\n", count);
	printf("Big: %ld\n", big);
	printf("Very Big: %lld\n", veryBig);
	printf("Huge: %llu\n", huge);
	printf("Precise: %Lf\n", precise);

	// Check the size of each of these variable types
	printf("Size of int: %zu bytes\n", sizeof(int));
	printf("Size of double: %zu bytes\n", sizeof(double));
	printf("Size of short int: %zu bytes\n", sizeof(short int));
	printf("Size of unsigned int: %zu bytes\n", sizeof(unsigned int));
	printf("Size of long int: %zu bytes\n", sizeof(long int));
	printf("Size of long long int: %zu bytes\n", sizeof(long long int));
	printf("Size of unsigned long long int: %zu bytes\n", sizeof(unsigned long long int));
	printf("Size of long double: %zu bytes\n", sizeof(long double));

	// Also constants begin with the const keyword and will not be changed

	// Return 0
	return 0;
}
