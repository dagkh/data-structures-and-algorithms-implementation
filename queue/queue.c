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

Queue* initial()
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

Node* create_node(int data)
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
void enqueue(Queue* queue, Node* node)
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
int dequeue(Queue* queue)
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
Node* peek(Queue* queue)
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
void clear(Queue* queue)
{
	while (queue->head != NULL)
		dequeue(queue);
}

void input(Queue* queue, int n)
{
	for (int i = 1; i <= n; i++)
	{
		int data;
		printf_s("\n Enter value for Node %d: ", i);
		scanf_s("%d", &data);
		Node* node = create_node(data);
		enqueue(queue, node);
	}
}

void print_queue(Queue* queue)
{
	while (queue->head != NULL)
	{
		int value = dequeue(queue);
		printf_s(" %d ", value);
	}
}

int main()
{
	Queue* queue = initial();
	input(queue, 5);
	print_queue(queue);
	clear(queue);

	char getch = _getch();
	return 0;
}