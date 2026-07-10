#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Recipe {
    int id;
    char name[50];
    char category[30];
    char ingredients[200];
    int cookingTime;
};

void addRecipe();
void viewRecipes();
void searchRecipe();
void updateRecipe();
void deleteRecipe();

int main() {
    int choice;

    while (1) {
        printf("\nDigital Recipe Organizer\n");
        printf("1. Add Recipe\n");
        printf("2. View Recipes\n");
        printf("3. Search Recipe\n");
        printf("4. Update Recipe\n");
        printf("5. Delete Recipe\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecipe();
                break;
            case 2:
                viewRecipes();
                break;
            case 3:
                searchRecipe();
                break;
            case 4:
                updateRecipe();
                break;
            case 5:
                deleteRecipe();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid Choice.\n");
        }
    }
}

void addRecipe() {
    struct Recipe recipe;

    FILE *fp = fopen("recipes.dat", "ab");

    if (fp == NULL) {
        printf("File Error.\n");
        return;
    }

    printf("Recipe ID: ");
    scanf("%d", &recipe.id);

    printf("Recipe Name: ");
    scanf(" %[^\n]", recipe.name);

    printf("Category: ");
    scanf(" %[^\n]", recipe.category);

    printf("Ingredients: ");
    scanf(" %[^\n]", recipe.ingredients);

    printf("Cooking Time (minutes): ");
    scanf("%d", &recipe.cookingTime);

    fwrite(&recipe, sizeof(recipe), 1, fp);

    fclose(fp);

    printf("Recipe Added Successfully.\n");
}

void viewRecipes() {
    struct Recipe recipe;

    FILE *fp = fopen("recipes.dat", "rb");

    if (fp == NULL) {
        printf("No Recipes Found.\n");
        return;
    }

    printf("\nID\tName\t\tCategory\tTime(min)\n");

    while (fread(&recipe, sizeof(recipe), 1, fp)) {
        printf("%d\t%s\t\t%s\t\t%d\n",
               recipe.id,
               recipe.name,
               recipe.category,
               recipe.cookingTime);

        printf("Ingredients: %s\n\n", recipe.ingredients);
    }

    fclose(fp);
}

void searchRecipe() {
    struct Recipe recipe;
    char name[50];
    int found = 0;

    FILE *fp = fopen("recipes.dat", "rb");

    if (fp == NULL) {
        printf("No Recipes Found.\n");
        return;
    }

    printf("Enter Recipe Name: ");
    scanf(" %[^\n]", name);

    while (fread(&recipe, sizeof(recipe), 1, fp)) {

        if (strcmp(recipe.name, name) == 0) {

            printf("\nRecipe Found\n");
            printf("ID: %d\n", recipe.id);
            printf("Name: %s\n", recipe.name);
            printf("Category: %s\n", recipe.category);
            printf("Ingredients: %s\n", recipe.ingredients);
            printf("Cooking Time: %d minutes\n", recipe.cookingTime);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Recipe Not Found.\n");
}

void updateRecipe() {
    struct Recipe recipe;
    int id, found = 0;

    FILE *fp = fopen("recipes.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (fp == NULL) {
        printf("No Recipes Found.\n");
        fclose(temp);
        return;
    }

    printf("Enter Recipe ID: ");
    scanf("%d", &id);

    while (fread(&recipe, sizeof(recipe), 1, fp)) {

        if (recipe.id == id) {

            printf("New Recipe Name: ");
            scanf(" %[^\n]", recipe.name);

            printf("New Category: ");
            scanf(" %[^\n]", recipe.category);

            printf("New Ingredients: ");
            scanf(" %[^\n]", recipe.ingredients);

            printf("New Cooking Time: ");
            scanf("%d", &recipe.cookingTime);

            found = 1;
        }

        fwrite(&recipe, sizeof(recipe), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("recipes.dat");
    rename("temp.dat", "recipes.dat");

    if (found)
        printf("Recipe Updated Successfully.\n");
    else
        printf("Recipe Not Found.\n");
}

void deleteRecipe() {
    struct Recipe recipe;
    int id, found = 0;

    FILE *fp = fopen("recipes.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (fp == NULL) {
        printf("No Recipes Found.\n");
        fclose(temp);
        return;
    }

    printf("Enter Recipe ID: ");
    scanf("%d", &id);

    while (fread(&recipe, sizeof(recipe), 1, fp)) {

        if (recipe.id != id) {
            fwrite(&recipe, sizeof(recipe), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("recipes.dat");
    rename("temp.dat", "recipes.dat");

    if (found)
        printf("Recipe Deleted Successfully.\n");
    else
        printf("Recipe Not Found.\n");
}
