#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

int l;

void* tc(void* args){
    char* str = (char*)args;
    printf("Length: %d String: %s\n",l, str);
    return (void*)str;
}

int main(){
    char buf[100];
    printf("\nEnter string : ");
    scanf("%s",buf);
    l = strlen(buf);
    pthread_t t;
    char* arr = (char*)malloc(sizeof(char)*l);
    pthread_create(&t,0,&tc,(void*)buf);
    pthread_join(t,(void**)&arr);
    printf("New String : %s",arr);
}