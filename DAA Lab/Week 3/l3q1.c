#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int a[],int n, int *count){
    int i,flag,temp;
    for(;;){
        flag =0;
        for(i=0;i<(n-1);i++){
            (*count)++;
            if(a[i]>a[i+1]){
                flag = 1;
                temp = a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
        n--;
        if(flag == 0)
            break;
    }
    return;
}

/*void BubbleSort(int a[],int n,int *count){
    int i,j,temp;
    for(i=0;i<(n-1);i++){
        for(j=0;j<(n-1-i);j++){
            (*count)++;
            if(a[j+1]<a[j]){
                temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    return;
}*/

int main(){
    int count,c,n,i,j;
    printf("\nEnter the number of test cases : ");
    scanf("%d",&c);
    for(i=0;i<c;i++){
        count=0;
        printf("Enter size of array : ");
        scanf("%d",&n);
        int a[n];
        printf("\nEnter the array elements : ");
        for(j=0;j<n;j++){
            scanf("%d",&a[j]);
        }
        BubbleSort(a,n,&count);
        printf("Count = %d\tn = %d\t",count,n);
        printf("\nSorted Array : \n");
        for(j=0;j<n;j++){
            printf("%d ",a[j]);
        }
        printf("\n");
    }
}