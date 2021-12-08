#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

typedef struct
{
    int front, rear;
    int array[MAX_QUEUE_SIZE];
} Queue;

int isEmpty(Queue q)
{
    if (q.front == -1 && q.rear == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(Queue q)
{
    if (q.rear == MAX_QUEUE_SIZE - 1)
    {
        return 1;
    }
    return 0;
}

void print(Queue q)
{
    if (isEmpty(q))
    {
        printf("\nThe queue is empty, nothing to print");
    }
    else
    {
        printf("\n");
        for (int i = q.front; i <= q.rear; i++)
        {
            printf("%d\t", q.array[i]);
        }
    }
}

void push(Queue *q, int key)
{
    if (isFull(*q))
    {
        printf("\nThe queue is full, cannot push");
    }
    else
    {
        if (q->front == -1 && q->rear == -1)
        {
            q->front++;
        }
        q->array[++q->rear] = key;
    }
}

int pop(Queue *q)
{
    int temp = q->array[q->front];
    q->front++;
    if (q->front > q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    return temp;
}

int front(Queue q)
{
    return q.array[q.front];
}
int main()
{
    Queue intQueue;
    intQueue.front = -1;
    intQueue.rear = -1;
    int choice = 0, ele;
    while (choice < 6)
    {
        printf("\n1 : Display the Queue \n2 : Pop the top \n3 : Push an element \n4 : Peek the top \n5 : Check for empty or full \n6 : Exit");
        printf("\nEnter the operation to be done: ");
        scanf("%d", &choice);
        printf("\n#################");
        switch (choice)
        {
        case 1:
            print(intQueue);
            break;

        case 2:
            if (isEmpty(intQueue))
            {
                printf("\nThe queue is empty, nothing to pop");
            }
            else
            {
                ele = pop(&intQueue);
                printf("\nThe popped element is %d", ele);
            }
            break;

        case 3:
            printf("\nEnter the element to be pushed : ");
            scanf("%d", &ele);
            push(&intQueue, ele);
            break;

        case 4:
            if (isEmpty(intQueue))
            {
                printf("\nThe queue is empty");
            }
            else
            {
                ele = front(intQueue);
                printf("\nThe top of the queue is %d", ele);
            }
            break;

        case 5:
            if (isEmpty(intQueue))
            {
                printf("\nThe queue is empty");
            }
            else if (isFull(intQueue))
            {
                printf("\nThe queue is full");
            }
            else
            {
                printf("\nNeither empty nor full. Queue has %d element(s)", intQueue.rear - intQueue.front + 1);
            }
            break;
        }
        printf("\n#################\n");
    }
    return 0;
}
