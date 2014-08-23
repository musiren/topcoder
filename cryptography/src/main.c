#include <stdio.h>
#include <stdlib.h>

long encrypt(long *numbers);
int length;

int main(int argc, char *argv[])
{
    long *numbers;
    long result;
    int i;

    if(argc > 1) {
        length = argc - 1;
        numbers = (long *)malloc((length) * sizeof(long));
    }

    for(i = 0; i < length; i++) {
         *(numbers+i) = atoi(argv[i+1]);
    }
    printf("%ld\n", encrypt(numbers));

    return 0;
}

long encrypt(long *numbers)
{
    int i;
    long max, tmp; 

    for(i = 0; i < length; i++) {
        printf("%d ", *(numbers+i));
    }
    printf("\n");

    return -1;
}
