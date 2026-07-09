#include <stdio.h>

struct Parcel {
    int trackingId;
    char sender[50];
    char receiver[50];
    float weight;
    char status[30];
};

int main() {
    struct Parcel parcels[100];
    int n, i;

    printf("Enter number of parcels: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nParcel %d\n", i + 1);

        printf("Enter Tracking ID: ");
        scanf("%d", &parcels[i].trackingId);

        printf("Enter Sender Name: ");
        scanf("%s", parcels[i].sender);

        printf("Enter Receiver Name: ");
        scanf("%s", parcels[i].receiver);

        printf("Enter Parcel Weight (kg): ");
        scanf("%f", &parcels[i].weight);

        printf("Enter Delivery Status: ");
        scanf("%s", parcels[i].status);
    }

    printf("\nParcel Information\n");

    for(i = 0; i < n; i++) {
        printf("\nTracking ID: %d\n", parcels[i].trackingId);
        printf("Sender: %s\n", parcels[i].sender);
        printf("Receiver: %s\n", parcels[i].receiver);
        printf("Weight: %.2f kg\n", parcels[i].weight);
        printf("Status: %s\n", parcels[i].status);
    }

    return 0;
}
