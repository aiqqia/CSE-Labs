#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>

sem_t sem1, sem2;

void* tc1(void* args){
    sem_post(&sem1);
    printf("\nThread 1");
}

void* tc2(void* args){
    sem_wait(&sem2);
    printf("\nThread 2");
}

int main(){
    sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 1);
    pthread_t t1, t2;
    pthread_create(&t1, 0, &tc1, 0);
    pthread_create(&t2, 0, &tc2, 0);
    pthread_join(t1, 0);
    pthread_join(t2, 0);
    sem_destroy(&sem1);
    sem_destroy(&sem2);
}