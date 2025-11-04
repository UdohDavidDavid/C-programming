#include <stdio.h>

int highest_common_factor(int m, int n) {
	/*	Get the remainder of m/n,
	 *	m = n, n = r.
	 *	If r = 0, stop - hcf == n.
	 *	Else, repeat until r = 0	*/
	int r = m % n;
	while (r != 0) {
		r = m % n;
		m = n;
		n = r;
	}
	return m;
}

int main(int argc, char *argv[]) {
	/* Define m and n and insert into function
	 * parameters.
	 * print output. */
	int first = 3;
	int second = 6;
	int hcf = highest_common_factor(first, second);
	printf("%d\n", hcf);
}
