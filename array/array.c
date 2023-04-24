#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void print_array(int* array, int length)
{
	printf_s("  ==> ");
	for (int i = 0; i < length; i++)
		printf_s(" %d ", *(array + i));
}

void input_array(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf_s("  Enter value for element[%d]: ", i);
		scanf_s("%d", array + i);
	}
}

int main()
{
	printf_s("\n Enter number of elements in array: ");
	int n;
	scanf_s("%d", &n);
	int* array = (int*)malloc(n * sizeof(int));
	input_array(array, n);
	print_array(array, n);

	free(array);

	char getch = _getch();
	return 0;
}