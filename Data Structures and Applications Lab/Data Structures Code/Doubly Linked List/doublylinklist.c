#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
    struct node *prev;
} * Node;

int isEmpty(Node first)
{
    if (first == NULL)
    {
        return 1;
    }
    return 0;
}

void insertF(Node *first, int key)
{
    Node n = (Node)malloc(sizeof(struct node));
    n->val = key;
    n->next = NULL;
    n->prev = NULL;
    if (isEmpty(*first))
    {
        *first = n;
        return;
    }
    n->next = *first;
    (*first)->prev = n;
    *first = n;
}

void insertR(Node *first, int key)
{
    Node n = (Node)malloc(sizeof(struct node));
    n->val = key;
    n->next = NULL;
    n->prev = NULL;
    if (isEmpty(*first))
    {
        *first = n;
        return;
    }
    Node cur = *first;
    while (cur->next)
    {
        cur = cur->next;
    }
    cur->next = n;
    n->prev = cur;
}

void deleteF(Node *first)
{
    if (isEmpty(*first))
    {
        printf("\nThe list is empty, nothing to delete");
        return;
    }
    if ((*first)->next == (*first)->prev)
    {
        printf("\nThe deleted element is %d", (*first)->val);
        free(*first);
        *first = NULL;
        return;
    }
    Node next_to_1 = (*first)->next;
    next_to_1->prev = NULL;
    printf("\nThe deleted element is %d", (*first)->val);
    free(*first);
    *first = next_to_1;
}

void deleteR(Node *first)
{
    if (isEmpty(*first))
    {
        printf("\nThe list is empty, nothing to delete");
        return;
    }
    if ((*first)->next == (*first)->prev)
    {
        printf("\nThe deleted element is %d", (*first)->val);
        free(*first);
        *first = NULL;
        return;
    }
    Node cur = (*first);
    while (cur->next)
    {
        cur = cur->next;
    }
    Node second_last = cur->prev;
    printf("\nThe deleted element is %d", cur->val);
    second_last->next = NULL;
    free(cur);
}

void display(Node first)
{
    if (isEmpty(first))
    {
        printf("\nThe list is empty, nothing to print");
        return;
    }
    printf("\n");
    while (first)
    {
        printf("%d\t", first->val);
        first = first->next;
    }
}

int main()
{
    Node first = NULL;
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
            display(first);
            break;

        case 2:
            printf("\nEnter the element to be inserted : ");
            scanf("%d", &ele);
            insertF(&first, ele);
            break;

        case 3:
            printf("\nEnter the element to be inserted : ");
            scanf("%d", &ele);
            insertR(&first, ele);
            break;

        case 4:
            deleteF(&first);
            break;

        case 5:
            deleteR(&first);
            break;
        case 6:
            if (isEmpty(first))
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