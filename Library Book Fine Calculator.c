#include <stdio.h>

int main() {
    int allowedDays, returnedDays, lateDays;
    float fine = 0;

    printf("Library Book Fine Calculator\n");

    printf("Enter allowed borrowing days: ");
    scanf("%d", &allowedDays);

    printf("Enter total days taken to return the book: ");
    scanf("%d", &returnedDays);

    lateDays = returnedDays - allowedDays;

    if (lateDays <= 0) {
        printf("\nBook returned on time.\n");
        printf("Late Days: 0\n");
        printf("Total Fine: 0.00 Taka\n");
    } else {
        if (lateDays <= 5)
            fine = lateDays * 5;
        else if (lateDays <= 10)
            fine = (5 * 5) + ((lateDays - 5) * 10);
        else
            fine = (5 * 5) + (5 * 10) + ((lateDays - 10) * 20);

        printf("\nLate Days: %d\n", lateDays);
        printf("Total Fine: %.2f Taka\n", fine);
    }

    return 0;
}
