#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_SEATS 50

struct Ticket {
    int seatNo;
    char name[50];
    char phone[20];
    char event[50];
};

void bookTicket();
void viewReservations();
void searchReservation();
void cancelReservation();
void availableSeats();

int main() {
    int choice;

    while (1) {
        printf("\nEvent Ticket Reservation System\n");
        printf("1. Book Ticket\n");
        printf("2. View Reservations\n");
        printf("3. Search Reservation\n");
        printf("4. Cancel Reservation\n");
        printf("5. Available Seats\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookTicket();
                break;
            case 2:
                viewReservations();
                break;
            case 3:
                searchReservation();
                break;
            case 4:
                cancelReservation();
                break;
            case 5:
                availableSeats();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid Choice.\n");
        }
    }
}

void bookTicket() {
    struct Ticket ticket, temp;
    int booked[TOTAL_SEATS + 1] = {0};

    FILE *fp = fopen("tickets.dat", "rb");

    if (fp != NULL) {
        while (fread(&temp, sizeof(temp), 1, fp)) {
            booked[temp.seatNo] = 1;
        }
        fclose(fp);
    }

    int seat = -1;

    for (int i = 1; i <= TOTAL_SEATS; i++) {
        if (!booked[i]) {
            seat = i;
            break;
        }
    }

    if (seat == -1) {
        printf("No Seats Available.\n");
        return;
    }

    ticket.seatNo = seat;

    printf("Customer Name: ");
    scanf(" %[^\n]", ticket.name);

    printf("Phone Number: ");
    scanf("%s", ticket.phone);

    printf("Event Name: ");
    scanf(" %[^\n]", ticket.event);

    fp = fopen("tickets.dat", "ab");

    fwrite(&ticket, sizeof(ticket), 1, fp);

    fclose(fp);

    printf("Ticket Booked Successfully.\n");
    printf("Seat Number: %d\n", seat);
}

void viewReservations() {
    struct Ticket ticket;

    FILE *fp = fopen("tickets.dat", "rb");

    if (fp == NULL) {
        printf("No Reservations Found.\n");
        return;
    }

    printf("\nSeat\tCustomer\tPhone\t\tEvent\n");

    while (fread(&ticket, sizeof(ticket), 1, fp)) {
        printf("%d\t%s\t\t%s\t%s\n",
               ticket.seatNo,
               ticket.name,
               ticket.phone,
               ticket.event);
    }

    fclose(fp);
}

void searchReservation() {
    struct Ticket ticket;
    char phone[20];
    int found = 0;

    FILE *fp = fopen("tickets.dat", "rb");

    if (fp == NULL) {
        printf("No Reservations Found.\n");
        return;
    }

    printf("Enter Phone Number: ");
    scanf("%s", phone);

    while (fread(&ticket, sizeof(ticket), 1, fp)) {

        if (strcmp(ticket.phone, phone) == 0) {

            printf("\nReservation Found\n");
            printf("Seat Number : %d\n", ticket.seatNo);
            printf("Customer : %s\n", ticket.name);
            printf("Phone : %s\n", ticket.phone);
            printf("Event : %s\n", ticket.event);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Reservation Not Found.\n");
}

void cancelReservation() {
    struct Ticket ticket;
    char phone[20];
    int found = 0;

    FILE *fp = fopen("tickets.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (fp == NULL) {
        printf("No Reservations Found.\n");
        fclose(temp);
        return;
    }

    printf("Enter Phone Number: ");
    scanf("%s", phone);

    while (fread(&ticket, sizeof(ticket), 1, fp)) {

        if (strcmp(ticket.phone, phone) != 0) {
            fwrite(&ticket, sizeof(ticket), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("tickets.dat");
    rename("temp.dat", "tickets.dat");

    if (found)
        printf("Reservation Cancelled Successfully.\n");
    else
        printf("Reservation Not Found.\n");
}

void availableSeats() {
    struct Ticket ticket;
    int booked = 0;

    FILE *fp = fopen("tickets.dat", "rb");

    if (fp != NULL) {

        while (fread(&ticket, sizeof(ticket), 1, fp)) {
            booked++;
        }

        fclose(fp);
    }

    printf("Total Seats : %d\n", TOTAL_SEATS);
    printf("Booked Seats : %d\n", booked);
    printf("Available Seats : %d\n", TOTAL_SEATS - booked);
}
