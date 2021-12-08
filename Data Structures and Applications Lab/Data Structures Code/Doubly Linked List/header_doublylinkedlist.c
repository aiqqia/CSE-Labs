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

void insertF(Node *head, int key)
{
    Node n = (Node)malloc(sizeof(struct node));
    n->val = key;
    n->next = NULL;
    n->prev = NULL;
    if (isEmpty(*head))
    {
        (*head)->next = n;
        n->prev = *head;
        (*head)->val++;
        return;
    }
    n->prev = *head;
    n->next = (*head)->next;
    n->next->prev = n;
    (*head)->next = n;
    (*head)->val++;
}

void insertR(Node *head, int key)
{
    Node n = (Node)malloc(sizeof(struct node));
    n->val = key;
    n->next = NULL;
    n->prev = NULL;
    if (isEmpty(*head))
    {
        (*head)->next = n;
        n->prev = *head;
        (*head)->val++;
        return;
    }
    Node cur = (*head)->next;
    while (cur->next)
    {
        cur = cur->next;
    }
    cur->next = n;
    n->prev = cur;
    (*head)->val++;
}

void deleteF(Node *head)
{
    if (isEmpty(*head))
    {
        printf("\nThe list is empty, nothing to delete");
        return;
    }
    if ((*head)->val == 1)
    {
        printf("\nThe deleted element is : %d", (*head)->next->val);
        free((*head)->next);
        (*head)->next = NULL;
        (*head)->val--;
        return;
    }
    Node tod = (*head)->next;
    printf("\nThe deleted element is : %d", tod->val);
    (*head)->next = tod->next;
    (*head)->next->prev = *head;
    (*head)->val--;
    free(tod);
}

void deleteR(Node *head)
{
    if (isEmpty(*head))
    {
        printf("\nThe list is empty, nothing to delete");
        return;
    }
    if ((*head)->val == 1)
    {
        printf("\nThe deleted element is : %d", (*head)->next->val);
        free((*head)->next);
        (*head)->next = NULL;
        (*head)->val--;
        return;
    }
    Node cur = (*head)->next;
    while (cur->next)
    {
        cur = cur->next;
    }
    printf("\nThe deleted element is : %d", cur->val);
    Node prev = cur->prev;
    prev->next = NULL;
    free(cur);
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
    head = head->next;
    while (head)
    {
        printf("%d\t", head->val);
        head = head->next;
    }
}



int main()
{
    Node head;
    head->val = 0;
    head->next = NULL;
    head->prev = NULL;
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
