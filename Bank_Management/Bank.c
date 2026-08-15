#include <stdio.h>
#include "bank.h"

void createAccount(struct Account accounts[], int *count)
{
    if (*count >= MAX_ACCOUNTS)
    {
        printf("\nBank account limit reached!\n");
        return;
    }

    printf("\n===== CREATE ACCOUNT =====\n");

    printf("Enter Account Number: ");
    scanf("%d", &accounts[*count].accountNumber);

    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", accounts[*count].name);

    printf("Enter Account Type: ");
    scanf(" %[^\n]", accounts[*count].accountType);

    printf("Enter Initial Balance: ");
    scanf("%f", &accounts[*count].balance);

    (*count)++;

    printf("\nAccount created successfully!\n");
}

void displayAccounts(struct Account accounts[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo accounts available.\n");
        return;
    }

    printf("\n===== ALL ACCOUNTS =====\n");

    for (i = 0; i < count; i++)
    {
        printf("\nAccount %d\n", i + 1);
        printf("-----------------------------\n");
        printf("Account Number : %d\n", accounts[i].accountNumber);
        printf("Name          : %s\n", accounts[i].name);
        printf("Account Type  : %s\n", accounts[i].accountType);
        printf("Balance       : %.2f\n", accounts[i].balance);
    }
}

void searchAccount(struct Account accounts[], int count)
{
    int accountNumber;
    int i;
    int found = 0;

    printf("\n===== SEARCH ACCOUNT =====\n");

    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);

    for (i = 0; i < count; i++)
    {
        if (accounts[i].accountNumber == accountNumber)
        {
            printf("\nAccount Found!\n");
            printf("-----------------------------\n");
            printf("Account Number : %d\n", accounts[i].accountNumber);
            printf("Name          : %s\n", accounts[i].name);
            printf("Account Type  : %s\n", accounts[i].accountType);
            printf("Balance       : %.2f\n", accounts[i].balance);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nAccount not found!\n");
    }
}

void depositMoney(struct Account accounts[], int count)
{
    int accountNumber;
    float amount;
    int i;

    printf("\n===== DEPOSIT MONEY =====\n");

    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);

    for (i = 0; i < count; i++)
    {
        if (accounts[i].accountNumber == accountNumber)
        {
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);

            if (amount <= 0)
            {
                printf("\nInvalid amount!\n");
                return;
            }

            accounts[i].balance += amount;

            printf("\nAmount deposited successfully!\n");
            printf("New Balance: %.2f\n", accounts[i].balance);

            return;
        }
    }

    printf("\nAccount not found!\n");
}

void withdrawMoney(struct Account accounts[], int count)
{
    int accountNumber;
    float amount;
    int i;

    printf("\n===== WITHDRAW MONEY =====\n");

    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);

    for (i = 0; i < count; i++)
    {
        if (accounts[i].accountNumber == accountNumber)
        {
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);

            if (amount <= 0)
            {
                printf("\nInvalid amount!\n");
                return;
            }

            if (amount > accounts[i].balance)
            {
                printf("\nInsufficient balance!\n");
                return;
            }

            accounts[i].balance -= amount;

            printf("\nAmount withdrawn successfully!\n");
            printf("Remaining Balance: %.2f\n", accounts[i].balance);

            return;
        }
    }

    printf("\nAccount not found!\n");
}

void checkBalance(struct Account accounts[], int count)
{
    int accountNumber;
    int i;

    printf("\n===== CHECK BALANCE =====\n");

    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);

    for (i = 0; i < count; i++)
    {
        if (accounts[i].accountNumber == accountNumber)
        {
            printf("\nAccount Holder : %s\n", accounts[i].name);
            printf("Account Number : %d\n", accounts[i].accountNumber);
            printf("Balance        : %.2f\n", accounts[i].balance);

            return;
        }
    }

    printf("\nAccount not found!\n");
}

void deleteAccount(struct Account accounts[], int *count)
{
    int accountNumber;
    int i;
    int found = 0;

    printf("\n===== DELETE ACCOUNT =====\n");

    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);

    for (i = 0; i < *count; i++)
    {
        if (accounts[i].accountNumber == accountNumber)
        {
            found = 1;

            for (int j = i; j < *count - 1; j++)
            {
                accounts[j] = accounts[j + 1];
            }

            (*count)--;

            printf("\nAccount deleted successfully!\n");
            break;
        }
    }

    if (found == 0)
    {
        printf("\nAccount not found!\n");
    }
}