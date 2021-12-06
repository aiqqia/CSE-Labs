#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

sem_t wrt;
pthread_mutex_t mutex_sem;
int count = 1;
int numreader = 0;

void *writer(void *wno){
	sem_wait(&wrt);
	count *= 2;
	printf("Writer %d modified 'count' to %d\n", (*((int*)wno)), count);
	sem_post(&wrt);
}

void *reader(void *rno){
	pthread_mutex_lock(&mutex_sem);
	numreader++;

	if(numreader == 1)
		sem_wait(&wrt); //first reader will block the writer
	pthread_mutex_unlock(&mutex_sem);

	//Reading Section, hence no locks

	printf("Reader %d: read 'count' as %d\n", *((int*)rno), count);

	//Reader acquire the lock before modifying numreader

	pthread_mutex_lock(&mutex_sem);
	numreader--;

	if(numreader == 0)
		sem_post(&wrt); //If this is the last reader, it will wake up the writer
	pthread_mutex_unlock(&mutex_sem);
}

int main(){
	pthread_t read[10], write[5];
	pthread_mutex_init(&mutex_sem, NULL);
	sem_init(&wrt, 0, 1);
	int a[10] = {1,2,3,4,5,6,7,8,9,10}; //used for numbering the producers and consumers
	
	for(int i=0;i<10;i++)
		pthread_create(&read[i], NULL, reader, &a[i]);
	for(int i=0;i<5;i++)
		pthread_create(&write[i], NULL, writer, &a[i]);
	for(int i=0;i<10;i++)
		pthread_join(read[i], NULL);
	for(int i=0;i<5;i++)
		pthread_join(write[i], NULL);

	pthread_mutex_destroy(&mutex_sem);
	sem_destroy(&wrt);
	return 0;
}