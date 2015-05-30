#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int k, n, w;
	int i, sum = 0;
	int borrow = 0;
	scanf("%d %d %d", &k, &n, &w);

	for (i = 1; i <= w; i++) {
		sum += i*k;
	}

	if (n - sum > 0)
		printf ("%d\n", 0);
	else {
		printf ("%d\n", (n - sum) * (-1));
	}

	return 0;
}
