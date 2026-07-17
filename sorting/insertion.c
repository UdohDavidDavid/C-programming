#include <stdio.h>
#include <stdlib.h>

int *insertion(int **list, int size)
{
	for (int i = 0; i < size; ++i) {
		int j = i;
		while ((*list)[j] < (*list)[j-1] && j != 0) {
			int temp = (*list)[j];
			(*list)[j] = (*list)[j-1];
			(*list)[j-1] = temp;
			j--;
		}
	}
	return *list;
}

int main()
{
	int init_list[] = {2, 5, 1, 6, 3, 7, 9, 4};
	int size = sizeof(init_list) / sizeof(init_list[0]);

	int *list = malloc(sizeof(int) * size);
	for (int i = 0; i < size; ++i) {
		list[i] = init_list[i];
	}
	int *sorted_list = insertion(&list, size);
	printf("Sorted list: ");
	for (int i = 0; i < size; ++i) {
		printf("%d ", sorted_list[i]);
	}
	printf("\n");
}
