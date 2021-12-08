#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

typedef struct
{
    int front, rear;
    int array[MAX_QUEUE_SIZE];
} Queue;

int isFull(Queue q)
{
    if ((q.rear + 1) % MAX_QUEUE_SIZE == q.front)
    {
        return 1;
    }
    return 0;
}

int isEmpty(Queue q)
{
    if (q.front == q.rear)
    {
        return 1;
    }
    return 0;
}

void display(Queue q)
{
    if (isEmpty(q))
    {
        printf("\nThe queue is empty, nothing to print");
    }
    else
    {
        printf("\n");
        for (int i = (q.front + 1) % MAX_QUEUE_SIZE; i != (q.rear + 1) % MAX_QUEUE_SIZE; i = (i + 1) % MAX_QUEUE_SIZE)
        {
            printf("%d\t", q.array[i]);
        }
    }
}

void push(Queue *q, int key)
{
    if (isFull(*q))
    {
        printf("\nThe queue is  full, cannot push");
    }
    else
    {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->array[q->rear] = key;
    }
}

int pop(Queue *q)
{
    int temp = q->array[(q->front + 1) % MAX_QUEUE_SIZE];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return temp;
}

int front(Queue q)
{
    return q.array[(q.front + 1) % MAX_QUEUE_SIZE];
}

int main()
{
    Queue intQueue;
    intQueue.front = 0;
    intQueue.rear = 0;
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
            display(intQueue);
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
                printf("\nNeither empty nor full.");
            }
            break;
        }
        printf("\n#################\n");
    }
    return 0;
}
