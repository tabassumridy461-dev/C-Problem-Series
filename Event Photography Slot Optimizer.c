#include <stdio.h>
#include <string.h>

struct Booking {
    int id;
    char customer[50];
    char event[50];
    char date[20];
    char time[20];
    float price;
    int active;
};

int main() {
    struct Booking booking[100];

    int total = 0;
    int choice;
    int i, id;
    float income = 0;

    while (1) {

        printf("\nEvent Photography Slot Optimizer\n");
        printf("1. Add Booking\n");
        printf("2. View Bookings\n");
        printf("3. Search Booking\n");
        printf("4. Cancel Booking\n");
        printf("5. Available Slots\n");
        printf("6. Total Income\n");
        printf("7. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {

            int conflict = 0;

            printf("Booking ID: ");
            scanf("%d", &booking[total].id);

            printf("Customer Name: ");
            scanf(" %[^\n]", booking[total].customer);

            printf("Event Type: ");
            scanf(" %[^\n]", booking[total].event);

            printf("Date (DD-MM-YYYY): ");
            scanf("%s", booking[total].date);

            printf("Time (10AM/2PM/5PM): ");
            scanf("%s", booking[total].time);

            for (i = 0; i < total; i++) {
                if (booking[i].active == 1 &&
                    strcmp(booking[i].date, booking[total].date) == 0 &&
                    strcmp(booking[i].time, booking[total].time) == 0) {
                    conflict = 1;
                    break;
                }
            }

            if (conflict) {
                printf("This slot is already booked.\n");
                continue;
            }

            printf("Package Price: ");
            scanf("%f", &booking[total].price);

            booking[total].active = 1;

            income += booking[total].price;
            total++;

            printf("Booking Successful.\n");
        }

        else if (choice == 2) {

            int found = 0;

            for (i = 0; i < total; i++) {

                if (booking[i].active == 1) {

                    found = 1;

                    printf("\nBooking %d\n", i + 1);
                    printf("ID: %d\n", booking[i].id);
                    printf("Customer: %s\n", booking[i].customer);
                    printf("Event: %s\n", booking[i].event);
                    printf("Date: %s\n", booking[i].date);
                    printf("Time: %s\n", booking[i].time);
                    printf("Price: %.2f\n", booking[i].price);
                }
            }

            if (!found)
                printf("No Active Bookings.\n");
        }

        else if (choice == 3) {

            int found = 0;

            printf("Enter Booking ID: ");
            scanf("%d", &id);

            for (i = 0; i < total; i++) {

                if (booking[i].id == id && booking[i].active == 1) {

                    found = 1;

                    printf("Customer: %s\n", booking[i].customer);
                    printf("Event: %s\n", booking[i].event);
                    printf("Date: %s\n", booking[i].date);
                    printf("Time: %s\n", booking[i].time);
                    printf("Price: %.2f\n", booking[i].price);

                    break;
                }
            }

            if (!found)
                printf("Booking Not Found.\n");
        }

        else if (choice == 4) {

            int found = 0;

            printf("Enter Booking ID: ");
            scanf("%d", &id);

            for (i = 0; i < total; i++) {

                if (booking[i].id == id && booking[i].active == 1) {

                    booking[i].active = 0;
                    income -= booking[i].price;

                    printf("Booking Cancelled.\n");

                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Booking Not Found.\n");
        }

        else if (choice == 5) {

            char date[20];
            char slots[3][10] = {"10AM", "2PM", "5PM"};
            int j;

            printf("Enter Date: ");
            scanf("%s", date);

            printf("Available Slots:\n");

            for (j = 0; j < 3; j++) {

                int booked = 0;

                for (i = 0; i < total; i++) {

                    if (booking[i].active == 1 &&
                        strcmp(booking[i].date, date) == 0 &&
                        strcmp(booking[i].time, slots[j]) == 0) {

                        booked = 1;
                        break;
                    }
                }

                if (!booked)
                    printf("%s\n", slots[j]);
            }
        }

        else if (choice == 6) {

            printf("Total Active Bookings: ");

            int count = 0;

            for (i = 0; i < total; i++) {
                if (booking[i].active == 1)
                    count++;
            }

            printf("%d\n", count);
            printf("Total Income: %.2f\n", income);
        }

        else if (choice == 7) {

            printf("Program Ended.\n");
            break;
        }

        else {

            printf("Invalid Choice.\n");
        }
    }

    return 0;
}
