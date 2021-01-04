#include <stdio.h>

int main()
{
    int n1, n2;
    printf("Enter numbers as: n1 n1\n");
    scanf("%d %d", &n1, &n2);

    printf("1st Num: %d\n", n1);
    printf("2nd Num: %d\n", n2);

    printf("Addition: %d\n", n1 + n2);
    printf("Subtraction: %d\n", n1 - n2);
    printf("Multiplication: %d\n", n1 * n2);
    printf("Division: %d\n", n1 / n2);
    printf("Remainder: %d\n", n1 % n2);
    return 0;
}
