#include <stdio.h>

#define TRUE 1
#define FALSE 0

int n, N, K;
int arr[10001];
int answer;
int ret;

int find(int current_pos, int count, int current_val) {
	int i;

	if (ret == K)
		answer = TRUE;

	for (i = current_pos+1; i < N; i++) {
		if (current_val < arr[i]) {
//			printf("find(arr[%d]=(%d), %d, arr[%d]=(%d)\n",
//				i, arr[i], count+1, i, arr[i]);
			if (find(i, count+1, arr[i])) {
				ret = count+1;
				if (ret == K)
					answer = TRUE;
				return TRUE;
			}
		} else {
//			printf("find(arr[%d]=(%d), %d, %d\n",
//				i, arr[i], count, current_val);
			if(find(i, count, current_val)) {
				ret = count;
				return FALSE;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	int i, j, k, l;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &N, &K);
		for (j = 0; j < N; j++) {
			scanf("%d", &arr[j]);
		}

		answer = FALSE;
		for (j = 0; j < N; j++) {
			int count;
//			printf("\n==============\nfind(arr[%d]=(%d), %d, arr[%d]=(%d)\n",
//					j, arr[j], 1, j, arr[j]);

			find(j, 1, arr[j]);
			if (answer == TRUE)
				break;
		}
		printf("Case #%d\n%d\n", i, answer);
	}

	return 0;
}
