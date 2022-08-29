// Bank Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ACCNUM 20206000


typedef struct node
{
    char name[20];
    int age;
    char address[20];
    char citizenship[20];
    long long int phone;
    long int accnum;
    float balance;

    struct node * next;
} NODE;

NODE* newaccount(NODE * first)
{
    NODE *newnode,*temp;
    static long int z=0;
    newnode=(NODE*)malloc(sizeof(NODE));

    printf("\nEnter the details of customer: ");

    printf("\nNAME: ");
    scanf("%s",newnode->name);

    printf("AGE: ");
    scanf("%d",&newnode->age);

    printf("ADDRESS: ");
    scanf("%s",newnode->address);

    printf("CITIZENSHIP: ");
    scanf("%s",newnode->citizenship);

    printf("PHONE NUMBER: ");
    scanf("%lld",&newnode->phone);

    printf("AMOUNT: ");
    scanf("%f",&newnode->balance);

    newnode->next=NULL;

    if(first==NULL)
        first=newnode;

    else
    {
        temp=first;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
    printf("\nACOOUNT CREATED SUCCESSFULLY\nThank You for banking with us!!\n");
    if(first->next==NULL)
    {
        newnode->accnum=ACCNUM+z;
        printf("\nACCOUNT NUMBER is %ld\n",newnode->accnum);
    }
    else
    {
        z=z+1;
        newnode->accnum=ACCNUM;

        newnode->accnum=newnode->accnum+z;

        printf("\nACCOUNT NUMBER is %ld\n",newnode->accnum);

    }
    return (first);
}

void transfer(NODE *first)
{
    NODE *temp;
    long int toacc_no,fromacc_no;
    float trans;
    int flag=0,f=0,t=0;
    printf("\nACCOUNT NUMBER to transfer money from: ");
    scanf("%ld",&fromacc_no);
    printf("\nACCOUNT NUMBER to transfer money to:  ");
    scanf("%ld",&toacc_no);
    printf("\nEnter the money for the transaction: ");
    scanf("%f",&trans);
    temp=first;

    while (temp!=NULL)
    {
        if( temp->accnum==fromacc_no)
        {
            f=1;
            break;
        }
        temp=temp->next;
    }
    temp=first;
    while (temp!=NULL)
    {
        if( temp->accnum==toacc_no)
        {
            t=1;
            break;
        }
        temp=temp->next;
    }
    if(f==1&&t==1)
    {
        printf("\nTransaction Begins...\n");
        temp=first;
    }
    else
    {
        printf ("\nAccount doesn't exist\n");
        return;
    }
    while(temp!=NULL)
    {
        if(temp->accnum==fromacc_no)
        {
            if(temp->balance>=trans)
            {
                temp->balance=temp->balance-trans;
                break;
            }
            else
            {
                printf("\nLOW BALANCE!!\n");
                return;
            }
        }
        temp=temp->next;
    }
    temp=first;
    while(temp!=NULL)
    {
        if(temp->accnum==toacc_no)
        {
            temp->balance=temp->balance+trans;
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==1)
    {
        printf("\nTransaction successful\n");
    }
   // return(first);
}

void display_accnum (NODE *first)
{
    NODE *temp;
    long int accnum1;
    int flag=0;
    if(first==NULL)
    {
        printf("\nNO account found\n");
        return;

    }
    printf("\nEnter the account number to display the details: \n");
    scanf("%ld",&accnum1);
    temp=first;

    while(temp!=NULL)
    {
        if(temp->accnum==accnum1)
        {
            if(flag==0)
            {
                printf("\n THE DETAILS OF THE ACCOUNTS ARE\n");
                flag=1;
            }
            printf("\nName:%s",temp->name);
            printf("\nAge:%d",temp->age);
            printf("\nAddress:%s",temp->address);
            printf("\nCitizenship:%s",temp->citizenship);
            printf("\nPhone Number:%lld",temp->phone);
            printf("\nAmount:%f\n",temp->balance);

        }
        temp=temp->next;
    }
    if (flag==0)
    {
        printf("\nThe account not found in bank\n");

    }
}

void display_allacc(NODE *first)
{
    NODE *temp;
    int count=0;

    if (first==NULL)
    {
        printf("\nNo accounts  found\n");
        return;

    }
    temp=first;

    printf("\nTHE DETAILS OF THE ACCOUNTS ARE\n\n");

    while(temp!=NULL)
    {
        printf("Account Number:%ld\n",temp->accnum);
        printf("Name:%s\n",temp->name);
        printf("Age:%d\n",temp->age);
        printf("Address:%s\n",temp->address);
        printf("Citizenship:%s\n",temp->citizenship);
        printf("Balance:%f\n",temp->balance);
        printf("Phone:%lld\n",temp->phone);

        temp=temp->next;
        printf("\n");

        count++;

    }
    printf("\nTotal number of accounts in bank is %d\n",count);

}

void add_amount(NODE *first)
{
    long int accnum;
    float amount;
    printf("Enter the account number:");
    scanf("%ld",&accnum);

    while(first!=NULL&&accnum!=first->accnum)
    {
        first=first->next;
    }

    if(first==NULL)
    {
        printf("Account number doesn't exists\n");
        return ;
    }

    printf("Enter the amount to be added:");
    scanf("%f",&amount);

    first->balance+=amount;
    printf("\nYou have successfully added the %f rupees\nNEW BALANCE=%f\n",amount,first->balance);
}

void withdrawl(NODE *first)
{
    NODE *temp;
    long int fromacc_no;
    float amount;
    int flag=0;

    printf("\nACCOUNT NUMBER from which you want to withdraw money: ");
    scanf("%ld",&fromacc_no);

    printf("\nEnter the amount you want to withdraw: ");
    scanf("%f",&amount);
    temp=first;

    while(temp!=NULL)
    {
        if(temp->accnum==fromacc_no)
        {
            if(temp->balance>=amount)
            {
                temp->balance = temp->balance - amount;
                printf("\nYou have successfully withdraw %f rupees\nREMAINING BALANCE=%f\n",amount,temp->balance);
            }
            else
            {
                printf("\nINSUFFICIENT BALANCE \n\n!!");
            }

            flag = 1;
            break;
        }

        temp=temp->next;
    }

    if(flag==0)
    {
        printf("No account with %ld ID was found", fromacc_no);
    }
}

int main()
{
    NODE *first=0;
    int choice;


    while(1)
    {
        printf("\n1.Create\n2.Transfer the money\n3.Display based on Account number\n4.Display all Account\n5.Add amount to existing account\n6.withdrawl\n7.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:first=newaccount(first);
                   break;
            case 2:transfer(first);
                   break;
            case 3:display_accnum(first);
                   break;
            case 4:display_allacc(first);
                   break;
            case 5:add_amount(first);
                   break;
            case 6:withdrawl(first);
                   break;
            case 7:exit(0);
            default:printf("\n Invalid choice\n");
        }
    }
    return 0;
}
