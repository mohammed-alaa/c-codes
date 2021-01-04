#include <stdio.h>

#define length 8

void Count_Repeated(int *, int, int *);

int main()
{
	int x, arr[length] = { 2, 4, 2, 5, 6, 4, 5, 2 },
		counter[length] = { 0 },
		appeared[length] = { 0 };

	Count_Repeated(arr, length, counter);
	for (x = 0; x < 8; x++)
	{
		if (!appeared[arr[x]] && (counter[arr[x]] - 1) > 0)
		{
			appeared[arr[x]] = 1;
			printf("%d is repeated %d times\n", arr[x], counter[arr[x]] - 1);
		}
	}
}

void Count_Repeated(int *arr, int size, int *counter)
{
	int x;
	for (x = 0; x < size; x++)
		counter[arr[x]]++;
}