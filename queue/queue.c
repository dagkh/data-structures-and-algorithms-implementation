#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node* ptr_previous;
} Node;

typedef struct queue
{
	struct node* tail;
	struct node* head;
	int count;
} Queue;

void Initialize(Queue* queue)
{
	queue->head = queue->tail = NULL;
	queue->count = 0;
}

Node* CreateNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if (node != NULL)
	{
		node->value = data;
		node->ptr_previous = NULL;
	}
	return node;
}

// Adds an node to the end of the Queue.
void Enqueue(Queue* queue, Node* node)
{
	if (queue->head == NULL)
		queue->head = queue->tail = node;
	else
	{
		queue->tail->ptr_previous = node;
		queue->tail = node;
	}
	queue->count++;
}

// Removes and returns the value of node at the beginning of the Queue.
int Dequeue(Queue* queue)
{
	int value = 0;
	if (queue->head != NULL)
	{
		Node* access_to_free = queue->head;
		queue->head = queue->head->ptr_previous;
		value = access_to_free->value;
		free(access_to_free);
	}
	queue->count--;
	return value;
}

// Returns the node at the beginning of the Queue without removing it.
Node* Peek(Queue* queue)
{
	Node* node = NULL;
	if (queue->head != NULL)
		node = queue->head;
	return node;
}

// Removes all node from the Queue.
void Clear(Queue* queue)
{
	while (queue->head != NULL)
		Dequeue(queue);
}

void Input(Queue* queue, int n)
{
	for (int i = 1; i <= n; i++)
	{
		int data;
		printf_s("\n Enter value for Node %d: ", i);
		scanf_s("%d", &data);
		Node* node = CreateNode(data);
		Enqueue(queue, node);
	}
}

void PrintQueue(Queue* queue)
{
	while (queue->head != NULL)
	{
		int value = Dequeue(queue);
		printf_s(" %d ", value);
	}
}

int main()
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	Initialize(queue);
	if (queue == NULL)
		return 0;
	Input(queue, 5);
	Clear(queue);
	PrintQueue(queue);

	_getch();
	return 0;
}