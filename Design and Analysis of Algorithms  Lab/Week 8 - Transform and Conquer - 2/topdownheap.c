#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int op=0;

void heapify(int arr[], int currIndex)
{
    int parent = (currIndex)/2;
    op++;
    while(parent > 0)
    {
	    op++;
        if(arr[parent]<arr[currIndex])
        {
            int temp = arr[parent];
            arr[parent] = arr[currIndex];
            arr[currIndex] = temp;

            currIndex = parent;
            parent = (currIndex)/2;
        }
        else
            return;
    }
}


int main(){
    int n;
    printf("\nEnter number of elements : ");
    scanf("%d",&n);
    int *h = (int*)malloc((sizeof(int))*(n+1));
    printf("\nEnter elements : ");
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i]);
        heapify(h,i);
    }
    printf("\nThe heap created is : ");
    for(int i=1;i<=n;i++){
        printf("%d ",h[i]);
    }
    printf("\n");
    printf("\nThe Opcount is : %d",op);
    return 0;
}