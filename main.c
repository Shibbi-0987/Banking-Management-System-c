#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 100

void addAccount(int accountNumbers[], char names[][50], double balances[], int *numAccounts, int pinNumber[]);
void displayAccounts(int accountNumbers[], char names[][50], double balances[], int numAccounts, int pinNumber[]);
void depositBalance(int accountNumbers[], double balances[], int numAccounts);
void withdrawalBalance(int accountNumbers[], double balances[], int numAccounts);

int main()
{
    int Accountnum[MAX_ACCOUNTS];
    char names[MAX_ACCOUNTS][50];
    double balances[MAX_ACCOUNTS];
    int numAccounts = 0;
    int choice;
    int pinNumber[MAX_ACCOUNTS];

    do
    {
        printf("\n\n\033[1;3;40m---------------  Select the services provided by banking management according to your requirements  ---------------\033[0m\n ");
        printf("\n\033[40m1. Add account       \n2. Display accounts  \n3. deposit balance   \n4. withdrawal balance\n5. Exit              \033[0m \n\n");
        printf("\033[38mEnter your choice: \033[0m");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addAccount(Accountnum, names, balances, &numAccounts, pinNumber);
            break;
        case 2:
            displayAccounts(Accountnum, names, balances, numAccounts, pinNumber);
            break;
        case 3:
            depositBalance(Accountnum, balances, numAccounts);
            break;
        case 4:
            withdrawalBalance(Accountnum, balances, numAccounts);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// add a new account
void addAccount(int accountNumbers[], char names[][50], double balances[], int *numAccounts, int pinNumber[])
{
    if (*numAccounts < MAX_ACCOUNTS)
    {

        printf("Enter account number: ");
        scanf("%d", &accountNumbers[*numAccounts]);

        printf("Enter name: ");
        scanf("%s", names[*numAccounts]);

        printf("Enter initial balance: ");
        scanf("%lf", &balances[*numAccounts]);

        printf("Enter the pin: ");
        scanf("%d", &pinNumber[*numAccounts]);

        (*numAccounts)++;
        printf("\n Your Account has been created successfully");
    }
    else
    {
        printf("Maximum number of accounts reached.\n");
    }
}

//  To display account details
void displayAccounts(int accountNumbers[], char names[][50], double balances[], int numAccounts, int pinNumber[])
{
    int serial;
    int pin;

    for (int i = 0; i < numAccounts; i++)
    {
        for (int j = 0; j < numAccounts; j++)
        {
            printf("%d. Name of account holder: %s\n", j + 1, names[j]);
        }

        printf("\nEnter the serial no of account holder if you want to see the details:");
        scanf("%d", &serial);

        printf("Enter the pin: ");
        scanf("%d", &pin);
        if (pin == pinNumber[serial-1])
        {
            printf("\nBalance: %.2lf\n", balances[serial-1]);
            printf("Account_NO: %d\n", accountNumbers[serial-1]);
        }

        else
        {
            printf("Invalid pin");
        }
    }
}

void depositBalance(int accountNumbers[], double balances[], int numAccounts)
{
    int accountNumber;
    double newBalance;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < numAccounts; i++)
    {
        if (accountNumbers[i] == accountNumber)
        {
            printf("Enter new balance: ");
            scanf("%lf", &newBalance);

            balances[i] += newBalance;
            printf("Deposit successful.\n");
            break;
        }
    }
}

void withdrawalBalance(int accountNumbers[], double balances[], int numAccounts)
{
    int accountNumber;
    double withdrawalAmount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < numAccounts; i++)
    {
        if (accountNumbers[i] == accountNumber)
        {
            printf("Enter the amount to withdrawal: ");
            scanf("%lf", &withdrawalAmount);

            if (withdrawalAmount > balances[i])
            {
                printf("Insufficient balance.\n");
            }
            else
            {
                balances[i] -= withdrawalAmount;
                printf("Withdrawal successful.\n");
            }
            break;
        }
    }
}
