#include <stdio.h>
#include <stdlib.h>

int T, N;
long long int arr[100001];

int main () {
	int i, j, k;
	long long int answer;

	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		answer = 1000000000 * 2;
		scanf("%d", &N);

		for (j = 0; j < N; j++) {
			scanf("%lld", &arr[j]);
		}

		for (j = 0; j < N-1; j++) {
			for (k = j+1; k < N; k++) {
				if (llabs(answer) > llabs(arr[j] + arr[k])) {
					answer = arr[j] + arr[k];
				} else if (llabs(answer) == llabs(arr[j] + arr[k])) {
					if (arr[j] + arr[k] < 0) {
						answer = arr[j] + arr[k];
					}
				}
			}
		}

		printf("%lld\n", answer);
	}
	return 0;
}
