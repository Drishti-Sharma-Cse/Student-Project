#include <stdio.h>
#include "inventory.h"

int main()
{
    struct Product products[MAX_PRODUCTS];

    int count = 0;
    int choice;

    do
    {
        printf("\n\n====================================\n");
        printf("       INVENTORY MANAGEMENT SYSTEM\n");
        printf("====================================\n");

        printf("1. Add Product\n");
        printf("2. Display All Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Sell Product\n");
        printf("6. Restock Product\n");
        printf("7. Delete Product\n");
        printf("8. Exit\n");

        printf("------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addProduct(products, &count);
                break;

            case 2:
                displayProducts(products, count);
                break;

            case 3:
                searchProduct(products, count);
                break;

            case 4:
                updateProduct(products, count);
                break;

            case 5:
                sellProduct(products, count);
                break;

            case 6:
                restockProduct(products, count);
                break;

            case 7:
                deleteProduct(products, &count);
                break;

            case 8:
                printf("\nThank you for using Inventory Management System!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 8);

    return 0;
}