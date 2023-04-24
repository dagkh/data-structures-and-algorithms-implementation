#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node* ptr_next;
	struct node* ptr_previous;
} Node;

typedef struct linkedList
{
	struct node* head;
	struct node* tail;
	int count;
} LinkedList;

LinkedList* initial()
{
	LinkedList* linkedList = (LinkedList*)malloc(sizeof(LinkedList));
	if (linkedList != NULL)
	{
		linkedList->head = linkedList->tail = NULL;
		linkedList->count = 0;
		return linkedList;
	}
	else return NULL;
}

Node* create_node(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if (node != NULL)
	{
		node->value = data;
		node->ptr_next = node->ptr_previous = NULL;
	}
	return node;
}

// Adds a new node containing the specified value at the start of the LinkedList.
void add_first(LinkedList* linkedList, Node* node)
{
	if (linkedList->head == NULL)
		linkedList->head = linkedList->tail = node;
	else
	{
		node->ptr_next = linkedList->head;
		linkedList->head->ptr_previous = node;
		linkedList->head = node;
	}
	linkedList->count++;
}

// Adds a new node containing the specified value at the end of the LinkedList.
void add_last(LinkedList* linkedList, Node* node)
{
	if (linkedList->head == NULL)
		linkedList->head = linkedList->tail = node;
	else
	{
		linkedList->tail->ptr_next = node;
		node->ptr_previous = linkedList->tail;
		linkedList->tail = node;
	}
	linkedList->count++;
}

void input(LinkedList* linkedList, int n)
{
	for (int i = 1; i <= n; i++)
	{
		int data;
		printf_s("\n Enter value for Node %d: ", i);
		scanf_s("%d", &data);
		Node* node = create_node(data);
		add_last(linkedList, node);
	}
}

// Removes the node at the start of the LinkedList.
void remove_first(LinkedList* linkedList)
{
	if (linkedList->head != NULL)
	{
		Node* access_to_free = linkedList->head;
		linkedList->head = linkedList->head->ptr_next;
		linkedList->head->ptr_previous = NULL;
		free(access_to_free);
	}
	linkedList->count--;
}

// Removes the node at the end of the LinkedList.
void remove_last(LinkedList* linkedList)
{
	if (linkedList->head != NULL)
	{
		Node* access_to_free = linkedList->tail;
		linkedList->tail = linkedList->tail->ptr_previous;
		linkedList->tail->ptr_next = NULL;
		free(access_to_free);
		linkedList->count--;
	}
}

// Removes all nodes from the LinkedList.
void clear(LinkedList* linkedList)
{
	Node* access_to_delete = NULL;
	while (linkedList->head != NULL)
	{
		access_to_delete = linkedList->head;
		linkedList->head = linkedList->head->ptr_next;
		free(access_to_delete);
	}
}

void print_Linkedlist(LinkedList* linkedList)
{
	for (Node* i = linkedList->head; i != NULL; i = i->ptr_next)
	{
		printf_s(" %d ", i->value);
	}
	printf_s("\n");
}

int main()
{
	LinkedList* linkedList = initial();
	int n;
	printf_s("\n Enter number of elements: ");
	scanf_s("%d", &n);
	input(linkedList, n);
	print_Linkedlist(linkedList);
	clear(linkedList);

	char getch = _getch();
	return 0;
}