#include <stdio.h>
#include <string.h>

struct Reservation {
    int studentId;
    char studentName[50];
    int seatNo;
    char date[20];
    char timeSlot[20];
    int active;
};

int main() {

    struct Reservation reserve[100];

    int total = 0;
    int choice;
    int seat, id;
    int found, booked;

    while (1) {

        printf("\nLibrary Seat Reservation System\n");
        printf("1. Reserve Seat\n");
        printf("2. View Reservations\n");
        printf("3. Search Reservation\n");
        printf("4. Cancel Reservation\n");
        printf("5. Show Available Seats\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {

            printf("Student ID: ");
            scanf("%d", &reserve[total].studentId);

            printf("Student Name: ");
            scanf(" %[^\n]", reserve[total].studentName);

            printf("Seat Number (1-20): ");
            scanf("%d", &reserve[total].seatNo);

            printf("Reservation Date: ");
            scanf("%s", reserve[total].date);

            printf("Time Slot (Morning/Afternoon/Evening): ");
            scanf("%s", reserve[total].timeSlot);

            booked = 0;

            for (int i = 0; i < total; i++) {

                if (reserve[i].active == 1 &&
                    reserve[i].seatNo == reserve[total].seatNo &&
                    strcmp(reserve[i].date, reserve[total].date) == 0 &&
                    strcmp(reserve[i].timeSlot, reserve[total].timeSlot) == 0) {

                    booked = 1;
                    break;
                }
            }

            if (booked) {

                printf("Seat Already Reserved.\n");
            }
            else {

                reserve[total].active = 1;
                total++;

                printf("Reservation Successful.\n");
            }
        }

        else if (choice == 2) {

            found = 0;

            for (int i = 0; i < total; i++) {

                if (reserve[i].active == 1) {

                    printf("\nStudent ID : %d\n", reserve[i].studentId);
                    printf("Student Name : %s\n", reserve[i].studentName);
                    printf("Seat Number : %d\n", reserve[i].seatNo);
                    printf("Date : %s\n", reserve[i].date);
                    printf("Time Slot : %s\n", reserve[i].timeSlot);

                    found = 1;
                }
            }

            if (!found)
                printf("No Reservations Found.\n");
        }

        else if (choice == 3) {

            printf("Enter Student ID: ");
            scanf("%d", &id);

            found = 0;

            for (int i = 0; i < total; i++) {

                if (reserve[i].studentId == id && reserve[i].active == 1) {

                    printf("Student Name : %s\n", reserve[i].studentName);
                    printf("Seat Number : %d\n", reserve[i].seatNo);
                    printf("Date : %s\n", reserve[i].date);
                    printf("Time Slot : %s\n", reserve[i].timeSlot);

                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Reservation Not Found.\n");
        }

        else if (choice == 4) {

            printf("Enter Student ID: ");
            scanf("%d", &id);

            found = 0;

            for (int i = 0; i < total; i++) {

                if (reserve[i].studentId == id && reserve[i].active == 1) {

                    reserve[i].active = 0;

                    printf("Reservation Cancelled.\n");

                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Reservation Not Found.\n");
        }

        else if (choice == 5) {

            printf("\nAvailable Seats\n");

            for (seat = 1; seat <= 20; seat++) {

                booked = 0;

                for (int i = 0; i < total; i++) {

                    if (reserve[i].active == 1 &&
                        reserve[i].seatNo == seat) {

                        booked = 1;
                        break;
                    }
                }

                if (!booked)
                    printf("Seat %d\n", seat);
            }
        }

        else if (choice == 6) {

            printf("Program Ended.\n");
            break;
        }

        else {

            printf("Invalid Choice.\n");
        }

    }

    return 0;
}
