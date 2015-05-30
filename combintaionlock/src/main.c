#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int n;
	int i;
	int move = 0;
	char first_arr[2000], second_arr[2000];

	scanf("%d", &n);
	scanf("%s", first_arr);
	scanf("%s", second_arr);

	for(i = 0; i < n; i++) {
		int abs = *(first_arr+i) - *(second_arr+i);
		
		if (abs < 0)
			abs = abs *(-1);
		if (abs > 5)
			abs = 10 - abs;
		
		move += abs;
	}

	printf("%d\n", move);	
	return 0;
}
