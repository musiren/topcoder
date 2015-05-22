#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1000000
#define MAX_NUM 4294967296
#define RAW_DATA_PATH "./raw_data"
#define SORT_DATA_PATH "./sorting_data"

#define QSORT 1

void create_rand_array(unsigned long long *arr, int size);
void print_array(unsigned long long *arr, int size);
void write_file(unsigned long long *arr, int size, char *path);
void read_file(unsigned long long *arr, int size, char *path);
void sorting_file(unsigned long long *arr, int size, char *path);

int main(int argc, char *argv[]) {
	unsigned long long arr[MAX_SIZE];
	create_rand_array(arr, MAX_SIZE);
	write_file(arr, MAX_SIZE, RAW_DATA_PATH);
	read_file(arr, MAX_SIZE, RAW_DATA_PATH);
	sorting_file(arr, MAX_SIZE, RAW_DATA_PATH);
	write_file(arr, MAX_SIZE, SORT_DATA_PATH);
	return 0;
}

void print_array(unsigned long long *arr, int size) {
	unsigned long i;

	for(i = 0; i < size; i++) {
		printf("arr[%lu] = %llu\n", i, *(arr+i));
	}

	return;
}

void create_rand_array(unsigned long long *arr, int size) {
	unsigned long i;
	unsigned long long product;
	unsigned long long tmp;

	srand((unsigned)time(NULL));
	for(i = 0; i < size; i++) {
		do {
			product = rand();
			tmp = rand() + (product * 1000000000);
		} while(tmp < MAX_NUM);

		*(arr+i) = tmp;
	}

	return;
}

void write_file(unsigned long long *arr, int size, char *path) {
    FILE *fp = fopen(path, "w+");
	char tmp[255];
	unsigned long i;

	for(i = 0; i < size; i++) {
		sprintf(tmp, "%llu\n", *(arr+i));
		fputs(tmp, fp);
	}

	if(fp) {
		fclose(fp);
	}

	return;
}

void read_file(unsigned long long *arr, int size, char *path) {
    FILE *fp = fopen(path, "r");
	char tmp[255];
	unsigned long i;

	for(i = 0; i < size; i++) {
		fgets(tmp, 255, fp);
		*(arr+i) = atoll(tmp);
	}

	return;
}

int _compare(const void *arg1, const void *arg2) {
	const unsigned long long *x = arg1, *y = arg2;
	if (*x > *y) {
		return 1;
	} else {
		return (*x < *y) ? -1 : 0;
	}
}

void sorting_file(unsigned long long *arr, int size, char *path) {
#if QSORT // quick sorting
	qsort(arr, size, sizeof(unsigned long long), _compare);
#else //select sorting
	unsigned long i, j, tmp;

	for(i = 0; i < size; i++) {
		j = i + 1;
		for(j = i + 1; j < size; j++) {
			if(*(arr+i) > *(arr+j)) {
				tmp = *(arr+i);
				*(arr+i) = *(arr+j);
				*(arr+j) = tmp;
			}
		}
	}
#endif
	return;
}
