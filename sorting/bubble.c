#include <stdio.h>
#include <stdlib.h>

int *bubble(int **list, int size)
{
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < (size - 1) - i; ++j) {
			if ((*list)[j] > (*list)[j+1]) {
				int temp = (*list)[j];
				(*list)[j] = (*list)[j+1];
				(*list)[j+1] = temp;
			}
		}
	}
	return *list;
}

int main() {
	int init_list[] = {4, 2, 6, 3, 9, 5, 1, 0};
	int size = sizeof(init_list) / sizeof(init_list[0]);

	int *list = malloc(sizeof(int) * size);
	for (int i = 0; i < size; ++i) {
		list[i] = init_list[i];
	}

	int *sorted_list = bubble(&list, size);
	printf("Sorted list: ");
	for (int i = 0; i < size; ++i) {
		printf("%d ", sorted_list[i]);
	}
	printf("\n");
}
