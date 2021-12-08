#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
    struct node *prev;
} * Node;

int isEmpty(Node head)
{
    if (head->val == 0)
    {
        return 1;
    }
    return 0;
}

void insertF(Node* head, int key){
    Node n = (Node)malloc(sizeof(struct node));
    n->val = key;
    n->next = NULL;
    n->prev = NULL;
    if(isEmpty(*head)){
        (*head)->next = n;
        (*head)->prev = n;
        n->next = *head;
        n->prev = *head;
        (*head)->val++;
        return;
    }
    Node next2head = (*head)->next;
    n->next = next2head;
    n->prev = *head;
    next2head->prev = n;
    (*head)->next = n;
    (*head)->val++;
}

void insertR(Node* head, int key){
    Node n = (Node)malloc(sizeof(struct node));
    n->val = key;
    n->next = NULL;
    n->prev = NULL;
    if(isEmpty(*head)){
        (*head)->next = n;
        (*head)->prev = n;
        n->next = *head;
        n->prev = *head;
        (*head)->val++;
        return;
    }
    Node last = (*head)->prev;
    n->next = (*head);
    n->prev = last;
    last->next = n;
    (*head)->prev = n;
    (*head)->val++;
}

void deleteF(Node* head){
    if(isEmpty(*head)){
        printf("\nThe list is empty, nothing to delete");
        return;
    }
    Node nexttodel = (*head)->next->next;
    Node tobedel = (*head)->next;
    (*head)->next = nexttodel;
    nexttodel->prev = *head;
    printf("\nThe deleted element is : %d", tobedel->val);
    free(tobedel);
    (*head)->val--;
}

void deleteR(Node* head){
    if(isEmpty(*head)){
        printf("\nThe list is empty, nothing to delete");
        return;
    }
    Node last = (*head)->prev;
    Node second_last = last->prev;
    (*head)->prev = second_last;
    second_last->next = (*head);
    printf("\nThe deleted element is : %d", last->val);
    free(last);
    (*head)->val--;
}


void display(Node head)
{
    if (isEmpty(head))
    {
        printf("\nThe list is empty, nothing to print");
        return;
    }
    printf("\n");
    int cnt = head->val;
    head = head->next;
    while (cnt--)
    {
        printf("%d\t", head->val);
        head = head->next;
    }
}

int main()
{
    Node head;
    head->val = 0;
    head->next = head;
    head->prev = head;
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
            display(head);
            break;

        case 2:
            printf("\nEnter the element to be inserted : ");
            scanf("%d", &ele);
            insertF(&head, ele);
            break;

        case 3:
            printf("\nEnter the element to be inserted : ");
            scanf("%d", &ele);
            insertR(&head, ele);
            break;

        case 4:
            deleteF(&head);
            break;

        case 5:
            deleteR(&head);
            break;
        case 6:
            if (isEmpty(head))
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