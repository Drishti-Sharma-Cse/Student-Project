#ifndef INVENTORY_H
#define INVENTORY_H

#define MAX_PRODUCTS 100

struct Product
{
    int productId;
    char productName[50];
    char category[30];
    float price;
    int quantity;
};

void addProduct(struct Product products[], int *count);
void displayProducts(struct Product products[], int count);
void searchProduct(struct Product products[], int count);
void updateProduct(struct Product products[], int count);
void sellProduct(struct Product products[], int count);
void restockProduct(struct Product products[], int count);
void deleteProduct(struct Product products[], int *count);

#endif