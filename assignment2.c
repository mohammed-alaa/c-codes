#include <stdio.h>

int main()
{
	int i, factor = 24;
	for (i = 1; i < factor; i++)
	{
		if (!(factor % i))
			printf("%d x %d = %d\n", i, factor / i, factor);
	}

	return 0;
}