#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    int id;
    char itemName[50];
    char category[30];
    char location[50];
    char status[10];
};

void addItem();
void viewItems();
void searchItem();
void updateStatus();
void deleteItem();

int main() {
    int choice;

    while (1) {
        printf("\nLost & Found Item Registry\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Search Item\n");
        printf("4. Update Status\n");
        printf("5. Delete Item\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewItems();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                updateStatus();
                break;
            case 5:
                deleteItem();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }
}

void addItem() {
    struct Item item;

    FILE *fp = fopen("items.dat", "ab");

    printf("Item ID: ");
    scanf("%d", &item.id);

    printf("Item Name: ");
    scanf(" %[^\n]", item.itemName);

    printf("Category: ");
    scanf(" %[^\n]", item.category);

    printf("Location: ");
    scanf(" %[^\n]", item.location);

    printf("Status (Lost/Found): ");
    scanf("%s", item.status);

    fwrite(&item, sizeof(item), 1, fp);

    fclose(fp);

    printf("Item Added Successfully.\n");
}

void viewItems() {
    struct Item item;

    FILE *fp = fopen("items.dat", "rb");

    if (fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("\nID\tItem\t\tCategory\tLocation\tStatus\n");

    while (fread(&item, sizeof(item), 1, fp)) {
        printf("%d\t%s\t\t%s\t\t%s\t\t%s\n",
               item.id,
               item.itemName,
               item.category,
               item.location,
               item.status);
    }

    fclose(fp);
}

void searchItem() {
    struct Item item;
    int id, found = 0;

    FILE *fp = fopen("items.dat", "rb");

    if (fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("Enter Item ID: ");
    scanf("%d", &id);

    while (fread(&item, sizeof(item), 1, fp)) {
        if (item.id == id) {
            printf("\nItem Found\n");
            printf("ID: %d\n", item.id);
            printf("Name: %s\n", item.itemName);
            printf("Category: %s\n", item.category);
            printf("Location: %s\n", item.location);
            printf("Status: %s\n", item.status);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Item Not Found.\n");
}

void updateStatus() {
    struct Item item;
    int id, found = 0;

    FILE *fp = fopen("items.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (fp == NULL) {
        printf("No Records Found.\n");
        fclose(temp);
        return;
    }

    printf("Enter Item ID: ");
    scanf("%d", &id);

    while (fread(&item, sizeof(item), 1, fp)) {

        if (item.id == id) {
            printf("Enter New Status (Lost/Found): ");
            scanf("%s", item.status);
            found = 1;
        }

        fwrite(&item, sizeof(item), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("items.dat");
    rename("temp.dat", "items.dat");

    if (found)
        printf("Status Updated Successfully.\n");
    else
        printf("Item Not Found.\n");
}

void deleteItem() {
    struct Item item;
    int id, found = 0;

    FILE *fp = fopen("items.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (fp == NULL) {
        printf("No Records Found.\n");
        fclose(temp);
        return;
    }

    printf("Enter Item ID: ");
    scanf("%d", &id);

    while (fread(&item, sizeof(item), 1, fp)) {

        if (item.id != id) {
            fwrite(&item, sizeof(item), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("items.dat");
    rename("temp.dat", "items.dat");

    if (found)
        printf("Item Deleted Successfully.\n");
    else
        printf("Item Not Found.\n");
}
