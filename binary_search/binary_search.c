#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int BinarySearch(int array[], int length, int value)
{
	int left = 0, right = length - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (value == array[mid])
			return mid;
		else if (value > array[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

int main()
{
	printf_s("\n Enter value want to find: ");
	int value;
	scanf_s("%d", &value);
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	int length = sizeof(array) / sizeof(array[0]);
	int index = BinarySearch(array, length, value);
	index == -1
		? printf_s("\n Element is not present in array")
		: printf_s("\n Element is present at index %d", index);

	char getch = _getch();
	return 0;
}