#include <stdio.h>

int isPrime(int num);

int main()
{
	int x;
	printf("Enter number: ");
	scanf("%d", &x);
	printf("\n%d is%s prime\n", x, (!isPrime(x) ? " not" : ""));
}

int isPrime(int num)
{
	if (num < 2) return 0;
	if (num == 2) return 1;

	int x;
	for (x = 3; x < (num/2); x++)
	{
		if (!(num % x))
			return 0;
	}

	return 1;
}