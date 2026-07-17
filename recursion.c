#include <stdio.h>

int sum(int n);
void countdown(int n);

void countdown(int n) {
    if (n == 0) {
        printf("Lift off!\n");
        return;
    }
    printf("%d\n", n);
    countdown(n - 1);
}

int sum(int n)
{
	if (n == 0) {
		return 0;
	} else {
		return n + sum(n - 1);
	}
}

int main(int argc, char **argv)
{
	int n = 10;
	int num = sum(n);
	printf("%d\n", num);

	countdown(10);
}
