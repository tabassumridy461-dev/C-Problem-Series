#include <stdio.h>

void checkBalance(float balance) {
    printf("\nCurrent Balance: %.2f Taka\n", balance);
}

float depositMoney(float balance) {
    float amount;

    printf("Enter deposit amount: ");
    scanf("%f", &amount);

    if (amount > 0) {
        balance += amount;
        printf("Deposit Successful.\n");
    } else {
        printf("Invalid amount.\n");
    }

    return balance;
}

float withdrawMoney(float balance) {
    float amount;

    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount.\n");
    } else if (amount > balance) {
        printf("Insufficient Balance.\n");
    } else {
        balance -= amount;
        printf("Withdrawal Successful.\n");
    }

    return balance;
}

int main() {
    int choice;
    float balance = 5000.00;

    do {
        printf("\nATM Cash Withdrawal Simulation\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;

            case 2:
                balance = depositMoney(balance);
                break;

            case 3:
                balance = withdrawMoney(balance);
                break;

            case 4:
                printf("Thank you for using the ATM.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}
