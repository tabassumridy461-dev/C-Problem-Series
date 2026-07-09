#include <stdio.h>

struct Order {
    int orderId;
    char customerName[50];
    char foodName[50];
    int quantity;
    float price;
};

int main() {
    struct Order orders[100];
    int n, i;
    float grandTotal = 0;

    printf("Enter number of orders: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nOrder %d\n", i + 1);

        printf("Enter Order ID: ");
        scanf("%d", &orders[i].orderId);

        printf("Enter Customer Name: ");
        scanf("%s", orders[i].customerName);

        printf("Enter Food Name: ");
        scanf("%s", orders[i].foodName);

        printf("Enter Quantity: ");
        scanf("%d", &orders[i].quantity);

        printf("Enter Price Per Item: ");
        scanf("%f", &orders[i].price);
    }

    printf("\nOrder Details\n");

    for(i = 0; i < n; i++) {
        float total = orders[i].quantity * orders[i].price;

        printf("\nOrder ID: %d\n", orders[i].orderId);
        printf("Customer Name: %s\n", orders[i].customerName);
        printf("Food Name: %s\n", orders[i].foodName);
        printf("Quantity: %d\n", orders[i].quantity);
        printf("Price Per Item: %.2f\n", orders[i].price);
        printf("Order Total: %.2f\n", total);

        grandTotal += total;
    }

    printf("\nTotal Sales: %.2f\n", grandTotal);

    return 0;
}
