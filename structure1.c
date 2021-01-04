#include <stdio.h>

struct SComplex
{
	double m_R;
	double m_I;	
};

struct SComplex AddComplex(struct SComplex, struct SComplex);
struct SComplex ReadComplex(char *);
void PrintComplex(char *, struct SComplex);

int main()
{
	struct SComplex a, b, sum;
	a = ReadComplex("");
	b = ReadComplex("");
	sum = AddComplex(a, b);
	PrintComplex("", sum);
}

struct SComplex ReadComplex(char name[])
{
	struct SComplex input;
	double real, imag;
	printf("Enter Real number: ");
	scanf("%lf", &real);
	printf("Enter imaginary number: ");
	scanf("%lf", &imag);

	input.m_R = real;
	input.m_I = imag;
	return input;
}

struct SComplex AddComplex(struct SComplex a, struct SComplex b)
{
	struct SComplex result;
	result.m_R = a.m_R + b.m_R;
	result.m_I = a.m_I + b.m_I;
	return result;
}

void PrintComplex(char name[], struct SComplex c)
{
	printf("%.2lf + %.2lfi\n", c.m_R, c.m_I);
	printf("Real number: %.2lf\nImaginary number: %.2lfi\n", c.m_R, c.m_I);
}