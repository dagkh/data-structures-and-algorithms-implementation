#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/*
************************************************************
*					TREE IMPLEMENTATION
************************************************************
*/

typedef struct tree_node
{
	int data;
	struct tree_node* ptr_left;
	struct tree_node* ptr_right;
} TNode;

TNode* Create_TNode(int data)
{
	TNode* tree_node = (TNode*)malloc(sizeof(TNode));
	if (tree_node == NULL) return NULL;
	tree_node->data = data;
	tree_node->ptr_left = tree_node->ptr_right = NULL;
	return tree_node;
}

void InsertLeft(TNode* root, TNode* node_left)
{
	root->ptr_left = node_left;
}

void InsertRight(TNode* root, TNode* node_right)
{
	root->ptr_left = node_right;
}

/*
************************************************************
*					QUEUE IMPLEMENTATION
************************************************************
*/
typedef struct queue_node
{
	TNode* tree_node;
	struct queue_node* ptr_next;
	struct queue_node* ptr_previous;
} QNode;

typedef struct queue
{
	QNode* head;
	QNode* tail;
} Queue;

Queue* Initial_Queue()
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	if (queue != NULL)
		queue->head = queue->tail = NULL;
	else return NULL;
}

QNode* Create_QNode(TNode* tree_node)
{
	QNode* queue_node = (QNode*)malloc(sizeof(QNode));
	if (queue_node != NULL)
	{
		queue_node->tree_node = tree_node;
		queue_node->ptr_previous = queue_node->ptr_next = NULL;
		return queue_node;
	}
	return NULL;
}

// Adds an node to the end of the Queue.
void Enqueue(Queue* queue, TNode* tree_node)
{
	QNode* queue_node = Create_QNode(tree_node);
	if (queue->head == NULL)
		queue->head = queue->tail = queue_node;
	else
	{
		queue_node->ptr_next = queue->tail;
		queue->tail->ptr_previous = queue_node;
		queue->tail = queue_node;
	}
}

// Removes node at the beginning of the Queue.
void Dequeue(Queue* queue)
{
	if (queue->head != NULL)
	{
		QNode* access_to_free = queue->head;
		queue->head = queue->head->ptr_previous;
		if (queue->head != NULL)
			queue->head->ptr_next = NULL;
		free(access_to_free);
	}
	else
		return;
}

// Returns the node at the beginning of the Queue without removing it.
TNode* Peek(Queue* queue)
{
	if (queue->head != NULL)
	{
		QNode* queue_node = NULL;
		queue_node = queue->head;
		return queue_node->tree_node;
	}
	return NULL;
}

// Removes all node from the Queue.
void Clear(Queue* queue)
{
	while (queue->head != NULL)
		Dequeue(queue);
}

int Is_Queue_Empty(Queue* queue)
{
	if (queue->head == NULL) return 1;
	return 0;
}

void PrintQueue(Queue* queue)
{
	printf_s("  QUEUE:");
	QNode* access = queue->tail;
	printf_s("\n  --------------------------------\n");
	while (access != NULL)
	{
		printf_s("  %d ", access->tree_node->data);
		access = access->ptr_next;
	}
	printf_s("\n  --------------------------------\n\n");
}

/*
************************************************************
*					TREE PROCESSING
************************************************************
*/

TNode* Enter_Data(const char* string)
{
	TNode* tree_node = (TNode*)malloc(sizeof(TNode));
	printf_s("  Enter data for NODE %s: ", string);
	int data;
	scanf_s("%d", &data);
	tree_node = Create_TNode(data);
	return tree_node;
}

TNode* Initial_Tree()
{
	TNode* root = Enter_Data("root");

	Queue* queue = Initial_Queue();
	Enqueue(queue, root);
	PrintQueue(queue);

	while (!Is_Queue_Empty(queue))
	{
		TNode* node_head = Peek(queue);
		Dequeue(queue);

		printf_s("\n Pop node %d success !", node_head->data);
		printf_s("\n How many node-childs do you want to add for NODE %d - (0 or 1 or 2): ", node_head->data);
		int number_of_childs;
		scanf_s("%d", &number_of_childs);

		if (number_of_childs == 1)
		{
			char trash;
			scanf_s("%c", &trash, 1);
			fflush(stdin);

			printf_s("\n Left or Right - (L or R): ");
			char left_of_right;
			scanf_s("%c", &left_of_right, 1);

			TNode* node_want_to_add = NULL;
			if (left_of_right == 'L' || left_of_right == 'l')
			{
				node_want_to_add = Enter_Data("left child");
				node_head->ptr_left = node_want_to_add;
			}
			else
			{
				node_want_to_add = Enter_Data("right child");
				node_head->ptr_right = node_want_to_add;
			}
			Enqueue(queue, node_want_to_add);
		}
		else if (number_of_childs == 2)
		{
			TNode* node_want_to_add;

			node_want_to_add = Enter_Data("left child");
			node_head->ptr_left = node_want_to_add;
			Enqueue(queue, node_want_to_add);

			node_want_to_add = Enter_Data("right child");
			node_head->ptr_right = node_want_to_add;
			Enqueue(queue, node_want_to_add);
		}
		PrintQueue(queue);
	}
	return root;
}

int main()
{
	TNode* root = Initial_Tree();

	char getch = _getch();
	return 0;
}