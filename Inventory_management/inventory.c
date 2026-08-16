#include <stdio.h>
#include "inventory.h"

void addProduct(struct Product products[], int *count)
{
    if (*count >= MAX_PRODUCTS)
    {
        printf("\nInventory is full!\n");
        return;
    }

    printf("\n===== ADD PRODUCT =====\n");

    printf("Enter Product ID: ");
    scanf("%d", &products[*count].productId);

    printf("Enter Product Name: ");
    scanf(" %[^\n]", products[*count].productName);

    printf("Enter Category: ");
    scanf(" %[^\n]", products[*count].category);

    printf("Enter Price: ");
    scanf("%f", &products[*count].price);

    printf("Enter Quantity: ");
    scanf("%d", &products[*count].quantity);

    (*count)++;

    printf("\nProduct added successfully!\n");
}

void displayProducts(struct Product products[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo products available.\n");
        return;
    }

    printf("\n========== ALL PRODUCTS ==========\n");

    for (i = 0; i < count; i++)
    {
        printf("\nProduct %d\n", i + 1);
        printf("-----------------------------\n");
        printf("Product ID   : %d\n", products[i].productId);
        printf("Name         : %s\n", products[i].productName);
        printf("Category     : %s\n", products[i].category);
        printf("Price        : %.2f\n", products[i].price);
        printf("Quantity     : %d\n", products[i].quantity);
    }
}

void searchProduct(struct Product products[], int count)
{
    int productId;
    int i;

    printf("\n===== SEARCH PRODUCT =====\n");

    printf("Enter Product ID: ");
    scanf("%d", &productId);

    for (i = 0; i < count; i++)
    {
        if (products[i].productId == productId)
        {
            printf("\nProduct Found!\n");
            printf("-----------------------------\n");
            printf("Product ID   : %d\n", products[i].productId);
            printf("Name         : %s\n", products[i].productName);
            printf("Category     : %s\n", products[i].category);
            printf("Price        : %.2f\n", products[i].price);
            printf("Quantity     : %d\n", products[i].quantity);

            return;
        }
    }

    printf("\nProduct not found!\n");
}

void updateProduct(struct Product products[], int count)
{
    int productId;
    int i;

    printf("\n===== UPDATE PRODUCT =====\n");

    printf("Enter Product ID: ");
    scanf("%d", &productId);

    for (i = 0; i < count; i++)
    {
        if (products[i].productId == productId)
        {
            printf("Enter New Product Name: ");
            scanf(" %[^\n]", products[i].productName);

            printf("Enter New Category: ");
            scanf(" %[^\n]", products[i].category);

            printf("Enter New Price: ");
            scanf("%f", &products[i].price);

            printf("Enter New Quantity: ");
            scanf("%d", &products[i].quantity);

            printf("\nProduct updated successfully!\n");

            return;
        }
    }

    printf("\nProduct not found!\n");
}

void sellProduct(struct Product products[], int count)
{
    int productId;
    int quantity;
    int i;

    printf("\n===== SELL PRODUCT =====\n");

    printf("Enter Product ID: ");
    scanf("%d", &productId);

    for (i = 0; i < count; i++)
    {
        if (products[i].productId == productId)
        {
            printf("Enter Quantity to Sell: ");
            scanf("%d", &quantity);

            if (quantity <= 0)
            {
                printf("\nInvalid quantity!\n");
                return;
            }

            if (quantity > products[i].quantity)
            {
                printf("\nInsufficient stock!\n");
                return;
            }

            products[i].quantity -= quantity;

            printf("\nProduct sold successfully!\n");
            printf("Remaining Stock: %d\n", products[i].quantity);

            return;
        }
    }

    printf("\nProduct not found!\n");
}

void restockProduct(struct Product products[], int count)
{
    int productId;
    int quantity;
    int i;

    printf("\n===== RESTOCK PRODUCT =====\n");

    printf("Enter Product ID: ");
    scanf("%d", &productId);

    for (i = 0; i < count; i++)
    {
        if (products[i].productId == productId)
        {
            printf("Enter Quantity to Add: ");
            scanf("%d", &quantity);

            if (quantity <= 0)
            {
                printf("\nInvalid quantity!\n");
                return;
            }

            products[i].quantity += quantity;

            printf("\nProduct restocked successfully!\n");
            printf("Current Stock: %d\n", products[i].quantity);

            return;
        }
    }

    printf("\nProduct not found!\n");
}

void deleteProduct(struct Product products[], int *count)
{
    int productId;
    int i;
    int found = 0;

    printf("\n===== DELETE PRODUCT =====\n");

    printf("Enter Product ID: ");
    scanf("%d", &productId);

    for (i = 0; i < *count; i++)
    {
        if (products[i].productId == productId)
        {
            found = 1;

            for (int j = i; j < *count - 1; j++)
            {
                products[j] = products[j + 1];
            }

            (*count)--;

            printf("\nProduct deleted successfully!\n");

            break;
        }
    }

    if (found == 0)
    {
        printf("\nProduct not found!\n");
    }
}