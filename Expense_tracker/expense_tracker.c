#include<stdio.h>
#include<string.h>
struct Expense
{
    char name[50];
    float amount;
};
/*add expense*/
void addExpense(struct Expense expenses[], int *count){
    printf("\nEnter Expense Name:");
    getchar();
    fgets(expenses[*count].name,50, stdin);
    expenses[*count].name[strcspn(expenses[*count].name,"\n")]='\0';
    printf("Enter ammount:");
    scanf("%f",&expenses[*count].amount);
    (*count)++;
    printf("\nExpense added successfully!\n");
}
/*Display expense*/
void displayExpense(struct Expense expenses[], int count){
    int i;
    if (count==0){
        printf("\nNo Expenses recorded.\n");
        return;
    }
    printf("\n=====ALL EXPENSES=====\n");
    for (i=0;i<count; i++){
        printf("%d. %s - %.2f\n",i+1,expenses[i].name,expenses[i].amount);
    }
}
/*Calculate Expense*/
float calculateTotal(struct Expense expenses[], int count){
    float total=0.0;
    int i;
    for(i=0; i< count; i++)
    {
        total = total + expenses[i].amount; 
    }
    return total;
}
/*Delete expense*/
void deleteExpense(struct Expense expenses[],int*count){
    int choice;
    int i;
    if(*count == 0){
        printf("\nNo.Expenses to delete");
        return;
    }
    displayExpense(expenses, *count);
    printf("\nEnter Expense number to delete");
    scanf("%d",&choice);
    if (choice<1|| choice>*count){
        printf("\nInvalid Expense number!\n");
        return;
    }
    for(i=choice-1; i<*count-1; i++){
        expenses[i]=expenses[i+1];
    }
    (*count)--;
    printf("\nExpense deleted successfully");
} 
/*main function*/
int main(){
    struct Expense expenses[100];
    int count =0;
    int choice;
    do 
    {
        printf("\n=====EXPENSE TRAKER=====\n");
        printf("1.Add Expenses\n");
        printf("2.View Expenses\n");
        printf("3.Calculate Expenses\n");
        printf("4.Delete Expenses\n");
        printf("5.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch (choice){
            case 1:
            addExpense(expenses,&count);
            break;
            case 2:
            displayExpense(expenses, count);
            break;
            case 3:
            printf("\nTotal Expenses: %.2f\n", calculateTotal(expenses, count));
            break;
            case 4:
            deleteExpense(expenses,&count);
            break;
            case 5:
            printf("\nExiting Expense Tracker....\n");
            break;
            default:
            printf("\nInvalid Choice!!\n");
        }
    } while(choice!=5);
    return 0;
}