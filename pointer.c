#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void append(char ***list, int size) {
	*list = realloc(*list, size * sizeof(char *));
}


int main() {
	// Easy stuff
	int v = 0;
	int *e = &v;
	//printf("0x%x\n0x%x\n", p, &v);

	/*  This one however i dont really know how it works
	 *  its something about puts funcion and pointers
	 *  just take a look
	 *  */
	long y = 470020878965;
	puts((void*)&y); // It prints something unexpected
	/*
	*	char **name is a pointer to another pointer - char *list[]
	* char *string is the same as a list of chars or a string
	*/
	char **list = malloc(2 * sizeof(char *));
	list[0] = "David";
	list[1] = "Peace";
	char ***names = &list;
	printf("%s\n", **names);

	append(&list, 5);
	list[2] = "Joy";
	list[3] = "Dad";
	list[4] = "Mom";

	for (int i = 0; i < 5; i++) {
		printf("%s\n", list[i]);
	}
	/*
	 * Im gonna try to do the same thing except for
	 * an integer
	 */
	int num_list[5] = {1, 2, 3, 4, 5};
	int (*num_p)[5] = &num_list;
	printf("%d\n", (*num_p)[1]);

	// Pointer basics
	printf("\n");
	int x = 42;
	int *p = &x;
	printf("%d\n", x); // Print the value of x
	printf("%x\n", &x); // Print the address of x
	printf("%x\n", p); // Print the value stored in p
	printf("%d\n", *p); // Print the value of *p
	printf("\n");
	// Change the value of x through *p
	*p = 99;
	printf("%d\n", *p);
	printf("%d\n", x);
	printf("\n");

	//Two pointers to one variable
	int a = 10;
	int *p1 = &a;
	int *p2 = &a;
	*p2 = 20;
	printf("%d\n", *p1); // Print *p1

	free(list);
	return 0;
}

