#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, k1, k2;
	int *k1_arr, *k2_arr;
	int i;
	int turns = 0;

	scanf("%d", &n);

	scanf("%d", &k1);
	k1_arr = calloc(sizeof(int), n);
	for (i = k1-1; i >= 0; i--) {
		scanf("%d", k1_arr+i);
	}

	scanf("%d", &k2);
	k2_arr = calloc(sizeof(int), n);
	for (i = k2-1; i >= 0; i--) {
		scanf("%d", k2_arr+i);
	}

	while(k1 != 0 && k2 != 0 && turns < 501) {
		turns++;
		printf("turns: %d\n", turns);
		if(*(k1_arr+k1-1) > *(k2_arr+k2-1)) {
			int tmp = *(k1_arr+k1-1);

			for(i = k1; i > 1; i--) {
				*(k1_arr+i) = *(k1_arr+i-2);
			}
			*(k1_arr) = tmp;
			*(k1_arr+1) = *(k2_arr+k2-1);
			k1++;
			k2--;
		} else {
			int tmp = *(k2_arr+k2-1);

			for(i = k2; i > 1; i--) {
				*(k2_arr+i) = *(k2_arr+i-2);
			}
			*(k2_arr) = tmp;
			*(k2_arr+1) = *(k1_arr+k1-1);
			k2++;
			k1--;
		}

		for (i = 0; i < k1; i++) {
			printf("%d ", *(k1_arr+i));
		}

		printf("\n");
		for (i = 0; i < k2; i++) {
			printf("%d ", *(k2_arr+i));
		}
		printf("\n");
	}

	if (turns > 500)
		printf("%d", -1);
	else
		printf("\n%d %d", turns, k1==0?2:1);
	return 0;
}
