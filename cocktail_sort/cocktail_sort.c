#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void swapping(int* num_a, int* num_b)
{
	int temp = *num_a;
	*num_a = *num_b;
	*num_b = temp;
}

int* random_array(int length)
{
	int* array = (int*)calloc(length, sizeof(int));
	if (array == NULL) return NULL;
	srand(time(0));
	for (int i = 0; i < length; i++)
		*(array + i) = (rand() % (50 - 10 + 1)) + 10;

	return array;
}

void print_array(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		printf_s(" %d ", *(arr + i));
	printf_s("\n");
}

void cocktail_sort(int* array, int length, char* order)
{
	int i;
	int start = 0;
	int end = length - 1;
	int is_not_sorted = 1;
	if (order == "increasing")
	{
		while (is_not_sorted)
		{
			is_not_sorted = 0;
			printf_s("\nForward Pass:\n");
			for (i = start; i < end; ++i)
			{
				if (*(array + i) > *(array + i + 1))
				{
					swapping(array + i, array + i + 1);
					is_not_sorted = 1;
				}
				print_array(array, length);
			}
			printf_s("\n");
			if (!is_not_sorted) break;

			--end;
			is_not_sorted = 0;
			printf_s("\Backward Pass:\n");
			for (i = end - 1; i >= start; --i)
			{
				printf_s(" (end = %d; i = %d; i + 1 = %d) array[i] = %d; array[i + 1] = %d ==>", end, i, i + 1, *(array + i), *(array + i + 1));
				if (*(array + i) > *(array + i + 1))
				{
					swapping(array + i, array + i + 1);
					is_not_sorted = 1;
				}
				print_array(array, length);
				printf_s("\n");
			}
			++start;
			printf_s("\n\n");
		}
	}
	else if (order == "decreasing")
	{
		while (is_not_sorted)
		{
			is_not_sorted = 0;
			for (i = start; i < end; ++i)
			{
				if (*(array + i) < *(array + i + 1))
				{
					swapping(array + i, array + i + 1);
					is_not_sorted = 1;
				}
			}

			if (!is_not_sorted) break;

			--end;
			is_not_sorted = 0;
			for (i = end - 1; i >= start; --i)
			{
				if (*(array + i) < *(array + i + 1))
				{
					swapping(array + i, array + i + 1);
					is_not_sorted = 1;
				}
			}
			++start;
			print_array(array, length);
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
		? cocktail_sort(array, length, "increasing")
		: cocktail_sort(array, length, "decreasing");

	printf_s("  After Sorted: ");
	print_array(array, length);

	free(array);

	char getch = _getch();
	return 0;
}