#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
    struct node *prev;
} * Node;

int isEmpty(Node rear)
{
    if (rear == NULL)
    {
        return 1;
    }
    return 0;
}

void insertF(Node *rear, int key)
{
    Node n = (Node)malloc(sizeof(struct node));
    n->val = key;
    n->next = NULL;
    n->prev = NULL;
    if (isEmpty(*rear))
    {
        n->next = n;
        n->prev = n;
        *rear = n;
        return;
    }
    Node first = (*rear)->next;
    n->next = first;
    n->prev = *rear;
    (*rear)->next = n;
    first->prev = n;
}

void insertR(Node *rear, int key)
{
    Node n = (Node)malloc(sizeof(struct node));
    n->val = key;
    n->next = NULL;
    n->prev = NULL;
    if (isEmpty(*rear))
    {
        n->next = n;
        n->prev = n;
        *rear = n;
        return;
    }
    Node first = (*rear)->next;
    first->prev = n;
    (*rear)->next = n;
    n->next = first;
    n->prev = *rear;
    *rear = n;
}

void deleteF(Node *rear)
{
    if (isEmpty(*rear))
    {
        printf("\nThe list is empty, nothing to delete");
        return;
    }
    if ((*rear)->next==(*rear))
    {
        printf("\nThe deleted element is : %d", (*rear)->val);
        free(*rear);
        *rear = NULL;
        return;
    }
    Node first = (*rear)->next;
    printf("\nThe deleted element is : %d", first->val);
    (*rear)->next = first->next;
    first->next->prev = *rear;
    free(first);
}

void deleteR(Node *rear)
{
    if (isEmpty(*rear))
    {
        printf("\nThe list is empty, nothing to delete");
        return;
    }
    if ((*rear)->next == *rear)
    {
        printf("\nThe deleted element is : %d", (*rear)->val);
        free(*rear);
        *rear = NULL;
        return;
    }
    Node last = (*rear)->prev;
    Node first = (*rear)->next;
    first->prev = last;
    last->next = first;
    printf("\nThe deleted element is : %d", (*rear)->val);
    free(*rear);
    *rear = last;
}

void display(Node rear)
{
    if (isEmpty(rear))
    {
        printf("\nThe list is empty, nothing to print");
        return;
    }
    printf("\n");
    Node cur = rear->next;
    while (cur!=rear)
    {
        printf("%d\t", cur->val);
        cur = cur->next;
    }
    printf("%d", rear->val);
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