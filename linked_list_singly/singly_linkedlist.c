#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node* ptr_next;
} Node;

typedef struct linkedList
{
	struct node* head;
	struct node* tail;
	int count;
} LinkedList;

LinkedList* Initial()
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

// Adds a new node containing the specified value at the start of the LinkedList.
void AddFirst(LinkedList* linkedList, Node* node)
{
	if (linkedList->head == NULL)
		linkedList->head = linkedList->tail = node;
	else
	{
		node->ptr_next = linkedList->head;
		linkedList->head = node;
	}
	linkedList->count++;
}

// Adds a new node containing the specified value at the end of the LinkedList.
void AddLast(LinkedList* linkedList, Node* node)
{
	if (linkedList->head == NULL)
		linkedList->head = linkedList->tail = node;
	else
	{
		linkedList->tail->ptr_next = node;
		linkedList->tail = node;
	}
	linkedList->count++;
}

void Input(LinkedList* linkedList, int n)
{
	for (int i = 1; i <= n; i++)
	{
		int data;
		printf_s("\n Enter value for Node %d: ", i);
		scanf_s("%d", &data);
		Node* node = CreateNode(data);
		AddLast(linkedList, node);
	}
}

// Removes the node at the start of the LinkedList.
void RemoveFirst(LinkedList* linkedList)
{
	if (linkedList->head != NULL)
	{
		Node* access_to_free = linkedList->head;
		linkedList->head = linkedList->head->ptr_next;
		free(access_to_free);
	}
	linkedList->count--;
}

// Removes the node at the end of the LinkedList.
void RemoveLast(LinkedList* linkedList)
{
	if (linkedList->head != NULL)
	{
		Node* node_before_tail = linkedList->head;
		for (Node* i = linkedList->head->ptr_next; i != linkedList->tail; i = i->ptr_next)
		{
			node_before_tail = i;
		}
		Node* access_to_free = linkedList->tail;
		linkedList->tail = node_before_tail;
		linkedList->tail->ptr_next = NULL;
		free(access_to_free);
	}
	linkedList->count--;
}

// Removes all nodes from the LinkedList.
void Clear(LinkedList* linkedList)
{
	Node* access_to_delete = NULL;
	while (linkedList->head != NULL)
	{
		access_to_delete = linkedList->head;
		linkedList->head = linkedList->head->ptr_next;
		free(access_to_delete);
	}
}

void PrintLinkedList(LinkedList* linkedList)
{
	for (Node* i = linkedList->head; i != NULL; i = i->ptr_next)
	{
		printf_s(" %d ", i->value);
	}
	printf_s("\n");
}

int main()
{
	LinkedList* linkedList = Initial();

	int n;
	printf_s("\n Enter number of elements: ");
	scanf_s("%d", &n);
	Input(linkedList, n);
	PrintLinkedList(linkedList);
	Clear(linkedList);

	char getch = _getch();
	return 0;
}