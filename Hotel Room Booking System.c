#include <stdio.h>
#include <string.h>

#define TOTAL_ROOMS 10

struct Room {
    int roomNumber;
    char guestName[50];
    int nights;
    float pricePerNight;
    int booked;
};

int main() {
    struct Room rooms[TOTAL_ROOMS];
    int choice, roomNo, i;
    float totalBill;

    for (i = 0; i < TOTAL_ROOMS; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].booked = 0;
        rooms[i].pricePerNight = 2000.0 + (i * 200);
        rooms[i].nights = 0;
        strcpy(rooms[i].guestName, "");
    }

    do {
        printf("\nHotel Room Booking System\n");
        printf("1. View All Rooms\n");
        printf("2. Book a Room\n");
        printf("3. View Booking Details\n");
        printf("4. Cancel Booking\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("\nRoom Status\n");
            for (i = 0; i < TOTAL_ROOMS; i++) {
                printf("Room %d | Price: %.2f | ",
                       rooms[i].roomNumber,
                       rooms[i].pricePerNight);

                if (rooms[i].booked)
                    printf("Booked\n");
                else
                    printf("Available\n");
            }
            break;

        case 2:
            printf("Enter room number (1-%d): ", TOTAL_ROOMS);
            scanf("%d", &roomNo);

            if (roomNo < 1 || roomNo > TOTAL_ROOMS) {
                printf("Invalid room number.\n");
                break;
            }

            if (rooms[roomNo - 1].booked) {
                printf("Room is already booked.\n");
            } else {
                printf("Enter guest name: ");
                scanf(" %[^\n]", rooms[roomNo - 1].guestName);

                printf("Enter number of nights: ");
                scanf("%d", &rooms[roomNo - 1].nights);

                rooms[roomNo - 1].booked = 1;

                totalBill = rooms[roomNo - 1].nights *
                            rooms[roomNo - 1].pricePerNight;

                printf("\nBooking Successful!\n");
                printf("Guest: %s\n", rooms[roomNo - 1].guestName);
                printf("Room: %d\n", roomNo);
                printf("Total Bill: %.2f\n", totalBill);
            }
            break;

        case 3:
            printf("\nBooking Details\n");

            for (i = 0; i < TOTAL_ROOMS; i++) {
                if (rooms[i].booked) {
                    totalBill = rooms[i].nights * rooms[i].pricePerNight;

                    printf("\nRoom Number : %d\n", rooms[i].roomNumber);
                    printf("Guest Name  : %s\n", rooms[i].guestName);
                    printf("Nights      : %d\n", rooms[i].nights);
                    printf("Rate/Night  : %.2f\n", rooms[i].pricePerNight);
                    printf("Total Bill  : %.2f\n", totalBill);
                }
            }
            break;

        case 4:
            printf("Enter room number to cancel booking: ");
            scanf("%d", &roomNo);

            if (roomNo < 1 || roomNo > TOTAL_ROOMS) {
                printf("Invalid room number.\n");
            } else if (!rooms[roomNo - 1].booked) {
                printf("This room is not booked.\n");
            } else {
                rooms[roomNo - 1].booked = 0;
                rooms[roomNo - 1].nights = 0;
                strcpy(rooms[roomNo - 1].guestName, "");

                printf("Booking cancelled successfully.\n");
            }
            break;

        case 5:
            printf("Thank you for using the Hotel Room Booking System.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}
