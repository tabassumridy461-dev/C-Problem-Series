#include <stdio.h>

int main() {
    int choice;

    printf("Choose an option:\n");
    printf("1. Apple\n");
    printf("2. Banana\n");
    printf("3. Mango\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You selected Apple.\n");
            break;

        case 2:
            printf("You selected Banana.\n");
            break;

        case 3:
            printf("You selected Mango.\n");
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
