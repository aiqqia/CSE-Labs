#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int op=0;

void heapify(int *h, int n){
    int i,j,k,v;
    bool heap;
    for(i=(n/2);i>=1;i--){
        k=i;
        v=h[k];
        heap = false;
        while(!heap && (2*k) <= n){
            op++;
            j=2*k;
            if(j<n)
                if(h[j]<h[j+1])
                    j=j+1;
            if(v>=h[j])
                heap=true;
            else{
                h[k]=h[j];
                k=j;
            }
        }
        h[k]=v;
    }
    return;
}

void heapsort(int *h, int n){
    int i,k=n,temp;
    fflush(stdin);
    for(i=1;i<n;i++){
        op++;
        heapify(h,k);
        temp = h[1];
        h[1] = h[k];
        h[k] = temp;
        k=k-1;
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
    }
    heapsort(h,n);
    printf("\nThe sorted array created is : ");
    for(int i=1;i<=n;i++){
        printf("%d ",h[i]);
    }
    printf("\n");
    printf("\nThe Opcount is : %d",op);
    return 0;
}