#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
struct array {
  int n;
  struct student {
    int roll_no, marks, sem;
  } *arr;
};
  

void* sort(void* param){
  struct array* ptr = (struct array*) param;
  struct student temp;
  for(int i = 0; i < ptr -> n; i++){
    int smallest_id = i;
    for(int j = i + 1; j < ptr -> n; j++){
      if(ptr -> arr[smallest_id].roll_no > ptr -> arr[j].roll_no){
        smallest_id = j;
      }
    }
    temp = ptr -> arr[i];
    ptr -> arr[i] = ptr -> arr[smallest_id];
    ptr -> arr[smallest_id] = temp;
  }
  return NULL;
}

void* max(void* param){
  struct array* ptr = (struct array*) param;
  int* ans = (int *) malloc(sizeof(int));
  *ans = ptr -> arr[0].marks;
  for(int i = 0; i < ptr -> n; i++){
    if(*ans < ptr -> arr[i].marks){
      *ans = ptr -> arr[i].marks;
    }
  }
  return (void *) ans;
}

int main(){
  struct array obj;
  printf("Enter the value of n: ");
  scanf("%d", &obj.n);
  obj.arr = (struct student*) calloc(obj.n, sizeof(struct student));
  for(int i = 0; i < obj.n; i++){
    printf("--------%d--------\n", i + 1);
    printf("Roll No: ");
    scanf("%d", &obj.arr[i].roll_no);
    printf("Marks: ");
    scanf("%d", &obj.arr[i].marks);
    printf("Semester: ");
    scanf("%d", &obj.arr[i].sem);
    printf("\n");
  }
  
  int* maximum;
  pthread_t thread1, thread2;
  pthread_create(&thread1, 0, &sort, (void *) &obj);
  pthread_create(&thread2, 0, &max, (void *) &obj);
  pthread_join(thread1, 0);
  pthread_join(thread2, (void **) &maximum);
  
  puts("Sorted list of students is:");
  for(int i = 0; i < obj.n; i++){
    printf("--------%d--------\n", i + 1);
    printf("Roll No: %d\n", obj.arr[i].roll_no);
    printf("Marks: %d\n", obj.arr[i].marks);
    printf("Semester: %d\n\n", obj.arr[i].sem);
  }
  printf("Maximum marks is: %d\n", *maximum);
}