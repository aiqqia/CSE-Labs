#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>

int n;

struct stud{
    int roll, sem, marks;
};

void* threadcode1(void* args){
    struct stud *arr = (struct stud*)args;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j].roll > arr[j+1].roll){
                struct stud temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return (void*)arr;
}

void* threadcode2(void* args){
    struct stud *arr = (struct stud*)args;
    //struct stud *res;
    // int *max = (int*)malloc(sizeof(int));
    // *max = -1;
    // for(int i=0;i<n;i++){
    //     if(arr[i].marks > *max){
    //         *max = arr[i].marks;
    //     }
    // }
    int max = -1;
    for(int i=0;i<n;i++){
        if(arr[i].marks > max){
            max = arr[i].marks;
        }
    }
    return (void*)max;
}

int main(){
    printf("\nEnter number of students : ");
    scanf("%d",&n);
    struct stud *arr = (struct stud *)malloc(n * sizeof(struct stud));
    for(int i=0;i<n;i++){
        printf("\nEnter student %d details RSM: \n",i);
        scanf("%d %d %d",&arr[i].roll, &arr[i].sem, &arr[i].marks);
    }
    struct stud *res1 = (struct stud *)malloc(n * sizeof(struct stud));
    pthread_t thread1, thread2;
    pthread_create(&thread1, 0, &threadcode1, (void*)arr);
    pthread_join(thread1, (void**)&res1);
    printf("\n\nDetails: \n\n");
    for(int i=0;i<n;i++){
        printf("\nStudent %d details RSM: ",i);
        printf("%d %d %d",res1[i].roll, res1[i].sem, res1[i].marks);
    }
    printf("\n");
    pthread_create(&thread2, 0, &threadcode2, (void*)arr);
    //struct stud *res2;
    int res2;
    pthread_join(thread2, (void**)&res2);
    printf("\nStudent with max marks is : Marks: %d\n", res2);
}