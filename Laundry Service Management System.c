#include <stdio.h>

struct Laundry {
    int orderId;
    char customerName[50];
    char clothType[30];
    int quantity;
    float pricePerItem;
};

int main() {
    struct Laundry orders[100];
    int n, i;
    float totalRevenue = 0;

    printf("Enter number of laundry orders: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nOrder %d\n", i + 1);

        printf("Enter Order ID: ");
        scanf("%d", &orders[i].orderId);

        printf("Enter Customer Name: ");
        scanf("%s", orders[i].customerName);

        printf("Enter Cloth Type: ");
        scanf("%s", orders[i].clothType);

        printf("Enter Quantity: ");
        scanf("%d", &orders[i].quantity);

        printf("Enter Price Per Item: ");
        scanf("%f", &orders[i].pricePerItem);
    }

    printf("\nLaundry Order Details\n");

    for(i = 0; i < n; i++) {
        float bill = orders[i].quantity * orders[i].pricePerItem;

        printf("\nOrder ID: %d\n", orders[i].orderId);
        printf("Customer Name: %s\n", orders[i].customerName);
        printf("Cloth Type: %s\n", orders[i].clothType);
        printf("Quantity: %d\n", orders[i].quantity);
        printf("Price Per Item: %.2f\n", orders[i].pricePerItem);
        printf("Total Bill: %.2f\n", bill);

        totalRevenue += bill;
    }

    printf("\nTotal Revenue: %.2f\n", totalRevenue);

    return 0;
}
