#include <stdio.h>

struct BankAccount {
    int accountNumber;
    char accountHolder[50];
    float balance;
};

int main() {
    struct BankAccount account;
    int choice;
    float amount;

    printf("Bank Account Management System\n");

    printf("Enter Account Number: ");
    scanf("%d", &account.accountNumber);

    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", account.accountHolder);

    printf("Enter Initial Balance: ");
    scanf("%f", &account.balance);

    do {
        printf("\n1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Current Balance: %.2f Taka\n", account.balance);
            break;

        case 2:
            printf("Enter Deposit Amount: ");
            scanf("%f", &amount);

            if (amount > 0) {
                account.balance += amount;
                printf("Deposit Successful.\n");
            } else {
                printf("Invalid Amount.\n");
            }
            break;

        case 3:
            printf("Enter Withdrawal Amount: ");
            scanf("%f", &amount);

            if (amount <= 0) {
                printf("Invalid Amount.\n");
            } else if (amount > account.balance) {
                printf("Insufficient Balance.\n");
            } else {
                account.balance -= amount;
                printf("Withdrawal Successful.\n");
            }
            break;

        case 4:
            printf("Thank You.\n");
            break;

        default:
            printf("Invalid Choice.\n");
        }

    } while (choice != 4);

    return 0;
}
