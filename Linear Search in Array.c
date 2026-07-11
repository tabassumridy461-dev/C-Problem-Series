#include <stdio.h>

int main() {

    int array[100], size, search, i, found = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);

    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &search);

    for (i = 0; i < size; i++) {

        if (array[i] == search) {
            found = 1;
            printf("%d found at index %d.\n", search, i);
            break;
        }

    }

    if (found == 0) {
        printf("%d not found in the array.\n", search);
    }

    return 0;
}
