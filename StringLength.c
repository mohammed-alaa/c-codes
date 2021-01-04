#include <stdio.h>

int StringLength(char *);

int main()
{
	char string[] = "Hello World";
	printf("Length of %s is %d\n", string, StringLength(string));
}

int StringLength(char *str)
{
	int len = 0;
	while (str[len++]);
	return len;
}