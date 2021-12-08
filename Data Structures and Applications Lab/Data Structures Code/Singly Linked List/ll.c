#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}*Node;

int isEmpty(Node n){
    if(n==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void insertFront(Node *first, int n){
    Node new = (Node)malloc(sizeof(struct node));
    new->val = n;
    new->next = NULL;
    if(isEmpty(*first)){
        *first = new;
        return;
    }
    else{
        new->next = *first;
        *first=new;
    }
}

void insertRear(Node *first,int n){
    Node new = (Node)malloc(sizeof(struct node));
    new->val = n;
    new->next = NULL;
    if(isEmpty(*first)){
        *first = new;
        return;
    }
    Node cur = *first;
    while(cur->next){
        cur=cur->next;
    }
    cur->next = new;
}

void display(Node n){
    if(isEmpty(n)){
        printf("\nEmpty.");
        return;
    }
    printf("\n");
    while(n){
        printf("%d ",n->val);
        n=n->next;
    }
}

int main(){
    Node first = NULL;
    int ch,n;
    do{
        printf("\n1.View List \t2.Insert Front \t3.Insert Rear\nEnter choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1 : display(first);
                    break;
            case 2 : printf("\nEnter element : ");
                     scanf("%d",&n);
                     insertFront(&first,n);
                     break;
            case 3 : printf("\nEnter element : ");
                     scanf("%d",&n);
                     insertRear(&first,n);
                     break;
            default : exit(1);
                      break;
        }
    }while(ch<4);
    return 0;
}