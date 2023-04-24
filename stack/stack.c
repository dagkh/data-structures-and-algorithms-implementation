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

Stack* initial()
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


Node* create_node(int data)
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
Node* peek(Stack* stack)
{
	Node* node = NULL;
	if (stack->top != NULL)
		node = stack->top;

	return node;
}

// Removes and returns the value of node at the top of the Stack.
int pop(Stack* stack)
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

// push the node to the Stack.
void push(Stack* stack, Node* node)
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
void clear(Stack* stack)
{
	while (stack->top != NULL)
		pop(stack);
}

void input(Stack* stack, int n)
{
	for (int i = 1; i <= n; i++)
	{
		int data;
		printf_s("\n Enter value for Node %d: ", i);
		scanf_s("%d", &data);
		Node* node = create_node(data);
		push(stack, node);
	}
}

void	print_stack(Stack* stack)
{
	while (stack->top != NULL)
	{
		printf_s(" %d ", peek(stack)->value);
		pop(stack);
	}
	printf_s("\n");
}

int main()
{
	Stack* stack = initial();
	input(stack, 5);
	print_stack(stack);

	char getch = _getch();
	return 0;
}