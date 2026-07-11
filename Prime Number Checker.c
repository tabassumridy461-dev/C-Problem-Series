#include <stdio.h>

int main() {

    int number, i, isPrime = 1;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number <= 1) {
        isPrime = 0;
    } else {
        for (i = 2; i <= number / 2; i++) {
            if (number % i == 0) {
                isPrime = 0;
                break;
            }
        }
    }

    if (isPrime == 1) {
        printf("%d is a Prime Number.\n", number);
    } else {
        printf("%d is Not a Prime Number.\n", number);
    }

    return 0;
}
