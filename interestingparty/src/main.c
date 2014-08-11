#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *first;
    char *second;
} InterestingParty;

int people(InterestingParty *ip, int ip_size);

int main (int argc, char *argv[])
{
    InterestingParty *ip;
    int ip_size;
    int i;

    if(argc > 2) {
        ip_size = argc / 2;
        if (ip_size < 1 || ip_size > 50) {
            printf("To be Size 1 ~ 50\n");
            return -1;
        } else
            ip = (InterestingParty *)malloc(ip_size * sizeof(InterestingParty));
    } else {
        printf("Need to more than 2 args\n");
        return -1;
    }

    for(i = 0; i < ip_size; i++) {
        if(!strcmp(argv[i*2+1], argv[i*2+2])) {
            printf("Should NOT be same first and second\n");
            return -1;
        } else {
            ip[i].first = argv[i*2+1];
            ip[i].second = argv[i*2+2];
        }
        
        printf("ip[%d]: first:%s, second:%s\n", i, ip[i].first, ip[i].second);
    }

    printf("%d people can be invited\n", people(ip, ip_size));

    free(ip);
    return 0;
}

int people(InterestingParty *ip, int ip_size) {
    int ret = 0;
    int tmp_first = 0, tmp_second = 0;
    int i, j;

    for (i = 0; i < ip_size; i++) {
        for(j = 0; j < ip_size; j++) {
            //if (i != j) {
                if(!strcmp(ip[i].first, ip[j].first) || !strcmp(ip[i].first, ip[j].second))
                    tmp_first++;

                if(!strcmp(ip[i].second, ip[j].first) || !strcmp(ip[i].second, ip[j].second))
                    tmp_second++;
            //}
        }

        ret = (ret >= tmp_first  ? ret : tmp_first);
        ret = (ret >= tmp_second ? ret : tmp_second);
        tmp_first = 0;
        tmp_second = 0;
    }

    return ret;
}
