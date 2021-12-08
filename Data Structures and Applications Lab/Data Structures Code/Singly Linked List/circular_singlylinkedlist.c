#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} * Node;

int isEmpty(Node rear)
{
    if (rear == NULL)
    {
        return 1;
    }

    return 0;
}

void insertF(Node *rear, int key){
    Node n = (Node)malloc(sizeof(struct node));
    n->next = NULL;
    n->val = key;

    if(isEmpty(*rear)){
        *rear = n;
        (*rear)->next = *rear;
        return;
    }

    n->next = (*rear)->next;
    (*rear)->next = n;
}

void insertR(Node* rear, int key){
    Node n = (Node)malloc(sizeof(struct node));
    n->next = NULL;
    n->val = key;

    if(isEmpty(*rear)){
        *rear = n;
        (*rear)->next = *rear;
        return;
    }
    n->next = (*rear)->next;
    (*rear)->next = n;
    *rear = n;
}

void deleteF(Node* rear){
    if(isEmpty(*rear)){
        printf("\nThe list is empty, nothing to delete");
        return;
    }
    if((*rear)->next  == (*rear)){
        printf("\nThe deleted element is : %d", (*rear)->val);
        free(*rear);
        *rear = NULL;
        return;
    }
    Node temp = (*rear)->next;
    printf("\nThe deleted element is : %d", temp->val);
    (*rear)->next = temp->next;
    free(temp);
}

void deleteR(Node* rear){
    if(isEmpty(*rear)){
        printf("\nThe list is empty, nothing to delete");
        return;
    }
    if((*rear)->next  == (*rear)){
        printf("\nThe deleted element is : %d", (*rear)->val);
        free(*rear);
        *rear = NULL;
        return;
    }
    Node cur = (*rear)->next;
    Node prev = *rear;
    while(cur!=*rear){
        cur = cur->next;
        prev = prev->next;
    }
    printf("\nThe deleted element is : %d", cur->val);
    prev->next = cur -> next;
    free(cur);
    (*rear) = prev;
}

void display(Node rear){
    if (isEmpty(rear))
    {
        printf("\nThe list is empty, nothing to print");
        return;
    }
    printf("\n");
    Node cur = rear->next;
    while(cur!=rear && cur){
        printf("%d\t", cur->val);
        cur = cur->next;
    }
    printf("%d", rear->val);
}

int search(Node rear, int key)
{
    while (rear)
    {
        if (rear->val == key)
        {
            return 1;
        }
        rear = rear->next;
    }
    return 0;
}

int main()
{
    Node rear = NULL;
    int choice = 0, ele;
    while (choice < 7)
    {
        printf("\n1 : Display the list \n2 : Insert Front \n3 : Insert Rear \n4 : Remove front \n5 : Remove Rear \n6 : Check for empty or full \n7 : Exit");
        printf("\nEnter the operation to be done: ");
        scanf("%d", &choice);
        printf("\n#################");
        switch (choice)
        {
        case 1:
            display(rear);
            break;

        case 2:
            printf("\nEnter the element to be inserted : ");
            scanf("%d", &ele);
            insertF(&rear, ele);
            break;

        case 3:
            printf("\nEnter the element to be inserted : ");
            scanf("%d", &ele);
            insertR(&rear, ele);
            break;

        case 4:
            deleteF(&rear);
            break;

        case 5:
            deleteR(&rear);
            break;
        case 6:
            if (isEmpty(rear))
            {
                printf("\nThe list is empty");
            }
            else
            {
                printf("\nThe list is NOT empty");
            }
            break;
        }
        printf("\n#################\n");
    }
    return 0;
}