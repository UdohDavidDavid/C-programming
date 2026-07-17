#include <stdio.h>

void merge_sort(int list[], int l, int r);
void merge(int list[], int l, int m, int r);

// l is for left index and r is right index of the
// sub-array of arr to be sorted
void merge_sort(int list[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		// Sort first and second halves
		merge_sort(list, l, m);
		merge_sort(list, m + 1, r);

		merge(list, l, m, r);
	}
}

// Merges two subarrays of list[].
// First subarray is list[l..m]
// Second subarray is list[m+1..r]
void merge(int list[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	// Create temp arrays
	int L[n1], R[n2];

	// Copy data to temp arrays L[] and R[]
	for (i = 0; i < n1; ++i)
		L[i] = list[l + i];
	for (j = 0; j < n2; j++)
		R[j] = list[m + 1 + j];

	// Merge the temp arrays back into list[l..r
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			list[k] = L[i];
			i++;
		} else {
			list[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining values of L[]
	// if there are any
	while (i < n1) {
		list[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining values of R[]
	// if there are any
	while (j < n2) {
		list[k] = R[j];
		j++;
		k++;
	}
}

// Driver code
int main(int argc, char **argv)
{
	int list[] = {23, 0, 54, 12, 89};
	int size = sizeof(list) / sizeof(list[0]);

	merge_sort(list, 0, size - 1);

	for (int i = 0; i < size; ++i)
		printf("%d ", list[i]);
	printf("\n");
}
