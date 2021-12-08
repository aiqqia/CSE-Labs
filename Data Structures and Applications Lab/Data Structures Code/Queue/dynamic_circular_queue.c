// this is dynamic CIRCULAR queue not dynamic queue

#include <stdio.h>
#include <stdlib.h>

int isEmpty(int front, int rear)
{
    if (front == rear)
    {
        return 1;
    }
    return 0;
}

int isFull(int front, int rear, int capacity)
{
    if ((rear + 1) % capacity == front)
    {
        return 1;
    }
    return 0;
}

void display(int *Queue, int front, int rear, int capacity)
{
    if (isEmpty(front, rear))
    {
        printf("\nThe queue is empty, nothing to print");
    }
    else
    {
        printf("\n");
        for (int i = (front + 1) % capacity; i != (rear + 1) % capacity; i = (i + 1) % capacity)
        {
            printf("%d\t", Queue[i]);
        }
    }
}

void push(int **Queue, int *front, int *rear, int *capacity, int key)
{
    printf("\nReached push command");
    if (isFull(*front, *rear, *capacity))
    {
        printf("\nThe queue is full, allocating space");
        int *newQueue = (int *)calloc((*capacity) * 2, sizeof(int));
        int i, j;
        for (i = 1, j = (*front + 1) % (*capacity); j != (*rear + 1) % (*capacity); j = (j + 1) % (*capacity), i++)
        {
            newQueue[i] = (*Queue)[j];
        }
        int *temp = *Queue;
        *Queue = newQueue;
        *capacity = *capacity * 2;
        *front = 0;
        *rear = --i;
        free(temp);
    }
    *rear = (*rear + 1) % (*capacity);
    (*Queue)[*rear] = key;
}

int pop(int **Queue, int *front, int *rear, int *capacity)
{
    int temp = (*Queue)[(*front + 1) % (*capacity)];
    *front = (*front + 1) % (*capacity);
    return temp;
}

int main()
{
    int front = 0, rear = 0, capacity = 2;
    int *Queue = (int *)calloc(capacity, sizeof(int));
    int choice = 0, ele;
    while (choice < 6)
    {
        printf("\n1 : Display the Queue \n2 : Pop the  top \n3 : Push an element \n4 : Peek the top \n5 : Check for empty \n6 : Exit");
        printf("\nEnter the operation to be done: ");
        scanf("%d", &choice);
        printf("\n#################");
        switch (choice)
        {
        case 1:
            display(Queue, front, rear, capacity);
            break;

        case 2:
            if (isEmpty(front, rear))
            {
                printf("\nThe stack is empty, nothing to pop");
            }
            else
            {
                ele = pop(&Queue, &front, &rear, &capacity);
                printf("\nThe popped element is %d", ele);
            }
            break;

        case 3:
            printf("\nEnter the element to be pushed : ");
            scanf("%d", &ele);
            push(&Queue, &front, &rear, &capacity, ele);
            break;

        case 4:
            if (isEmpty(front, rear))
            {
                printf("\nThe stack is empty");
            }
            else
            {
                printf("\nThe top of the stack is %d", Queue[(front + 1) % capacity]);
            }
            break;

        case 5:
            if (isEmpty(front, rear))
            {
                printf("\nThe stack is empty");
            }
            else
            {
                printf("\nStack is not empty.");
            }
            break;
        }
        printf("\n#################\n");
    }
    return 0;
}