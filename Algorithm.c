#include <stdio.h>

int LinearSearch(int *arr, int length, int target)
{
	int x;
	for (x = 0; x < length; x++)
	{
		if (arr[x] == target)
			return x;
	}

	return -1;
}

int BinarySearch(int *arr, int target, int start, int end)
{
	if (start == end)
		return -1;

	if (arr[start] == target)
		return start;

	if (arr[start] > target)
		return BinarySearch(arr, target, (start - ((end - start) / 2)), start);

	return BinarySearch(arr, target, (start + ((end - start) / 2)), start);
}

int main()
{
	int target = 11;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int length = (sizeof(arr) / sizeof(arr[0]));
	printf("Found %d at index %d.\n", target, LinearSearch(arr, length, target));
	printf("Found %d at index %d.\n", target, BinarySearch(arr, target, (length / 2), length));
}