#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int size;
void thePouring(int *capacites, int *bottles, int *fromId, int *toId);

int main(int argc, char *argv[])
{
    int i;

    int *capacities;
    int *bottles;
    int *fromId;
    int *toId;
    
    if (argc == 2)
        size = atoi(argv[1]);
    else
        return -1;
    
    if (size < 2 || size > 50) 
        return -1;
    else {
        capacities = (int *)malloc(size*sizeof(int));
        bottles = (int *)malloc(size*sizeof(int));
        fromId = (int *)malloc(size*sizeof(int));
        toId = (int *)malloc(size*sizeof(int));
    }

    srand(time(0));

    for(i = 0; i < size; i++) {
        capacities[i] = (unsigned int)(rand() + 1) % 1000000 + 1;
        bottles[i] = (unsigned int)(rand() + 1) % (capacities[i] + 1);
        fromId[i] = (unsigned int)rand() % size;
        toId[i] = (unsigned int)rand() % size;
        printf ("[%d] capa(%d), bottle:(%d), fromId(%d), toId(%d)\n", i, capacities[i], bottles[i], fromId[i], toId[i]);
    }

    thePouring(capacities, bottles, fromId, toId);

    printf("========================================\n");
    printf("=================result=================\n");
    for(i = 0; i < size; i++) {
        printf ("[%d] capa(%d), bottle:(%d)\n", i, capacities[i], bottles[i]);
    }


    free(capacities);
    free(bottles);

    return 0;
}

void thePouring(int *capacites, int *bottles, int *fromId, int*toId)
{
    int i;
    int *ret = (int *)malloc(size*sizeof(int));
    int sum;

    for (i = 0; i < size; i++) {
       if(fromId[i] != toId[i]){
           if(bottles[fromId[i]] + bottles[toId[i]] > capacites[toId[i]]) {
                bottles[fromId[i]] = bottles[fromId[i]] + bottles[toId[i]] - capacites[toId[i]];
                bottles[toId[i]] = capacites[toId[i]];
           } else {
                bottles[toId[i]] = bottles[fromId[i]] + bottles[toId[i]];
                bottles[fromId[i]] = 0;
           }
       }
    }
   
    return;
}
