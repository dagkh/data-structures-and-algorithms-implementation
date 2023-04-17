#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node* ptr_next;
} Node;

typedef struct stack
{
	struct node* top;
	int count;
} Stack;

Stack* Initial()
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	if (stack != NULL)
	{
		stack->top = NULL;
		stack->count = 0;
		return stack;
	}
	else return NULL;
}


Node* CreateNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if (node != NULL)
	{
		node->value = data;
		node->ptr_next = NULL;
	}
	return node;
}

// Returns the node at the top of the Stack without removing it.
Node* Peek(Stack* stack)
{
	Node* node = NULL;
	if (stack->top != NULL)
		node = stack->top;

	return node;
}

// Removes and returns the value of node at the top of the Stack.
int Pop(Stack* stack)
{
	int value = 0;
	if (stack->top != NULL)
	{
		Node* access_to_free = stack->top;
		stack->top = stack->top->ptr_next;
		value = access_to_free->value;
		free(access_to_free);
		stack->count--;
	}
	return value;
}

// Push the node to the Stack.
void Push(Stack* stack, Node* node)
{
	if (stack->top == NULL)
		stack->top = node;
	else
	{
		node->ptr_next = stack->top;
		stack->top = node;
	}
	stack->count++;
}

// Removes all node from the Stack.
void Clear(Stack* stack)
{
	while (stack->top != NULL)
		Pop(stack);
}

void Input(Stack* stack, int n)
{
	for (int i = 1; i <= n; i++)
	{
		int data;
		printf_s("\n Enter value for Node %d: ", i);
		scanf_s("%d", &data);
		Node* node = CreateNode(data);
		Push(stack, node);
	}
}

void PrintStack(Stack* stack)
{
	while (stack->top != NULL)
	{
		printf_s(" %d ", Peek(stack)->value);
		Pop(stack);
	}
	printf_s("\n");
}

int main()
{
	Stack* stack = Initial();
	Input(stack, 5);
	PrintStack(stack);

	char getch = _getch();
	return 0;
}