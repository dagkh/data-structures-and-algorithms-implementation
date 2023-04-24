#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void swapping(int* num_a, int* num_b)
{
	int temp = *num_a;
	*num_a = *num_b;
	*num_b = temp;
}

// Generates numbers in range [upper, lower].
// int num = (rand() % (upper - lower + 1)) + lower
int* random_array(int length)
{
	int* array = (int*)calloc(length, sizeof(int));
	if (array == NULL) return NULL;
	srand(time(0));
	for (int i = 0; i < length; i++)
		*(array + i) = (rand() % (50 - 10 + 1)) + 10;
	
	return array;
}

void bubble_sort(int* array, int length, char* order)
{
	if (order == "increasing")
	{
		for (int i = 0; i < length - 1; i++)
		{
			for (int j = 0; j < length - 1 - i; j++)
			{
				if (*(array + j) > *(array + j + 1))
					swapping(array + j, array + j + 1);
			}
		}
	}
	else if (order == "decreasing")
	{
		for (int i = 0; i < length - 1; i++)
		{
			for (int j = 0; j < length - 1 - i; j++)
			{
				if (*(array + j) < *(array + j + 1))
					swapping(array + j, array + j + 1);
			}
		}
	}
}

void print_array(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		printf_s(" %d ", *(arr + i));
	printf_s("\n");
}

int main()
{
	//FILE* write_file;

	//// Declaring a variable of type errno_t to store the return value of fopen_s
	//errno_t error_code = fopen_s(&write_file, "C:\\PROGRAMMING\\Projects\\data_structures_and_algorithms\\input.txt", "w");
	//if (error_code != 0)
	//{
	//	printf_s("\n Error! Failed to open file w mode!");
	//	exit(1);
	//}
	//else
	//{
	//	srand(time(0));
	//	for (int i = 1; i <= 100000; i++)
	//	{
	//		int random_number = rand() % 501; // random 1.000.000 numbers between 0 and 500
	//		fprintf_s(write_file, "%d ", random_number);
	//	}
	//	fclose(write_file);
	//	printf_s("\n Write data to file successful!");
	//}

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
		? bubble_sort(array, length, "increasing")
		: bubble_sort(array, length, "decreasing");

	printf_s("  After Sorted: ");
	print_array(array, length);

	free(array);

	char getch = _getch();
	return 0;
}