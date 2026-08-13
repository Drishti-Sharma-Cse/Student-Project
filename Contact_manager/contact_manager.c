#include <stdio.h>
#include <string.h>

struct Contact
{
    char name[50];
    char phone[20];
    char email[50];
};

void addContact(struct Contact contacts[], int *count)
{
    printf("\nEnter Name: ");
    getchar();
    fgets(contacts[*count].name, 50, stdin);
    contacts[*count].name[strcspn(contacts[*count].name, "\n")] = '\0';

    printf("Enter Phone: ");
    fgets(contacts[*count].phone, 20, stdin);
    contacts[*count].phone[strcspn(contacts[*count].phone, "\n")] = '\0';

    printf("Enter Email: ");
    fgets(contacts[*count].email, 50, stdin);
    contacts[*count].email[strcspn(contacts[*count].email, "\n")] = '\0';

    (*count)++;

    printf("\nContact added successfully!\n");
}

void viewContacts(struct Contact contacts[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo contacts available.\n");
        return;
    }

    printf("\n===== CONTACTS =====\n");

    for (i = 0; i < count; i++)
    {
        printf("\nContact %d\n", i + 1);
        printf("Name  : %s\n", contacts[i].name);
        printf("Phone : %s\n", contacts[i].phone);
        printf("Email : %s\n", contacts[i].email);
    }
}

void manageContact(struct Contact contacts[], int count)
{
    int index;

    if (count == 0)
    {
        printf("\nNo contacts available.\n");
        return;
    }

    viewContacts(contacts, count);

    printf("\nEnter contact number to manage: ");
    scanf("%d", &index);

    if (index < 1 || index > count)
    {
        printf("\nInvalid contact number.\n");
        return;
    }

    index--;

    printf("\nEnter New Name: ");
    getchar();
    fgets(contacts[index].name, 50, stdin);
    contacts[index].name[strcspn(contacts[index].name, "\n")] = '\0';

    printf("Enter New Phone: ");
    fgets(contacts[index].phone, 20, stdin);
    contacts[index].phone[strcspn(contacts[index].phone, "\n")] = '\0';

    printf("Enter New Email: ");
    fgets(contacts[index].email, 50, stdin);
    contacts[index].email[strcspn(contacts[index].email, "\n")] = '\0';

    printf("\nContact updated successfully!\n");
}

void searchContact(struct Contact contacts[], int count)
{
    char name[50];
    int i;
    int found = 0;

    printf("\nEnter name to search: ");
    getchar();
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';

    for (i = 0; i < count; i++)
    {
        if (strcmp(contacts[i].name, name) == 0)
        {
            printf("\nContact Found!\n");
            printf("Name  : %s\n", contacts[i].name);
            printf("Phone : %s\n", contacts[i].phone);
            printf("Email : %s\n", contacts[i].email);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nContact not found.\n");
    }
}

void deleteContact(struct Contact contacts[], int *count)
{
    int index;
    int i;

    if (*count == 0)
    {
        printf("\nNo contacts available.\n");
        return;
    }

    viewContacts(contacts, *count);

    printf("\nEnter contact number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > *count)
    {
        printf("\nInvalid contact number.\n");
        return;
    }

    index--;

    for (i = index; i < *count - 1; i++)
    {
        contacts[i] = contacts[i + 1];
    }

    (*count)--;

    printf("\nContact deleted successfully!\n");
}

int main()
{
    struct Contact contacts[100];
    int count = 0;
    int choice;

    do
    {
        printf("\n===== CONTACT MANAGER =====\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Manage Contact\n");
        printf("4. Search Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addContact(contacts, &count);
                break;

            case 2:
                viewContacts(contacts, count);
                break;

            case 3:
                manageContact(contacts, count);
                break;

            case 4:
                searchContact(contacts, count);
                break;

            case 5:
                deleteContact(contacts, &count);
                break;

            case 6:
                printf("\nExiting Contact Manager...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}