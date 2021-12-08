#include <stdio.h>
#include <stdlib.h>

int isEmpty(int top)
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(int top, int capacity)
{
    if (top == capacity - 1)
    {
        return 1;
    }
    return 0;
}

void push(int **Stack, int *top, int *capacity, int key)
{
    if (isFull(*top, *capacity))
    {
        printf("\nThe stack is full, reallocating size;");
        *Stack = (int *)realloc(*Stack, sizeof(int) * (*capacity) * 2);
        *capacity *= 2;
    }
    (*top)++;
    (*Stack)[*top] = key;
}

int pop(int **Stack, int *top)
{
    int temp = (*Stack)[*top];
    (*top)--;
    return temp;
}

void display(int *Stack, int top)
{
    if (isEmpty(top))
    {
        printf("\nThe stack is empty, nothing to print");
    }
    else
    {
        printf("\n");
        int i;
        for (i = 0; i <= top; i++)
        {
            printf("%d\t", *(Stack+i));
        }
    }
}

int main()
{
    int top = -1, capacity = 2;
    int *Stack = (int *)calloc(capacity, sizeof(int));
    int choice = 0, ele;
    while (choice < 6)
    {
        printf("\n1 : Display the Stack \n2 : Pop the  top \n3 : Push an element \n4 : Peek the top \n5 : Check for empty \n6 : Exit");
        printf("\nEnter the operation to be done: ");
        scanf("%d", &choice);
        printf("\n#################");
        switch (choice)
        {
        case 1:
            display(Stack, top);
            break;

        case 2:
            if (isEmpty(top))
            {
                printf("\nThe stack is empty, nothing to pop");
            }
            else
            {
                ele = pop(&Stack, &top);
                printf("\nThe popped element is %d", ele);
            }
            break;

        case 3:
            printf("\nEnter the element to be pushed : ");
            scanf("%d", &ele);
            push(&Stack, &top, &capacity, ele);
            break;

        case 4:
            if (isEmpty(top))
            {
                printf("\nThe stack is empty");
            }
            else
            {
                printf("\nThe top of the stack is %d", Stack[top]);
            }
            break;

        case 5:
            if (isEmpty(top))
            {
                printf("\nThe stack is empty");
            }
            else
            {
                printf("\nStack is not empty. Stack has %d elements", top + 1);
            }
            break;
        }
        printf("\n#################\n");
    }
    return 0;
}