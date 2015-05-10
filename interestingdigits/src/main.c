#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER 9999
#define MAX_LEN 15
int main(int argc, char *argv[])
{
	int base = 0;
	int num = NUMBER;
	char num_string[MAX_LEN];
	int i = MAX_LEN-2;

	memset(num_string, 32, sizeof(num_string));

    if (argc != 2) {
        printf("Usage: interesing-digits [BASE]\n");
        return -1;
    } else {
		base = atoi(argv[1]);
	}

	while (num >= base) {
		int tmp = num % base;
		if (tmp < 10) {
			num_string[i] = (char)(tmp + 48);
		} else {
			num_string[i] = (char)(tmp + 55);
		}
		num = num / base;
		i--;
	}
	num_string[i] = (char)((num % base) + 48);
	num_string[MAX_LEN-1] = '\0';

	printf("%s\n", num_string);

    return 0;
}
