#include <stdio.h>

int Math_operations(int, int, int);

int main()
{
	int (*ptr)(int, int, int);
	ptr = Math_operations;
	int num1 = 1, num2 = 2;

	printf("%d + %d = %d\n", num1, num2, (*ptr)(num1, num2, 1));
	printf("%d - %d = %d\n", num1, num2, (*ptr)(num1, num2, 2));
	printf("%d x %d = %d\n", num1, num2, (*ptr)(num1, num2, 3));
}

int Math_operations(int num1, int num2, int op)
{
	switch(op)
	{
		case 1: // Add
			return num1 + num2;
		break;
		case 2: // Sub
			return num1 - num2;
		break;
		case 3: // Mul
			return num1 * num2;
		break;
		default: return 0;
	}
}