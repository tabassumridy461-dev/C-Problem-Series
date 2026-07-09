#include <stdio.h>

int main() {
    int customerId;
    char customerName[50];
    float units, bill, serviceCharge, vat, totalBill;

    printf("Electricity Bill Generator\n");

    printf("Enter Customer ID: ");
    scanf("%d", &customerId);

    printf("Enter Customer Name: ");
    scanf(" %[^\n]", customerName);

    printf("Enter Units Consumed: ");
    scanf("%f", &units);

    if (units <= 100)
        bill = units * 5.0;
    else if (units <= 300)
        bill = (100 * 5.0) + ((units - 100) * 7.0);
    else
        bill = (100 * 5.0) + (200 * 7.0) + ((units - 300) * 10.0);

    serviceCharge = 100;
    vat = bill * 0.05;
    totalBill = bill + serviceCharge + vat;

    printf("\nCustomer ID: %d\n", customerId);
    printf("Customer Name: %s\n", customerName);
    printf("Units Consumed: %.2f\n", units);
    printf("Energy Charge: %.2f Taka\n", bill);
    printf("Service Charge: %.2f Taka\n", serviceCharge);
    printf("VAT (5%%): %.2f Taka\n", vat);
    printf("Total Bill: %.2f Taka\n", totalBill);

    return 0;
}
