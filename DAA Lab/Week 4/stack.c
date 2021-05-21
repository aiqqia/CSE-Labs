#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int arr[20];
};

void push(struct stack *s,int n){
    if(s->top == 19){
        printf("\nStack full.");
        return;
    }
    s->arr[++(s->top)] = n;
    return;
}

int pop(struct stack *s){
    if(s->top == -1){
        printf("\nStack empty.");
        return -1;
    }
    return s->arr[s->top--];
}

int main(){
    struct stack s;
    s.top = -1;
    int ch,x;
    printf("\n1. Push \t 2. Pop \t 3. Exit");
    do{
        printf("\nEnter choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("\nEnter element to be pushed : ");
                    scanf("%d",&x);
                    push(&s,x);
                    break;
            case 2: x=pop(&s);
                    if(x!=-1){
                        printf("\nElement popped : %d",x);
                    }
                    break;
            case 3: exit(1);
                    break;
            default: break;
        }
    }while(ch<=3);
    return 0;
}