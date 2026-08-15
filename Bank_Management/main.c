#include <stdio.h>
#include "bank.h"

int main()
{
    struct Account accounts[MAX_ACCOUNTS];
    int count = 0;
    int choice;

    do
    {
        printf("\n\n====================================\n");
        printf("         BANK MANAGEMENT SYSTEM\n");
        printf("====================================\n");

        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Search Account\n");
        printf("4. Deposit Money\n");
        printf("5. Withdraw Money\n");
        printf("6. Check Balance\n");
        printf("7. Delete Account\n");
        printf("8. Exit\n");

        printf("------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createAccount(accounts, &count);
                break;

            case 2:
                displayAccounts(accounts, count);
                break;

            case 3:
                searchAccount(accounts, count);
                break;

            case 4:
                depositMoney(accounts, count);
                break;

            case 5:
                withdrawMoney(accounts, count);
                break;

            case 6:
                checkBalance(accounts, count);
                break;

            case 7:
                deleteAccount(accounts, &count);
                break;

            case 8:
                printf("\nThank you for using Bank Management System!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 8);

    return 0;
}