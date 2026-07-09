#include <stdio.h>

struct Bicycle {
    int rentalId;
    char customerName[50];
    char bicycleType[30];
    int hours;
    float rentPerHour;
};

int main() {
    struct Bicycle rentals[100];
    int n, i;
    float totalIncome = 0;

    printf("Enter number of rental records: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nRental %d\n", i + 1);

        printf("Enter Rental ID: ");
        scanf("%d", &rentals[i].rentalId);

        printf("Enter Customer Name: ");
        scanf("%s", rentals[i].customerName);

        printf("Enter Bicycle Type: ");
        scanf("%s", rentals[i].bicycleType);

        printf("Enter Rental Hours: ");
        scanf("%d", &rentals[i].hours);

        printf("Enter Rent Per Hour: ");
        scanf("%f", &rentals[i].rentPerHour);
    }

    printf("\nBicycle Rental Details\n");

    for(i = 0; i < n; i++) {
        float totalRent = rentals[i].hours * rentals[i].rentPerHour;

        printf("\nRental ID: %d\n", rentals[i].rentalId);
        printf("Customer Name: %s\n", rentals[i].customerName);
        printf("Bicycle Type: %s\n", rentals[i].bicycleType);
        printf("Rental Hours: %d\n", rentals[i].hours);
        printf("Rent Per Hour: %.2f\n", rentals[i].rentPerHour);
        printf("Total Rent: %.2f\n", totalRent);

        totalIncome += totalRent;
    }

    printf("\nTotal Rental Income: %.2f\n", totalIncome);

    return 0;
}
