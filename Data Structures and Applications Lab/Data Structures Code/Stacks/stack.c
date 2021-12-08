#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 50

typedef struct
{
	int array[MAX_STACK_SIZE];
	int top;
} Stack;

int isEmpty(Stack s)
{
	if (s.top == -1)
	{
		return 1;
	}
	return 0;
}

int isFull(Stack s)
{
	if (s.top == MAX_STACK_SIZE - 1)
	{
		return 1;
	}
	return 0;
}

void push(Stack *s, int key)
{
	if (isFull(*s))
	{
		printf("\nThe stack is full");
	}
	s->top++;
	s->array[s->top] = key;
}

int pop(Stack *s)
{
	int temp = s->array[s->top];
	s->top--;
	return temp;
}

void display(Stack s)
{
	if (isEmpty(s))
	{
		printf("\nThe stack is empty");
	}
	else
	{
		printf("\n");
		for (int i = 0; i <= s.top; i++)
		{
			printf("%d\t", s.array[i]);
		}
	}
}

int front(Stack s)
{
	return s.array[s.top];
}

int main()
{
	Stack intStack;
	intStack.top = -1;
	int choice = 0, ele;
	while (choice < 6)
	{
		printf("\n1 : Display the Stack \n2 : Pop the  top \n3 : Push an element \n4 : Peek the top \n5 : Check for empty or full \n6 : Exit");
		printf("\nEnter the operation to be done: ");
		scanf("%d", &choice);
		printf("\n#################");
		switch (choice)
		{
		case 1:
			display(intStack);
			break;

		case 2:
			if (isEmpty(intStack))
			{
				printf("\nThe stack is empty, nothing to pop");
			}
			else
			{
				ele = pop(&intStack);
				printf("\nThe popped element is %d", ele);
			}
			break;

		case 3:
			printf("\nEnter the element to be pushed : ");
			scanf("%d", &ele);
			push(&intStack, ele);
			break;

		case 4:
			if (isEmpty(intStack))
			{
				printf("\nThe stack is empty");
			}
			else
			{
				ele = front(intStack);
				printf("\nThe top of the stack is %d", ele);
			}
			break;

		case 5:
			if (isEmpty(intStack))
			{
				printf("\nThe stack is empty");
			}
			else if (isFull(intStack))
			{
				printf("\nThe stack is full");
			}
			else
			{
				printf("\nNeither empty nor full. Stack has %d elements", intStack.top + 1);
			}
			break;
		}
		printf("\n#################\n");
	}
	return 0;
}