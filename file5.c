#include <stdio.h>

#define ARRAY_SIZE 5

int main()
{
	int x, arr[ARRAY_SIZE];
	for (x = 0; x < ARRAY_SIZE; x++)
	{
		printf("Enter student %d degree: ", (x + 1));
		// scanf("%d", &arr[x]);
	}

	for (x = 0; x < ARRAY_SIZE; x++)
		printf("Student %d degree: %d\n", (x + 1), arr[x]);
}