#include <stdio.h>

struct Book {
    int bookId;
    char title[50];
    char borrower[50];
    int days;
};

int main() {
    struct Book books[100];
    int n, i;
    int totalDays = 0;

    printf("Enter number of borrowed books: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nBook %d\n", i + 1);

        printf("Enter Book ID: ");
        scanf("%d", &books[i].bookId);

        printf("Enter Book Title: ");
        scanf("%s", books[i].title);

        printf("Enter Borrower Name: ");
        scanf("%s", books[i].borrower);

        printf("Enter Borrowing Days: ");
        scanf("%d", &books[i].days);
    }

    printf("\nBorrowed Book Details\n");

    for(i = 0; i < n; i++) {
        printf("\nBook ID: %d\n", books[i].bookId);
        printf("Book Title: %s\n", books[i].title);
        printf("Borrower: %s\n", books[i].borrower);
        printf("Borrowing Days: %d\n", books[i].days);

        totalDays += books[i].days;
    }

    printf("\nTotal Borrowing Days: %d\n", totalDays);

    return 0;
}
