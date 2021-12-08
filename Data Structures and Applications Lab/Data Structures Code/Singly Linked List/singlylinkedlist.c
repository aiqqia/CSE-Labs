#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} * Node;

int isEmpty(Node first)
{
    if (first == NULL)
    {
        return 1;
    }
    return 0;
}

void insertR(Node *first, int key)
{
    Node n = (Node)malloc(sizeof(struct node));
    n->val = key;
    n->next = NULL;
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
}

void insertF(Node *first, int key)
{
    Node n = (Node)malloc(sizeof(struct node));
    n->val = key;
    if (isEmpty(*first))
    {
        *first = n;
        return;
    }
    n->next = *first;
    *first = n;
}

void deleteR(Node *first)
{
    int ans;
    if (isEmpty(*first))
    {
        printf("\nThe list is empty, nothing to delete");
        return;
    }
    if ((*first)->next == NULL)
    {
        printf("\nThe deleted element is %d", (*first)->val);
        free(*first);
        *first = NULL;
        return;
    }
    Node cur = *first;
    while (cur->next->next)
    {
        cur = cur->next;
    }
    printf("\nThe deleted element is %d", cur->next->val);
    Node temp = cur->next;
    free(temp);
    cur->next = NULL;
}

void deleteF(Node *first)
{
    if (isEmpty(*first))
    {
        printf("\nThe list is empty, nothing to delete");
        return;
    }
    if ((*first)->next == NULL)
    {
        printf("\nThe deleted element is %d", (*first)->val);
        free(*first);
        *first = NULL;
        return;
    }
    Node temp = (*first);
    printf("\nThe deleted element is %d", ((*first)->val));
    *first = ((*first)->next);
    free(temp);
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

int search(Node first, int key)
{
    while (first)
    {
        if (first->val == key)
        {
            return 1;
        }
        first = first->next;
    }
    return 0;
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