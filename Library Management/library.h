#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_BOOKS 100

struct Book
{
    int serialNo;
    char bookName[50];
    char author[50];
    char subject[50];
    char publisher[50];
    int edition;
    int issued;
};

void addBook(struct Book books[], int *count);
void displayBooks(struct Book books[], int count);
void searchBook(struct Book books[], int count);
void issueBook(struct Book books[], int count);
void returnBook(struct Book books[], int count);
void deleteBook(struct Book books[], int *count);

#endif