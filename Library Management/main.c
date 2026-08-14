#include <stdio.h>
#include "library.h"

int main()
{
    struct Book books[MAX_BOOKS];
    int count = 0;
    int choice;

    do
    {
        printf("\n\n====================================\n");
        printf("      LIBRARY MANAGEMENT SYSTEM\n");
        printf("====================================\n");

        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Delete Book\n");
        printf("7. Exit\n");

        printf("------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addBook(books, &count);
                break;

            case 2:
                displayBooks(books, count);
                break;

            case 3:
                searchBook(books, count);
                break;

            case 4:
                issueBook(books, count);
                break;

            case 5:
                returnBook(books, count);
                break;

            case 6:
                deleteBook(books, &count);
                break;

            case 7:
                printf("\nThank you for using Library Management System!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}