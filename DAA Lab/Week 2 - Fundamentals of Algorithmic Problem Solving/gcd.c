#include<stdio.h>
#include<stdlib.h>

int prime(int x){
    int i,c=0;
    for(i=2;i<(x/2);i++){
        if(x%i == 0){
            c++;
        }
    }
    if(c==0){
        return 1;
    }
    else return 0;
}

int gcd(int x,int y){
    int a[x], b[y],i,c1=0,c2=0,j;
    int xx = x, yy = y;
    for(i=2;i<=xx;){
        if(prime(i)){
              if(xx%i == 0){
              a[c1] = i;
              c1+=1;
              xx/=i;
              continue;
            }
        i++;
        }
        else{
            i++;
        }
    }
    for(j=2;j<=yy;){
        if(prime(j)){
              if(yy%j == 0){
              b[c2] = j;
              c2+=1;
              yy/=j;
              continue;
              }
        j++;
        }
        else{
            j++;
        }
    }
    printf("Prime factors of %d : ",x);
    for(i=0;i<c1;i++){
        printf("%d ",a[i]);
    }
    printf("\nPrime factors of %d : ",y);
    for(j=0;j<c2;j++){
        printf("%d ",b[j]);
    }


    int m=0,n=0;
    int l=c1;
    int res=1;
    for(;m<l;){
        if(a[m] == b[n]){
            res*=a[m];
            m++;
            n++;
        }
        if(a[m]<b[n]){
            m++;
        }
        if(a[m]>b[n]){
            n++;
        }
    }

    return res;
}

int main(){
    int x,y;
    printf("\nEnter two numbers : ");
    scanf("%d %d",&x,&y);
    int z = gcd(x,y);
    printf("\nGCD is %d",z);
}