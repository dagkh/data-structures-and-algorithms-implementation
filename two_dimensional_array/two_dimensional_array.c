#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int** Calloc_Matrix(int row, int column)
{
	int** matrix = (int**)calloc(row, sizeof(int*));
	if (matrix != NULL)
	{
		for (int i = 0; i < row; i++)
			*(matrix + i) = (int*)calloc(column, sizeof(int));
		return matrix;
	}
	return NULL;
}

void Set_Matrix(int** matrix, int row, int column)
{
	printf_s("\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf_s("matrix[%d][%d] = ", i, j);
			scanf_s("%d", *(matrix + i) + j);
		}
		printf_s("\n");
	}
}

void Print_Matrix(int** matrix, int row, int column)
{
	printf_s("\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf_s(" %d ", *(*(matrix + i) + j));
		}
		printf_s("\n");
	}
}

void Free_Matrix(int** matrix, int row)
{
	for (int i = 0; i < row; i++)
		free(*(matrix + i));
	free(matrix);
}

int main()
{
	/*int row, column;
	printf_s("\n Enter row: ");
	scanf_s("%d", &row);
	printf_s(" Enter column: ");
	scanf_s("%d", &column);
	int** matrix = Calloc_Matrix(row, column);

	Set_Matrix(matrix, row, column);
	Print_Matrix(matrix, row, column);
	Free_Matrix(matrix, row);*/

	int a = 5;
	int* ptr_a = &a;
	printf_s("\n a = %d", a);
	printf_s("\n ptr_a = %d", *ptr_a);
	int** ptr_to_ptr_a = &ptr_a;

	printf_s("");

	char getch = _getch();
	return 0;
}