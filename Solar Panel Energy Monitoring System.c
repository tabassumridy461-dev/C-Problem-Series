#include <stdio.h>
#include <string.h>

struct SolarPanel {
    int panelId;
    char location[50];
    float energyGenerated;
    float energyConsumed;
    float batteryStored;
    float efficiency;
};

int main() {

    struct SolarPanel panel[100];

    int total = 0;
    int choice;
    int id;
    float totalGenerated = 0;
    float totalConsumed = 0;
    float totalProfit = 0;

    while (1) {

        printf("\nSolar Panel Energy Monitoring System\n");
        printf("1. Add Solar Panel Record\n");
        printf("2. View All Records\n");
        printf("3. Search Panel\n");
        printf("4. Daily Energy Report\n");
        printf("5. Low Battery Alert\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {

            printf("Panel ID: ");
            scanf("%d", &panel[total].panelId);

            printf("Location: ");
            scanf(" %[^\n]", panel[total].location);

            printf("Energy Generated (kWh): ");
            scanf("%f", &panel[total].energyGenerated);

            printf("Energy Consumed (kWh): ");
            scanf("%f", &panel[total].energyConsumed);

            printf("Battery Stored (kWh): ");
            scanf("%f", &panel[total].batteryStored);

            panel[total].efficiency =
                (panel[total].energyConsumed / panel[total].energyGenerated) * 100;

            totalGenerated += panel[total].energyGenerated;
            totalConsumed += panel[total].energyConsumed;

            if (panel[total].energyGenerated > panel[total].energyConsumed) {
                totalProfit +=
                    (panel[total].energyGenerated - panel[total].energyConsumed) * 8;
            }

            total++;

            printf("Record Added Successfully.\n");
        }

        else if (choice == 2) {

            if (total == 0) {
                printf("No Records Available.\n");
            }
            else {

                for (int i = 0; i < total; i++) {

                    printf("\nPanel %d\n", i + 1);
                    printf("Panel ID: %d\n", panel[i].panelId);
                    printf("Location: %s\n", panel[i].location);
                    printf("Generated: %.2f kWh\n", panel[i].energyGenerated);
                    printf("Consumed: %.2f kWh\n", panel[i].energyConsumed);
                    printf("Battery: %.2f kWh\n", panel[i].batteryStored);
                    printf("Efficiency: %.2f %%\n", panel[i].efficiency);
                }
            }
        }

        else if (choice == 3) {

            int found = 0;

            printf("Enter Panel ID: ");
            scanf("%d", &id);

            for (int i = 0; i < total; i++) {

                if (panel[i].panelId == id) {

                    printf("Location: %s\n", panel[i].location);
                    printf("Generated: %.2f kWh\n", panel[i].energyGenerated);
                    printf("Consumed: %.2f kWh\n", panel[i].energyConsumed);
                    printf("Battery: %.2f kWh\n", panel[i].batteryStored);
                    printf("Efficiency: %.2f %%\n", panel[i].efficiency);

                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Panel Not Found.\n");
        }

        else if (choice == 4) {

            printf("\nDaily Energy Report\n");
            printf("Total Panels: %d\n", total);
            printf("Total Energy Generated: %.2f kWh\n", totalGenerated);
            printf("Total Energy Consumed: %.2f kWh\n", totalConsumed);
            printf("Remaining Energy: %.2f kWh\n",
                   totalGenerated - totalConsumed);
            printf("Estimated Profit: %.2f\n", totalProfit);
        }

        else if (choice == 5) {

            int found = 0;

            printf("\nPanels With Low Battery (<20 kWh)\n");

            for (int i = 0; i < total; i++) {

                if (panel[i].batteryStored < 20) {

                    printf("Panel ID: %d\n", panel[i].panelId);
                    printf("Location: %s\n", panel[i].location);
                    printf("Battery: %.2f kWh\n\n",
                           panel[i].batteryStored);

                    found = 1;
                }
            }

            if (!found)
                printf("No Low Battery Alerts.\n");
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
