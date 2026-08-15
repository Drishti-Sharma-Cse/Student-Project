#ifndef BANK_H
#define BANK_H

#define MAX_ACCOUNTS 100

struct Account
{
    int accountNumber;
    char name[50];
    char accountType[20];
    float balance;
};

void createAccount(struct Account accounts[], int *count);
void displayAccounts(struct Account accounts[], int count);
void searchAccount(struct Account accounts[], int count);
void depositMoney(struct Account accounts[], int count);
void withdrawMoney(struct Account accounts[], int count);
void checkBalance(struct Account accounts[], int count);
void deleteAccount(struct Account accounts[], int *count);

#endif