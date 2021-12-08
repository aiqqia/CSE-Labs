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

void push(char **Stack, int *top, int *capacity, char key)
{
    if (isFull(*top, *capacity))
    {
        //printf("\nThe stack is full, reallocating size;");
        *Stack = (char *)realloc(*Stack, sizeof(char) * (*capacity) * 2);
        *capacity *= 2;
    }
    (*top)++;
    (*Stack)[*top] = key;
}

char pop(char **Stack, int *top)
{
    char temp = (*Stack)[*top];
    (*top)--;
    return temp;
}

void display(char *Stack, int top)
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
            printf("%d\t", *(Stack + i));
        }
    }
}

void convert(char **infix, char **postfix, char **Stack, int *top, int *capacity)
{
    char *ptr = *postfix;
    char *ptr2 = *infix;
    for (int i = 0; ptr2[i] != '\0'; i++)
    {
        char cur = ptr2[i];
        if (cur == '(')
        {
            push(Stack, top, capacity, cur);
        }
        else if (cur == '+' || cur == '-')
        {
            while ((*Stack)[*top] == '*' || (*Stack)[*top] == '/' || (*Stack)[*top] == '%' || (*Stack)[*top] == '+' || (*Stack)[*top] == '-')
            {
                char ins = pop(Stack, top);
                *ptr = ins;
                ptr++;
            }
            push(Stack, top, capacity, cur);
        }
        else if (cur == '*' || cur == '/' || cur == '%')
        {
            while ((*Stack)[*top] == '*' || (*Stack)[*top] == '/' || (*Stack)[*top] == '%' || (*Stack)[*top] == '^')
            {
                char ins = pop(Stack, top);
                *ptr = ins;
                ptr++;
            }
            push(Stack, top, capacity, cur);
        }
        else if (cur == '^')
        {
            push(Stack, top, capacity, cur);
        }
        else if (cur == ')')
        {
            while ((*Stack)[*top] != '(')
            {
                char ins = pop(Stack, top);
                *ptr = ins;
                ptr++;
            }
            char rem = pop(Stack, top);
        }
        else
        {
            *ptr = cur;
            ptr++;
        }
    }
    if (!isEmpty(*top))
    {
        while (!isEmpty(*top))
        {
            char ins = pop(Stack, top);
            *ptr = ins;
            ptr++;
        }
    }
}

int main()
{
    int top = -1, capacity = 2;
    char *infix = (char *)calloc(100, sizeof(char));
    char *postfix = (char *)calloc(100, sizeof(char));
    char *Stack = (char *)calloc(capacity, sizeof(char));
    push(&Stack, &top, &capacity, '#');
    printf("\nOnly allowed operators are :\n^, +, -, *, /, %%\nEnter the infix expression : ");
    scanf("%s", infix);
    char **sendInfix = &infix;
    char **sendPostfix = &postfix;
    convert(sendInfix, sendPostfix, &Stack, &top, &capacity);
    printf("The postfix is : ");
    for (int i = 0; postfix[i] != '#'; i++)
    {
        printf("%c", postfix[i]);
    }
    printf("\n");
    return 0;
}