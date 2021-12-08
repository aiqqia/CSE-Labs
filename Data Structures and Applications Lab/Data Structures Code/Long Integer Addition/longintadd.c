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

void reverse(Node *head)
{
    Node current = *head;
    Node prev = NULL, next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
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
        printf("%d", first->val);
        first = first->next;
    }
}

void add(Node one, Node two)
{
    reverse(&one);
    reverse(&two);
    Node sumList = NULL;
    int carry = 0;
    while (one || two)
    {
        int sum = (one ? one->val : 0) + (two ? two->val : 0) + carry;
        int dig = sum % 10;
        carry = sum / 10;
        insertR(&sumList, dig);
        if (one)
            one = one->next;
        if (two)
            two = two->next;
    }
    if (carry)
    {
        insertR(&sumList, carry);
    }
    printf("\nThe sum is : ");
    reverse(&sumList);
    display(sumList);
}

int main()
{
    Node first = NULL;
    Node second = NULL;
    int choice = 0;
    char ele[100];
    while (choice < 3)
    {
        printf("\n1 : Enter the numbers \n2 : Add the numbers \n3 : Exit");
        printf("\nEnter the operation to be done: ");
        scanf("%d", &choice);
        printf("\n#################");
        switch (choice)
        {
        case 1:
            printf("\nEnter the first number : ");
            fflush(stdin);
            scanf("%s", ele);
            for (int i = 0; ele[i] != '\0'; i++)
            {
                insertF(&first, (int)(ele[i] - '0'));
            }
            printf("\nEnter the second number : ");
            fflush(stdin);
            scanf("%s", ele);
            for (int i = 0; ele[i] != '\0'; i++)
            {
                insertF(&second, (int)(ele[i] - '0'));
            }
            printf("\nThe numbers are : \n1 : ");
            reverse(&first);
            display(first);
            reverse(&second);
            printf("\n2  : ");
            display(second);
            break;

        case 2:
            add(first, second);
            first = NULL;
            second = NULL;
            break;
        }
        printf("\n#################\n");
    }
    return 0;
}