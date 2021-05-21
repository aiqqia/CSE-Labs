#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int checksubstring(char str[], char sub[]){
    int c=0,c1,flag=1;
    int i,j,n,m;
    n = strlen(str);
    m = strlen(sub);
    for(i=0;i<=(n-m);i++){
        c1=0;
        flag = 1;
        for(j=i; c1<m; j++,c1++){
            c++;
            if(str[j] != sub[c1]){
                flag = 0;
                break;
            }
        }
        if(flag == 1)
            break;
    }
    if(flag == 1)
        printf("\nSubstring Found!");
    else
        printf("\nSubstring not found !");
    return c;
}

int main(){
    printf("\nEnter a string : ");
    char str[20],sub[20];
    scanf("%[^\n]%*c",str);
    printf("\nEnter a substring : ");
    scanf("%[^\n]%*c",sub);
    int count = checksubstring(str,sub);
    printf("\nCount = %d",count);
}