#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int BinarySearch(int* array, int length, int value)
{

}

int main()
{
	printf_s("\n Enter value want to find: ");
	int value;
	scanf_s("%d", &value);
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int length = sizeof(array) / sizeof(array[0]);
	int index = BinarySearch(array, length, value);
	index == -1
		? printf_s("\n Element is not present in array")
		: printf_s("\n Element is present at index %d", index);

	_getch();
	return 0;
}