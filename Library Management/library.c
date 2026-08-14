#include <stdio.h>
#include <string.h>
#include "library.h"

void addBook(struct Book books[], int *count)
{
    if (*count >= MAX_BOOKS)
    {
        printf("\nLibrary is full!\n");
        return;
    }

    printf("\n===== ADD BOOK =====\n");

    printf("Enter Serial Number: ");
    scanf("%d", &books[*count].serialNo);

    printf("Enter Book Name: ");
    scanf(" %[^\n]", books[*count].bookName);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", books[*count].author);

    printf("Enter Subject: ");
    scanf(" %[^\n]", books[*count].subject);

    printf("Enter Publisher: ");
    scanf(" %[^\n]", books[*count].publisher);

    printf("Enter Edition: ");
    scanf("%d", &books[*count].edition);

    books[*count].issued = 0;

    (*count)++;

    printf("\nBook added successfully!\n");
}

void displayBooks(struct Book books[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo books available in the library.\n");
        return;
    }

    printf("\n===== ALL BOOKS =====\n");

    for (i = 0; i < count; i++)
    {
        printf("\nBook %d\n", i + 1);
        printf("-----------------------------\n");
        printf("Serial Number : %d\n", books[i].serialNo);
        printf("Book Name     : %s\n", books[i].bookName);
        printf("Author        : %s\n", books[i].author);
        printf("Subject       : %s\n", books[i].subject);
        printf("Publisher     : %s\n", books[i].publisher);
        printf("Edition       : %d\n", books[i].edition);

        if (books[i].issued == 0)
            printf("Status        : Available\n");
        else
            printf("Status        : Issued\n");
    }
}

void searchBook(struct Book books[], int count)
{
    int serialNo;
    int i;
    int found = 0;

    printf("\n===== SEARCH BOOK =====\n");

    printf("Enter Serial Number: ");
    scanf("%d", &serialNo);

    for (i = 0; i < count; i++)
    {
        if (books[i].serialNo == serialNo)
        {
            printf("\nBook Found!\n");
            printf("-----------------------------\n");
            printf("Serial Number : %d\n", books[i].serialNo);
            printf("Book Name     : %s\n", books[i].bookName);
            printf("Author        : %s\n", books[i].author);
            printf("Subject       : %s\n", books[i].subject);
            printf("Publisher     : %s\n", books[i].publisher);
            printf("Edition       : %d\n", books[i].edition);

            if (books[i].issued == 0)
                printf("Status        : Available\n");
            else
                printf("Status        : Issued\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nBook not found!\n");
    }
}

void issueBook(struct Book books[], int count)
{
    int serialNo;
    int i;

    printf("\n===== ISSUE BOOK =====\n");

    printf("Enter Serial Number: ");
    scanf("%d", &serialNo);

    for (i = 0; i < count; i++)
    {
        if (books[i].serialNo == serialNo)
        {
            if (books[i].issued == 1)
            {
                printf("\nBook is already issued!\n");
            }
            else
            {
                books[i].issued = 1;
                printf("\nBook issued successfully!\n");
            }

            return;
        }
    }

    printf("\nBook not found!\n");
}

void returnBook(struct Book books[], int count)
{
    int serialNo;
    int i;

    printf("\n===== RETURN BOOK =====\n");

    printf("Enter Serial Number: ");
    scanf("%d", &serialNo);

    for (i = 0; i < count; i++)
    {
        if (books[i].serialNo == serialNo)
        {
            if (books[i].issued == 0)
            {
                printf("\nBook is already available!\n");
            }
            else
            {
                books[i].issued = 0;
                printf("\nBook returned successfully!\n");
            }

            return;
        }
    }

    printf("\nBook not found!\n");
}

void deleteBook(struct Book books[], int *count)
{
    int serialNo;
    int i;
    int found = 0;

    printf("\n===== DELETE BOOK =====\n");

    printf("Enter Serial Number: ");
    scanf("%d", &serialNo);

    for (i = 0; i < *count; i++)
    {
        if (books[i].serialNo == serialNo)
        {
            found = 1;

            for (int j = i; j < *count - 1; j++)
            {
                books[j] = books[j + 1];
            }

            (*count)--;

            printf("\nBook deleted successfully!\n");
            break;
        }
    }

    if (found == 0)
    {
        printf("\nBook not found!\n");
    }
}