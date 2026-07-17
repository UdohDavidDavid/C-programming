#include <stdio.h>

void print_repeat(char c, int count) {
	for (int i = 0; i < count; ++i) {
		printf("%c", c);
	}
}

void print_triangle(int size) {
	int space_count = size;
	int star_count = 1;
	for (int i = 0; i < size; ++i) {
		print_repeat(' ', space_count);
		print_repeat('*', star_count);
		space_count--;
		star_count+=2;
		printf("\n");
	}
}

int main(int argc, char **argv) {
	int size = 36;
	int running = 1;
	while (running) {
		print_triangle(size);
	}
}
