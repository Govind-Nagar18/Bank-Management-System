#include <stdio.h>
#include <string.h>
#define Max_size 2 // You can increase the value of Customers.Howmuch you want to add Customers
#define string_size 100

struct customer
{
    int account_number;
    char name[string_size];
    int balance;
};

void getdetail(struct customer cust[])
{
loop:
    for (int i = 0; i < Max_size; i++)
    {
        printf("Enter the name of %d Customer: ", i + 1);
        fgets(cust[i].name, string_size, stdin);
        cust[i].name[strcspn(cust[i].name, "\n")] = '\0';

        if (i == 0)
        {
            printf("Enter the Accout Number of %d Customer: ", i + 1);
            scanf("%d", &cust[i].account_number);
        }
        else
        {
            printf("Enter the Accout Number of %d Customer: ", i + 1);
            scanf("%d", &cust[i].account_number);
            for (int j = 0; j < i; j++)
            {
                if (cust[i].account_number == cust[j].account_number)
                {
                    printf("An account with number already exist try again\n");
                    printf("===================================\n");
                    i--;
                    fgetc(stdin);
                    goto loop;
                }
            }
        }

        printf("Enter the Balance of %d Customer: ", i + 1);
        scanf("%d", &cust[i].balance);

        fgetc(stdin);
        printf("===================================\n");
    }
}

void withdrawal(struct customer cust[])
{
    int acn, amount, flag = 0;
    printf("Enter Your Account Number: ");
    scanf("%d", &acn);

    for (int i = 0; i < Max_size; i++)
    {
        if (acn == cust[i].account_number)
        {
            flag = 1;
            printf("Enter the amount you want to withdraw: ");
            scanf("%d", &amount);

            if (amount <= cust[i].balance)
            {
                cust[i].balance -= amount;
                printf("You have Successfully Withdrawn %drs\nYour current Balance is: %drs\n", amount, cust[i].balance);
                printf("=================================\n");
                break;
            }
            else
            {
                printf("Insufficient Balance\n");
                printf("=================================\n");
                break;
            }
        }
    }

    if (!flag)
    {
        printf("No Account with this number found\n");
        printf("=================================\n");
    }
}

void deposite(struct customer cust[])
{
    int acn, amount, flag = 0;
    printf("Enter Your Account Number: ");
    scanf("%d", &acn);

    for (int i = 0; i < Max_size; i++)
    {
        if (acn == cust[i].account_number)
        {
            flag = 1;
            printf("Enter the amount you want to Deposite: ");
            scanf("%d", &amount);
            cust[i].balance += amount;
            printf("You have Successfully Deposited %drs\nYour current Balance is: %drs\n", amount, cust[i].balance);
            printf("=================================\n");
            break;
        }
    }
    if (!flag)
    {
        printf("No Account with this number found\n");
        printf("=================================\n");
    }
}

void below_100(struct customer cust[])
{
    int flag = 0;
    for (int i = 0; i < Max_size; i++)
    {
        if (cust[i].balance < 100)
        {
            flag = 1;
            printf("The Name of %d Customer is: %s\n", i + 1, cust[i].name);
            printf("The Account number of %d Customer is: %d\n", i + 1, cust[i].account_number);
            printf("The Balance of %d Customer is: %d\n", i + 1, cust[i].balance);
            printf("===================================\n");
        }
    }

    if (!flag)
    {
        printf("No customer with balance below 100 Found\n");
        printf("=================================\n");
    }
}

int main()
{
    int choice;
    printf("Add two Customer Details then you can perform All the other Features \n");
    struct customer cust[Max_size];
    getdetail(cust);
    printf("Choose From Below Options\n");
    printf("0 For withdrawal\n");
    printf("1 For depsite\n");
    printf("2 For printing the data of customers with balance below 100\n");
    printf("3 For Exiting the code\n");
    printf("=======================================\n");

    while (1)
    {
        printf("Enter You Choice:  ");
        scanf("%d", &choice);
        printf("=======================================\n");

        if (choice == 0)
        {
            withdrawal(cust);
        }

        else if (choice == 1)
        {
            deposite(cust);
        }

        else if (choice == 2)
        {
            below_100(cust);
        }

        else if (choice == 3)
        {
            printf("Code Exited");
            break;
        }

        else
        {
            printf("Invalid Choice\nPlease try Again\n");
            printf("=======================================\n");
        }
    }

    return 0;
}
