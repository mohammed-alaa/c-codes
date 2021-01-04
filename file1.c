#include <stdio.h>
#include "MathLib.h"
#include "ErrorLog.h"

unsigned short inputError;
unsigned int validateInput(unsigned int);
unsigned char ScanUIntToChar(void);

int main()
{
	unsigned char param_1 = ScanUIntToChar();
	if (!inputError)
	{
		unsigned char param_2 = ScanUIntToChar();
		if (!inputError)
			printf("\n%hhu + %hhu = %hhu", param_1, param_2, Math_Add(param_1, param_2));
	}
}

unsigned int validateInput(unsigned int input)
{
	return ((input >= 0) && (input <= 255));
}

unsigned char ScanUIntToChar(void)
{
	unsigned int input, attempt = 1;
	inputError = 0;
	do
	{
		printf("\nAttempt %d => Enter number between 0-255: ", attempt++);
		if (!scanf("%u", &input))
		{
			inputError = 1;
			ErrLog_Log();
			break;
		}
	} while (!validateInput(input));

	return (unsigned char) input;
}