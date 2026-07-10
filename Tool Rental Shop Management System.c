#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tool {
    int toolId;
    char toolName[50];
    char customerName[50];
    int rentalDays;
    float rentPerDay;
};

void addRental();
void viewRentals();
void searchRental();
void updateRental();
void deleteRental();
void calculateRevenue();

int main() {
    int choice;

    while (1) {
        printf("\nTool Rental Shop Management\n");
        printf("1. Add Rental\n");
        printf("2. View Rentals\n");
        printf("3. Search Rental\n");
        printf("4. Update Rental\n");
        printf("5. Delete Rental\n");
        printf("6. Calculate Total Revenue\n");
        printf("7. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRental();
                break;
            case 2:
                viewRentals();
                break;
            case 3:
                searchRental();
                break;
            case 4:
                updateRental();
                break;
            case 5:
                deleteRental();
                break;
            case 6:
                calculateRevenue();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid Choice.\n");
        }
    }
}

void addRental() {
    struct Tool tool;

    FILE *fp = fopen("tools.dat", "ab");

    if (fp == NULL) {
        printf("File Error.\n");
        return;
    }

    printf("Tool ID: ");
    scanf("%d", &tool.toolId);

    printf("Tool Name: ");
    scanf(" %[^\n]", tool.toolName);

    printf("Customer Name: ");
    scanf(" %[^\n]", tool.customerName);

    printf("Rental Days: ");
    scanf("%d", &tool.rentalDays);

    printf("Rent Per Day: ");
    scanf("%f", &tool.rentPerDay);

    fwrite(&tool, sizeof(tool), 1, fp);

    fclose(fp);

    printf("Rental Added Successfully.\n");
}

void viewRentals() {
    struct Tool tool;

    FILE *fp = fopen("tools.dat", "rb");

    if (fp == NULL) {
        printf("No Rentals Found.\n");
        return;
    }

    printf("\nID\tTool\t\tCustomer\tDays\tRent/Day\n");

    while (fread(&tool, sizeof(tool), 1, fp)) {
        printf("%d\t%s\t\t%s\t%d\t%.2f\n",
               tool.toolId,
               tool.toolName,
               tool.customerName,
               tool.rentalDays,
               tool.rentPerDay);
    }

    fclose(fp);
}

void searchRental() {
    struct Tool tool;
    int id;
    int found = 0;

    FILE *fp = fopen("tools.dat", "rb");

    if (fp == NULL) {
        printf("No Rentals Found.\n");
        return;
    }

    printf("Enter Tool ID: ");
    scanf("%d", &id);

    while (fread(&tool, sizeof(tool), 1, fp)) {

        if (tool.toolId == id) {

            printf("\nRental Found\n");
            printf("Tool Name: %s\n", tool.toolName);
            printf("Customer: %s\n", tool.customerName);
            printf("Rental Days: %d\n", tool.rentalDays);
            printf("Rent Per Day: %.2f\n", tool.rentPerDay);
            printf("Total Rent: %.2f\n",
                   tool.rentalDays * tool.rentPerDay);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Rental Not Found.\n");
}

void updateRental() {
    struct Tool tool;
    int id;
    int found = 0;

    FILE *fp = fopen("tools.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (fp == NULL) {
        printf("No Rentals Found.\n");
        fclose(temp);
        return;
    }

    printf("Enter Tool ID: ");
    scanf("%d", &id);

    while (fread(&tool, sizeof(tool), 1, fp)) {

        if (tool.toolId == id) {

            printf("New Customer Name: ");
            scanf(" %[^\n]", tool.customerName);

            printf("New Rental Days: ");
            scanf("%d", &tool.rentalDays);

            printf("New Rent Per Day: ");
            scanf("%f", &tool.rentPerDay);

            found = 1;
        }

        fwrite(&tool, sizeof(tool), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("tools.dat");
    rename("temp.dat", "tools.dat");

    if (found)
        printf("Rental Updated Successfully.\n");
    else
        printf("Rental Not Found.\n");
}

void deleteRental() {
    struct Tool tool;
    int id;
    int found = 0;

    FILE *fp = fopen("tools.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (fp == NULL) {
        printf("No Rentals Found.\n");
        fclose(temp);
        return;
    }

    printf("Enter Tool ID: ");
    scanf("%d", &id);

    while (fread(&tool, sizeof(tool), 1, fp)) {

        if (tool.toolId != id) {
            fwrite(&tool, sizeof(tool), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("tools.dat");
    rename("temp.dat", "tools.dat");

    if (found)
        printf("Rental Deleted Successfully.\n");
    else
        printf("Rental Not Found.\n");
}

void calculateRevenue() {
    struct Tool tool;
    float revenue = 0;

    FILE *fp = fopen("tools.dat", "rb");

    if (fp == NULL) {
        printf("No Rentals Found.\n");
        return;
    }

    while (fread(&tool, sizeof(tool), 1, fp)) {
        revenue += tool.rentalDays * tool.rentPerDay;
    }

    fclose(fp);

    printf("Total Revenue: %.2f\n", revenue);
}
