#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* thread_codeLcm(void* args){
    int *arr = (int*)args;
    int *res = (int*)malloc(sizeof(int));
    *res = arr[0]+arr[1]+arr[2];
    return (void*)res;
}

void* thread_codeRev(void* args){
    int *arr = (int*)args;
    int *res = (int*)malloc(sizeof(int));
    *res = arr[0]+arr[1]-arr[2];
    return (void*)res;
}

int main(int argc, char *argv[])
{
    if(argc < 4){
        printf("Insufficient Arguments!\n");
        exit(EXIT_FAILURE);
    }
    int *arr = (int*)malloc(sizeof(int)*3), *resLcm, *resRev;
    arr[0] = atoi(argv[1]);
    arr[1] = atoi(argv[2]);
    arr[2] = atoi(argv[3]);
    pthread_t threadLcm,threadRev;
    pthread_create(&threadLcm,0,&thread_codeLcm,(void*)arr);
    pthread_create(&threadRev,0,&thread_codeRev,(void*)arr);
    pthread_join(threadLcm,(void**)&resLcm);
    pthread_join(threadRev,(void**)&resRev);
    printf("\nLCM: %d Rev: %d",*resLcm, *resRev);
    return 0;
}
