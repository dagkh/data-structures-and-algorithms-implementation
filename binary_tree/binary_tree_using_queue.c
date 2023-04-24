#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/*
************************************************************
******************* TREE IMPLEMENTATION ********************
************************************************************
*/

typedef struct tree_node
{
	int data;
	struct tree_node* ptr_left;
	struct tree_node* ptr_right;
} TNode;

TNode* create_tnode(int data)
{
	TNode* tree_node = (TNode*)malloc(sizeof(TNode));
	if (tree_node == NULL) return NULL;
	tree_node->data = data;
	tree_node->ptr_left = tree_node->ptr_right = NULL;
	return tree_node;
}

void insert_left(TNode* root, TNode* node_left)
{
	root->ptr_left = node_left;
}

void insert_right(TNode* root, TNode* node_right)
{
	root->ptr_left = node_right;
}

/*
************************************************************
******************* QUEUE IMPLEMENTATION *******************
************************************************************
*/
typedef struct queue_node
{
	TNode* tree_node;
	struct queue_node* ptr_previous;
} QNode;

typedef struct queue
{
	QNode* head;
	QNode* tail;
} Queue;

Queue* initial_queue()
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	if (queue != NULL)
		queue->head = queue->tail = NULL;
	else return NULL;
}

QNode* create_qnode(TNode* tree_node)
{
	QNode* queue_node = (QNode*)malloc(sizeof(QNode));
	if (queue_node != NULL)
	{
		queue_node->tree_node = tree_node;
		queue_node->ptr_previous = NULL;
		return queue_node;
	}
	return NULL;
}

// Adds an node to the end of the Queue.
void enqueue(Queue* queue, TNode* tree_node)
{
	QNode* queue_node = create_qnode(tree_node);
	if (queue->head == NULL)
		queue->head = queue->tail = queue_node;
	else
	{
		queue->tail->ptr_previous = queue_node;
		queue->tail = queue_node;
	}
}

// Removes node at the beginning of the Queue.
void dequeue(Queue* queue)
{
	if (queue->head != NULL)
	{
		QNode* access_to_free = queue->head;
		queue->head = queue->head->ptr_previous;
		free(access_to_free);
	}
	else
		return;
}

// Returns the node at the beginning of the Queue without removing it.
TNode* peek(Queue* queue)
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
void clear(Queue* queue)
{
	while (queue->head != NULL)
		dequeue(queue);
}

int is_queue_empty(Queue* queue)
{
	if (queue->head == NULL) return 1;
	return 0;
}

/*
************************************************************
******************* TREE INPUT & OUTPUT ********************
************************************************************
*/

TNode* enter_data(const char* string)
{
	TNode* tree_node = (TNode*)malloc(sizeof(TNode));
	printf_s("  Enter data for NODE %s: ", string);
	int data;
	scanf_s("%d", &data);
	tree_node = create_tnode(data);
	return tree_node;
}

TNode* initial_tree()
{
	TNode* root = enter_data("root");

	Queue* queue = initial_queue();
	enqueue(queue, root);

	while (!is_queue_empty(queue))
	{
		TNode* node_head = peek(queue);
		dequeue(queue);

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
				node_want_to_add = enter_data("left child");
				node_head->ptr_left = node_want_to_add;
			}
			else
			{
				node_want_to_add = enter_data("right child");
				node_head->ptr_right = node_want_to_add;
			}
			enqueue(queue, node_want_to_add);
		}
		else if (number_of_childs == 2)
		{
			TNode* node_want_to_add;

			node_want_to_add = enter_data("left child");
			node_head->ptr_left = node_want_to_add;
			enqueue(queue, node_want_to_add);

			node_want_to_add = enter_data("right child");
			node_head->ptr_right = node_want_to_add;
			enqueue(queue, node_want_to_add);
		}
	}
	return root;
}

// BFS using Queue
void breadth_first_traversal(TNode* root)
{
	Queue* queue = initial_queue();
	if (root != NULL)
		enqueue(queue, root);

	while (!is_queue_empty(queue))
	{
		TNode* node_first_of_queue = peek(queue);
		printf_s(" %d ", node_first_of_queue->data);
		dequeue(queue);

		if (node_first_of_queue->ptr_left != NULL)
			enqueue(queue, node_first_of_queue->ptr_left);
		if (node_first_of_queue->ptr_right != NULL)
			enqueue(queue, node_first_of_queue->ptr_right);
	}
}

// DFS using Recursion
void preorder(TNode* root)
{
	if (root != NULL)
	{
		printf_s(" %d ", root->data);
		preorder(root->ptr_left);
		preorder(root->ptr_right);
	}
}

void inorder(TNode* root)
{
	if (root != NULL)
	{
		inorder(root->ptr_left);
		printf_s(" %d ", root->data);
		inorder(root->ptr_right);
	}
}

void postorder(TNode* root)
{
	if (root != NULL)
	{
		postorder(root->ptr_left);
		postorder(root->ptr_right);
		printf_s(" %d ", root->data);
	}
}

void free_tree(TNode* root)
{
	if (root != NULL)
	{
		free_tree(root->ptr_left);
		free_tree(root->ptr_right);
		free(root);
		root = NULL;
	}
}

int main()
{
	//TNode* root = initial_tree();
	TNode* root = create_tnode(1);
	TNode* two = create_tnode(2);
	TNode* three = create_tnode(3);
	TNode* four = create_tnode(4);
	TNode* five = create_tnode(5);
	TNode* six = create_tnode(6);
	TNode* seven = create_tnode(7);
	TNode* eight = create_tnode(8);
	TNode* nine = create_tnode(9);
	TNode* ten = create_tnode(10);
	TNode* eleven = create_tnode(11);
	TNode* twelve = create_tnode(12);
	TNode* thirteen = create_tnode(13);
	TNode* fourteen = create_tnode(14);

	root->ptr_left = two;
	root->ptr_right = three;

	two->ptr_left = four;
	two->ptr_right = five;

	three->ptr_left = six;
	three->ptr_right = seven;

	four->ptr_left = eight;
	four->ptr_right = nine;

	five->ptr_left = ten;
	five->ptr_right = eleven;

	six->ptr_right = thirteen;

	seven->ptr_left = fourteen;

	printf_s("\n Breadth First Traversal: ");
	breadth_first_traversal(root);

	printf_s("\n\n Depth First Traversals: ");
	printf_s("\n	preorder Traversal : ");
	preorder(root);
	printf_s("\n	inorder Traversal  : ");
	inorder(root);
	printf_s("\n	postorder Traversal: ");
	postorder(root);

	free_tree(root);

	char getch = _getch();
	return 0;
}