#include <stdio.h>

int main() {
    int vehicleNumber;
    int entryHour, entryMinute;
    int exitHour, exitMinute;
    int entryTime, exitTime;
    int totalMinutes;
    int hours;
    float parkingFee;

    printf("Parking Fee Calculator\n");

    printf("Enter Vehicle Number: ");
    scanf("%d", &vehicleNumber);

    printf("Enter Entry Time (HH MM): ");
    scanf("%d %d", &entryHour, &entryMinute);

    printf("Enter Exit Time (HH MM): ");
    scanf("%d %d", &exitHour, &exitMinute);

    entryTime = entryHour * 60 + entryMinute;
    exitTime = exitHour * 60 + exitMinute;

    if (exitTime < entryTime) {
        printf("Invalid exit time.\n");
        return 0;
    }

    totalMinutes = exitTime - entryTime;

    hours = totalMinutes / 60;
    if (totalMinutes % 60 != 0)
        hours++;

    if (hours <= 1)
        parkingFee = 50;
    else
        parkingFee = 50 + (hours - 1) * 30;

    printf("\nVehicle Number: %d\n", vehicleNumber);
    printf("Parking Time: %d minutes\n", totalMinutes);
    printf("Charged Hours: %d\n", hours);
    printf("Parking Fee: %.2f Taka\n", parkingFee);

    return 0;
}
