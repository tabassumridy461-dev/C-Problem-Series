#include <stdio.h>
#include <string.h>

struct Laundry {
    int orderId;
    char customer[50];
    char phone[20];
    int clothes;
    char pickupDate[20];
    char deliveryDate[20];
    char status[20];
    float bill;
};

int main() {

    struct Laundry order[100];

    int total = 0;
    int choice;
    int id;
    float totalIncome = 0;

    while (1) {

        printf("\nSmart Laundry Pickup Scheduler\n");
        printf("1. Add Order\n");
        printf("2. View Orders\n");
        printf("3. Search Order\n");
        printf("4. Update Status\n");
        printf("5. Pending Deliveries\n");
        printf("6. Total Income\n");
        printf("7. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {

            printf("Order ID: ");
            scanf("%d", &order[total].orderId);

            printf("Customer Name: ");
            scanf(" %[^\n]", order[total].customer);

            printf("Phone: ");
            scanf("%s", order[total].phone);

            printf("Number of Clothes: ");
            scanf("%d", &order[total].clothes);

            printf("Pickup Date: ");
            scanf("%s", order[total].pickupDate);

            printf("Delivery Date: ");
            scanf("%s", order[total].deliveryDate);

            order[total].bill = order[total].clothes * 40;

            strcpy(order[total].status, "Pending");

            totalIncome += order[total].bill;

            total++;

            printf("Order Added Successfully.\n");
        }

        else if (choice == 2) {

            if (total == 0) {
                printf("No Orders Available.\n");
            }
            else {

                for (int i = 0; i < total; i++) {

                    printf("\nOrder %d\n", i + 1);
                    printf("Order ID: %d\n", order[i].orderId);
                    printf("Customer: %s\n", order[i].customer);
                    printf("Phone: %s\n", order[i].phone);
                    printf("Clothes: %d\n", order[i].clothes);
                    printf("Pickup: %s\n", order[i].pickupDate);
                    printf("Delivery: %s\n", order[i].deliveryDate);
                    printf("Status: %s\n", order[i].status);
                    printf("Bill: %.2f\n", order[i].bill);
                }
            }
        }

        else if (choice == 3) {

            int found = 0;

            printf("Enter Order ID: ");
            scanf("%d", &id);

            for (int i = 0; i < total; i++) {

                if (order[i].orderId == id) {

                    printf("Customer: %s\n", order[i].customer);
                    printf("Phone: %s\n", order[i].phone);
                    printf("Clothes: %d\n", order[i].clothes);
                    printf("Pickup Date: %s\n", order[i].pickupDate);
                    printf("Delivery Date: %s\n", order[i].deliveryDate);
                    printf("Status: %s\n", order[i].status);
                    printf("Bill: %.2f\n", order[i].bill);

                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Order Not Found.\n");
        }

        else if (choice == 4) {

            int found = 0;
            char newStatus[20];

            printf("Enter Order ID: ");
            scanf("%d", &id);

            for (int i = 0; i < total; i++) {

                if (order[i].orderId == id) {

                    printf("Enter New Status: ");
                    scanf("%s", newStatus);

                    strcpy(order[i].status, newStatus);

                    printf("Status Updated.\n");

                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Order Not Found.\n");
        }

        else if (choice == 5) {

            int found = 0;

            printf("\nPending Deliveries\n");

            for (int i = 0; i < total; i++) {

                if (strcmp(order[i].status, "Pending") == 0) {

                    printf("Order ID: %d\n", order[i].orderId);
                    printf("Customer: %s\n", order[i].customer);
                    printf("Delivery Date: %s\n\n", order[i].deliveryDate);

                    found = 1;
                }
            }

            if (!found)
                printf("No Pending Deliveries.\n");
        }

        else if (choice == 6) {

            printf("Total Orders: %d\n", total);
            printf("Total Income: %.2f\n", totalIncome);
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
