#include <stdio.h>

struct Pet {
    int petId;
    char petName[50];
    char animalType[30];
    int age;
    char adopterName[50];
    float adoptionFee;
};

int main() {
    struct Pet pets[100];
    int n, i;
    float totalFees = 0;

    printf("Enter number of adoption records: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nAdoption Record %d\n", i + 1);

        printf("Enter Pet ID: ");
        scanf("%d", &pets[i].petId);

        printf("Enter Pet Name: ");
        scanf("%s", pets[i].petName);

        printf("Enter Animal Type: ");
        scanf("%s", pets[i].animalType);

        printf("Enter Pet Age: ");
        scanf("%d", &pets[i].age);

        printf("Enter Adopter Name: ");
        scanf("%s", pets[i].adopterName);

        printf("Enter Adoption Fee: ");
        scanf("%f", &pets[i].adoptionFee);
    }

    printf("\nPet Adoption Details\n");

    for(i = 0; i < n; i++) {
        printf("\nPet ID: %d\n", pets[i].petId);
        printf("Pet Name: %s\n", pets[i].petName);
        printf("Animal Type: %s\n", pets[i].animalType);
        printf("Pet Age: %d\n", pets[i].age);
        printf("Adopter Name: %s\n", pets[i].adopterName);
        printf("Adoption Fee: %.2f\n", pets[i].adoptionFee);

        totalFees += pets[i].adoptionFee;
    }

    printf("\nTotal Adoption Fees Collected: %.2f\n", totalFees);

    return 0;
}
