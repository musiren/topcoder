#include <stdio.h>
#include <stdlib.h>

#define PLUS_ONE    1

long encrypt1(long *numbers);
long encrypt2(long *numbers);
int length;

int main(int argc, char *argv[])
{
    long *numbers;
    int i;

    if(argc > 1) {
        length = argc - 1;
        numbers = (long *)malloc((length) * sizeof(long));
    }

    for(i = 0; i < length; i++) {
         *(numbers+i) = atoi(argv[i+1]);
    }

    printf("%ld\n", encrypt2(numbers));

    return 0;
}

long encrypt1(long *numbers)
{
    int i, j;
    long max = 1, tmp = 1;

    for(i = 0; i < length; i++) {
        printf("%ld ", *(numbers+i));
    }
    printf("\n");


    for(i = 0; i < length; i++) {
        *(numbers+i) += PLUS_ONE;
//        printf("*numbers+%d) += PLUS ONE\n", i);
        tmp = *numbers;
//        printf("tmp = %ld\n", tmp);

        for(j = 1; j < length; j++) {
//            printf("i = %d, j = %d\n", i, j);
            tmp = tmp * *(numbers+j);
//            printf("tmp = %ld, *(number+%d) = %ld\n", tmp, j, *(numbers+j));
        }
        *(numbers+i) -= PLUS_ONE;

        max = max >= tmp ? max : tmp;
    }

    return max;
}


long encrypt2(long *numbers)
{
    int i, j = 0;
    long min = *numbers, max = 1;

    for(i = 1; i < length; i++) {
        if(min >= *(numbers+i)) {
            min = *(numbers+i);
            j = i;
        }
    }

    printf("min = %ld\n", min);

    *(numbers+j) += PLUS_ONE;
    max = *numbers; 
    for (i = 1; i < length; i++) {
        max = max * *(numbers+i);
    }
     
    return max;
}
