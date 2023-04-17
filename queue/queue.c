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
	Node* tail;
	Node* head;
	int count;
} Queue;

Queue* Initial()
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	if (queue != NULL)
	{
		queue->head = queue->tail = NULL;
		queue->count = 0;
		return queue;
	}
	else return NULL;
}

Node* CreateNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if (node != NULL)
	{
		node->value = data;
		node->ptr_previous = NULL;
		return node;
	}
	return NULL;
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
	if (queue->head != NULL)
	{
		Node* node = NULL;
		node = queue->head;
		return node;
	}
	return NULL;
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
	Queue* queue = Initial();
	Input(queue, 5);
	PrintQueue(queue);
	Clear(queue);

	char getch = _getch();
	return 0;
}