#include <stdio.h>
#include <sys/time.h>

int main() {
    unsigned long long int time, i, u;
    struct timeval beginT, endT;

    gettimeofday(&beginT, NULL);

    for(i=0; i<5000000000; i++)
        u = 0;

    gettimeofday(&endT, NULL);

    time = (endT.tv_sec * 1000000 + endT.tv_usec) - (beginT.tv_sec * 1000000 + beginT.tv_usec);

    printf("time: %llu\n",beginT.tv_sec);
    printf("time: %llu\n",endT.tv_sec);
    printf("time: %llu\n",time);
}
