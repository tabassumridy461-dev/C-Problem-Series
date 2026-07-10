#include <stdio.h>
#include <string.h>

struct Booking {
    int id;
    char customerName[50];
    char phone[20];
    char packageName[50];
    char bookingDate[20];
    char bookingTime[20];
    float price;
};

int main() {
    struct Booking bookings[100];
    int choice;
    int totalBookings = 0;
    int searchId;
    int found;
    float totalIncome = 0;

    while (1) {
        printf("\nPhotography Studio Booking System\n");
        printf("1. Add Booking\n");
        printf("2. View All Bookings\n");
        printf("3. Search Booking\n");
        printf("4. Total Income\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Booking ID: ");
            scanf("%d", &bookings[totalBookings].id);

            printf("Customer Name: ");
            scanf(" %[^\n]", bookings[totalBookings].customerName);

            printf("Phone Number: ");
            scanf("%s", bookings[totalBookings].phone);

            printf("Package Name: ");
            scanf(" %[^\n]", bookings[totalBookings].packageName);

            printf("Booking Date: ");
            scanf("%s", bookings[totalBookings].bookingDate);

            printf("Booking Time: ");
            scanf("%s", bookings[totalBookings].bookingTime);

            printf("Package Price: ");
            scanf("%f", &bookings[totalBookings].price);

            totalIncome += bookings[totalBookings].price;
            totalBookings++;

            printf("Booking Added Successfully.\n");
        }

        else if (choice == 2) {

            if (totalBookings == 0) {
                printf("No Booking Available.\n");
            } else {
                for (int i = 0; i < totalBookings; i++) {
                    printf("\nBooking %d\n", i + 1);
                    printf("ID: %d\n", bookings[i].id);
                    printf("Customer: %s\n", bookings[i].customerName);
                    printf("Phone: %s\n", bookings[i].phone);
                    printf("Package: %s\n", bookings[i].packageName);
                    printf("Date: %s\n", bookings[i].bookingDate);
                    printf("Time: %s\n", bookings[i].bookingTime);
                    printf("Price: %.2f\n", bookings[i].price);
                }
            }
        }

        else if (choice == 3) {

            printf("Enter Booking ID: ");
            scanf("%d", &searchId);

            found = 0;

            for (int i = 0; i < totalBookings; i++) {
                if (bookings[i].id == searchId) {
                    printf("\nBooking Found\n");
                    printf("Customer: %s\n", bookings[i].customerName);
                    printf("Phone: %s\n", bookings[i].phone);
                    printf("Package: %s\n", bookings[i].packageName);
                    printf("Date: %s\n", bookings[i].bookingDate);
                    printf("Time: %s\n", bookings[i].bookingTime);
                    printf("Price: %.2f\n", bookings[i].price);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Booking Not Found.\n");
            }
        }

        else if (choice == 4) {
            printf("Total Bookings: %d\n", totalBookings);
            printf("Total Income: %.2f\n", totalIncome);
        }

        else if (choice == 5) {
            printf("Thank You.\n");
            break;
        }

        else {
            printf("Invalid Choice.\n");
        }
    }

    return 0;
}
