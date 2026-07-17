#include <stdio.h>

void merge_sort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int binary_search(int arr[], int l, int size, int T);

int main(int argc, char **argv)
{
	int arr[] = {34, 62, 23, 92, 17, 39, 57};
	int size = sizeof(arr) / sizeof(arr[0]);

	merge_sort(arr, 0, size - 1);

	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	// Search for a number in the sorted array
	int search = 62;
	int result = binary_search(arr, 0, size, search);
	if (result != -1) {
		printf("Value %d found at index %d\n", arr[result], result);
	} else {
		printf("Error! Value %d not found\n", search);
	}
}

void merge_sort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = (m - l) + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; ++i)
		L[i] = arr[l + i];
	for (j = 0; j < n2; ++j)
		R[j] = arr[(m + 1)+ j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

int binary_search(int arr[], int l, int size, int T)
{
	int r = size - 1;

	while (l <= r) {
		int m = l + (r - l) / 2;
		if (arr[m] < T) {
			l = m + 1;
		} else if (arr[m] > T) {
			r = m - 1;
		} else {
			return m;
		}
	}
	return -1;
}
