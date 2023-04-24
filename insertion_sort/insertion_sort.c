#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int* random_array(int length)
{
	int* array = (int*)calloc(length, sizeof(int));
	if (array == NULL) return NULL;
	srand(time(0));
	for (int i = 0; i < length; i++)
		*(array + i) = (rand() % (50 - 10 + 1)) + 10;

	return array;
}

void swapping(int* num_a, int* num_b)
{
	int temp = *num_a;
	*num_a = *num_b;
	*num_b = temp;
}

void print_array(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		printf_s(" %d ", *(arr + i));
	printf_s("\n");
}

void insertion_sort(int* array, int length, char* order)
{
	int i, j, current_element;
	if (order == "decreasing")
	{
		for (i = 1; i < length; i++)
		{
			j = i - 1;
			current_element = *(array + i);
			while (current_element > *(array + j) && j >= 0)
			{
				*(array + j + 1) = *(array + j);
				--j;
			}
			*(array + j + 1) = current_element;
		}
	}
	else if (order == "increasing")
	{
		for (i = 1; i < length; i++)
		{
			j = i - 1;
			current_element = *(array + i);
			while (current_element < *(array + j) && j >= 0)
			{
				*(array + j + 1) = *(array + j);
				--j;
			}
			*(array + j + 1) = current_element;
		}
	}
}

int main()
{
	int length;
	printf_s("\n Enter number RANDOM elements of the array: ");
	scanf_s("%d", &length);
	int* array = random_array(length);

	printf_s("  Before Sorted: ");
	print_array(array, length);

	printf_s("  Enter your order want to sort (increasing - 1, decreasing - 2): ");
	int order;
	scanf_s("%d", &order);

	order == 1
		? insertion_sort(array, length, "increasing")
		: insertion_sort(array, length, "decreasing");

	printf_s("  After Sorted: ");
	print_array(array, length);

	free(array);

	char getch = _getch();
	return 0;
}