#include <stdio.h>

#define TRUE 1
#define FALSE 0

int n, N, K;
int arr[10000];
int answer;

int main(int argc, char *argv[])
{
	int i, j, k;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d %d", &N, &K);
		for (j = 0; j < N; j++) {
			scanf("%d", &arr[j]);
		}

		answer = FALSE;

		for (j = 0; j < N; j++) {
			int count = 1;
			for (k = j + 1; k < N; k++) {
				if(arr[j] < arr[k]) {
					count++;
				}
			}
			if (count > K)
				answer = TRUE;
		}

		printf("Case #%d\n%d\n", i, answer);
	}

	return 0;
}
