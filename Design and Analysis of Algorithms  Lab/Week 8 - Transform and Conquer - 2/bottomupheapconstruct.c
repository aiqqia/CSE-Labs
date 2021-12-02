#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void heapify(int *h, int n){
    int i,j,k,v;
    bool heap;
    for(i=(n/2);i>=1;i--){
        k=i;
        v=h[k];
        heap = false;
        while(!heap && (2*k) <= n){
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

int main(){
    int n;
    printf("\nEnter number of elements : ");
    scanf("%d",&n);
    int *h = (int*)malloc((sizeof(int))*(n+1));
    printf("\nEnter elements : ");
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i]);
    }
    heapify(h,n);
    printf("\nThe heap created is : ");
    for(int i=1;i<=n;i++){
        printf("%d ",h[i]);
    }
    printf("\n");
    return 0;
}