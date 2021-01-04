#include <stdio.h>

struct operators
{
	int add;
	int sub;
	int mul;
};

struct operators operate(int, int);

int main()
{
	int num1 = 1, num2 = 3;
	struct operators result;
	result = operate(num1, num2);
	printf("%d %d %d\n", result.add, result.sub, result.mul);
}

struct operators operate(int num1, int num2)
{
	struct operators x;
	x.add = num1 + num2;
	x.sub = num1 - num2;
	x.mul = num1 * num2;
	return x;
}