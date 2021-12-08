#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
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
    if(isEmpty(*head)){
        n->next = (*head);
        (*head)->next = n;
        (*head)->val++;
        return;
    }
    n->next = (*head)->next;
    (*head)->next = n;
    (*head)->val++;
}

void insertR(Node* head, int key){
    Node n = (Node)malloc(sizeof(struct node));
    n->val = key;
    n->next = NULL;
    if(isEmpty(*head)){
        n->next = (*head);
        (*head)->next = n;
        (*head)->val++;
        return;
    }
    Node cur = (*head)->next;
    while(cur->next!=*head){
        cur = cur->next;
    }
    cur->next = n;
    n->next = *head;
    (*head)->val++;
}

void deleteF(Node* head){
    if(isEmpty(*head)){
        printf("\nThe list is empty, nothing to delete");
        return;
    }
    Node temp = (*head)->next;
    (*head)->next = temp->next;
    (*head)->val--;
    printf("\nThe deleted element is : %d", temp->val);
    free(temp);
}

void deleteR(Node* head){
    if(isEmpty(*head)){
        printf("\nThe list is empty, nothing to delete");
        return;
    }
    Node cur = (*head)->next;
    Node prev = (*head);
    while(cur->next!=*head){
        cur = cur->next;
        prev = prev->next;
    }
    prev->next = cur->next;
    printf("\nThe deleted element is : %d", cur->val);
    free(cur);
    (*head)->val--;
}

void display(Node head){
    if (isEmpty(head))
    {
        printf("\nThe list is empty, nothing to print");
        return;
    }
    printf("\n");
    int cnt = head->val;
    Node cur = head->next;
    while(cnt--){
        printf("%d\t", cur->val);
        cur = cur->next;
    }
}

int main()
{
    Node head;
    head->val = 0;
    head->next = head;
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
