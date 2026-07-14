#include <stdio.h>

// Recursive function to calculate factorial
int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number < 0)
    {
        printf("Factorial is not defined for negative numbers.\n");
    }
    else
    {
        printf("Factorial of %d = %d\n", number, factorial(number));
    }

    return 0;
}
