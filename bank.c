#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>
#include<windows.h>
#include<string.h>


void close(void)
{
    system("cls");
    printf("\n\n\n\t\t THIS WAS C-DATA STRUCTURES MINI PROJECT \n\n\t\t DEVELOPED BY TSEC STUDENTS : - ASHISH GANGWANI \n\t\t                              - PARTH JANGID\n\n\n");
    }

struct node
{
    char name[50];
    char address[100];
    char acc_type[20];
    double balance;
    int acc_no;
    long long int phone;
    int age,day,month,year;

    struct node *next;
};

struct node *start=NULL;

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void new_acc()
{
        system("cls");
    int just,i;
    char nam[50],addr[100],temp,tempo;
    struct node *ptr,*newacc,*preptr;

    newacc = (struct node *)malloc(sizeof(struct node));
    if(start==NULL)
    {
        start = newacc;
        printf("\n\t\t ENTER NAME :  ");
        gets(nam);
        strcpy(newacc->name,nam);

    printf("\n\t\t ENTER ADDRESS :  ");
    scanf("%s",newacc->address);
    gets(addr);
    strcpy(newacc->address,addr);

    printf("\n\t\t ENTER ACCOUNT TYPE :\n\t\t\t\t #--SAVINGS \n\t\t\t\t #--CURRENT\n\t\t ENTER CHOICE  :  ");
    scanf("%s",&newacc->acc_type);
    age :
    printf("\n\t\t ENTER AGE :  ");
    scanf("%d",&newacc->age);
    if(newacc->age<18)
    {
        printf("\t\t\t ----INVALID AGE----\n");
        goto age ;
    }

    printf("\n\t\t ENTER PHONE N0. :  ");
    scanf("%lli",&newacc->phone);
    printf("\n\t\t ENTER BALANCE :  ");
    scanf("%lf",&newacc->balance);

    date :
    printf("\n\t\t ENTER TODAY'S DATE(DD/MM/YYYY) :  ");
    scanf("%d/%d/%d",&newacc->day,&newacc->month,&newacc->year);
    if(newacc->day>31||newacc->day<1 || newacc->month>12 || newacc->month<1 || newacc->year > 2019 || (newacc->day>28&&newacc->month==2) || newacc->year!=2019)
    {
        printf("DATE NOT ACCEPTED.......PLEASE RE-ENTER");
        goto date ;
    }
        printf("\n\t\t ENTER ACCOUNT_NUMBER :  ");
        scanf("%d",&newacc->acc_no);

        newacc->next=NULL;
        start =newacc;
    system("cls");

        printf("\n\t\tSUCCESSFULLY RECORDED\n");
    }
    else
    {
            system("cls");

        re_enter :
       printf("\n\t\t ENTER NAME :  ");
        gets(nam);
        strcpy(newacc->name,nam);

    printf("\n\t\t ENTER ADDRESS :  ");
    //scanf("%s",newacc->address);
    gets(addr);
    strcpy(newacc->address,addr);

    printf("\n\t\t ENTER ACCOUNT TYPE :\n\t\t\t\t #--SAVINGS \n\t\t\t\t #--CURRENT\n\t\t ENTER CHOICE  :  ");
    scanf("%s",&newacc->acc_type);
    age1 :
    printf("\n\t\t ENTER AGE :  ");
    scanf("%d",&newacc->age);
    if(newacc->age<18)
    {
        printf("\n\t\t\t -----INVALID AGE-----\n");
        goto age1 ;
    }

      printf("\n\t\t ENTER PHONE N0. :  ");
    scanf("%lli",&newacc->phone);
    printf("\n\t\t ENTER BALANCE :  ");
    scanf("%lf",&newacc->balance);


   date1 :
    printf("\n\t\t ENTER TODAY'S DATE(DD/MM/YYYY) :  ");
    scanf("%d/%d/%d",&newacc->day,&newacc->month,&newacc->year);
    if(newacc->day>31||newacc->day<1 || newacc->month>12 || newacc->month<1 || newacc->year > 2019 || (newacc->day>28&&newacc->month==2))
    {
        printf("\n\t\t DATE NOT ACCEPTED.......PLEASE RE-ENTER");
        goto date1 ;
    }
        printf("\n\t\t ENTER ACCOUNT_NO. : ");
        scanf("%d",&newacc->acc_no);

        ptr = start;
        preptr = ptr;
        while(ptr!=NULL)
        {

            if(newacc->acc_no==preptr->acc_no)
            {
                printf("\n\t\t ACC_NO. ALREADY TAKEN\n\t\t PLEASE WAIT FORWARDING TO MENU ");
                 for(i=0;i<=6;i++)
                {
                    fordelay(100000000);
                    printf(".");
                }
                menu();
            }
            preptr = ptr ;
            ptr=ptr->next;

        }
        if(preptr->acc_no==newacc->acc_no)
        {
            printf("\n\t\t ACC_NO. ALREADY TAKEN\n\t\t PLEASE WAIT FORWARDING TO MENU ");
                 for(i=0;i<=6;i++)
                {
                    fordelay(100000000);
                    printf(".");
                }
                menu();
        }
        else
        {
            preptr->next=newacc;
            newacc->next=NULL;
        }
    }
    system("cls");
    printf("\n\n\t\tSUCCESSFULLY RECORDED\n");

    printf("\n\n\t\tENTER 1 FOR MAIN MENU || 0 TO EXIT : \n\t\tENTER YOUR CHOICE :   ");
    scanf("%d",&just);
    if(just==1)
    {
        menu();
    }
    if(just==0)
    {
        close();
    }
}

void see()
{
    again :
    system("cls");
    struct node *ptr;
    ptr = start;
    int noacc,flag=0,todo;
    printf("\n\t\t Enter ACCOUNT_NUMBER :  ");
    scanf("%d",&noacc);


    if(start==NULL)
    {
        printf("\n\t\t NOTHING TO DISPLAY\n");
    }
    else if(start->next==NULL)
    {
        if(noacc==start->acc_no)
        {
        printf("\n\t\t ACC DETAILS ARE : \n");
        flag=1;
        printf("NAME\t\tACC_NO\tPHONE N0.\t\tBALANCE\n");
                printf("%s\t",ptr->name);
                printf("%d\t",ptr->acc_no);
                printf("%lli\t\t",ptr->phone);
                printf("%lf",ptr->balance);
        }

    }
    else
    {

        while(ptr!=NULL)
        {
            if(noacc==ptr->acc_no)
            {
                flag=1;
                printf("\n\t\t ACC DETAILS ARE : \n");
               printf("NAME\t\tACC_NO\tPHONE N0.\t\tBALANCE\n");
                printf("%s\t",ptr->name);
                printf("%d\t",ptr->acc_no);
                printf("%lli\t\t",ptr->phone);
                printf("%lf",ptr->balance);
                break;
            }
            ptr=ptr->next;
        }
    }
    if(flag==0)
    {
        printf("\n\t\t NOTHING FOUND REGARDING THAT ACC_NO.!!\n");
    }

    printf("\n\n\nENTER --> 1: FOR THE MENU , 2: TO EXIT , 0: TO TRY AGAIN:: YOUR CHOICE :   ");
    scanf("%d",&todo);
    if(todo==1)
    {
        menu();
    }
    else if(todo==2)
    {
        close();
    }
    else if(todo==0)
    {
        goto again;
    }
}

void transact()
{
    system("cls");
    int choice,option,acc,flag=0,i,strength=0,tp=0,let;
    double amt;

    struct node *ptr;
    ptr = start ;

    printf("\n\t\t WOULD YOU LIKE TO :\n\t\t                    1--DEPOSIT\n\t\t                    2--WITHDRAW\n\n");
    printf("\n\t\t ENTER YOUR CHOICE  :  ");
    scanf("%d",&choice);

    system("cls");

    repeat :

    printf("\n\t\t ENTER YOUR ACC NO  :  ");
    scanf("%d",&acc);

    if(choice==1)
    {
        more :

        printf("\n\t\t ENTER THE AMOUNT YOU WANT TO DEPOSIT :  ");
        scanf("%lf",&amt);

        if(amt<=0)
        {
            printf("\n\t\t THE AMOUNT %lf IS INCORRECT \n",amt);
            printf("\n\t\t WOULD YOU LIKE TO ENTER AGAIN : \n\n\t1--YES \n\n\t 2-- NO , GO TO MAIN MENU \n");
            scanf("%d",&option);
            if(option==1)
            {
                goto more;
            }
            if(option==2)
            {
                menu();
            }

        }


    if(start==NULL)
    {
        printf("\n\n\t\t NO DATA PRESENT");
         printf("\n\t\tPROCEEDING TO MENU PLEASE WAIT ");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
        menu();
        strength=1;
    }
    if(strength==0)
    {
        if(start->acc_no==acc)
    {
        //printf("working");
        ptr->balance = ( (ptr->balance)+amt );
        printf("\n\t\tSUCCESSFULL TRANSACTION \n\t\t PROCEEDING TO MENU PLEASE WAIT ");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
        menu();
        tp=1;
    }
    if(tp==0)
    {

    {
        //printf("working1");
        while(ptr->next!=NULL)
        {
            if(ptr->acc_no==acc)
            {
                flag=1;
                break;
            }
            ptr=ptr->next;
        }
    }
    if(flag==0)
    {
        printf("\n\t\t NO SUCH ACC FOUND\n");
        printf("\n\t\t WOULD YOU LIKE TO ENTER AGAIN : 1--YES OR 2-- NO , GO TO  MAIN MENU \n \t\tENTER CHOICE : ");
        scanf("%d",&option);
            if(option==1)
            {
                goto repeat;
            }
            if(option==2)
            {
                menu();
            }
    }
        if(flag==1)
        {
        //printf("working2");
            ptr->balance=((ptr->balance)+amt);
            printf("\n\n\t\t -----TRANSACTION SUCCESSFULL -----\n");
        }
    }
    }
    }
    if(choice==2)
    {
        system("cls");

        while(ptr!=NULL)
        {
            if(ptr->acc_no=acc)
            {
                flag=1;
                break;
            }
            ptr=ptr->next;
        }
        if(flag==0)
        {
            printf("\n\n\t\tNO RECORDS FOUND . MOVING YOU TO MAIN MENU PLEASE WAIT ");
            for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
        menu();
        }


        if(ptr->balance==0)
        {
            printf("\n\t\tYOUR BALANCE IS %lf NOT SUFFICIENT",ptr->balance);
            printf("\n\t\t PROCEEDING TO MENU PLEASE WAIT ");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
        menu();
        }

        re :

        printf("\n\t\t ENTER THE AMOUNT TO WITHDRAW :  ");
        scanf("%lf",&amt);

        if(amt<=0)
        {
            printf("\n\t\t ENTER APPROPRIATE AMOUNT \n");
            printf("\n\t\t DO YOU WANT TO TRY AGAIN : 1--TRY AGAIN && 2--GO TO MENU\n\n");
            printf("\n\t\t ENTER YOUR CHOICE :  ");
            scanf("%d",&let);
            if(let==1)
            {goto re;}
            if(let==2)
            {
                menu();
            }
        }
        else if(amt>ptr->balance)
        {
            printf("\n\t\t ( INSUFFICIENT BALANCE ) YOUR BAL = %lf < WITHDRAW AMOUNT = %lf",ptr->balance,amt);
            printf("\n\t\t DO YOU WANT TO TRY AGAIN : 1--TRY AGAIN && 2--GO TO MENU\n\n");
            printf("\n\t\t ENTER YOUR CHOICE :  ");
            scanf("%d",&let);
            if(let==1)
            {goto re;}
            if(let==2)
            {
                menu();
            }
        }

        else
        {
            ptr->balance = ((ptr->balance)-amt);
            printf("\n\t\t -----WITHDRAWAL SUCCESFULL-----");
            printf("\n\t\t ENTER : 1-- EXIT OR 2--MAIN MENU\n \t\t CHOICE : ");
            scanf("%d",&let);
            if(let==1)
            {close();}
            if(let==2)
            {
                menu();
            }
        }
    }
}

void erase()
{
    system("cls");
    int acc,i,flag=0,choice;
    char del[7]="delete",confirm[7];
    struct node *ptr,*preptr;
    ptr = start ;
    preptr = start ;

    if(start==NULL)
    {
        printf("\n\n\n\t\t NO RECORDS TO DISPLAY");
        printf("\n\n\t\t DIRECTING TOWARDS MENU : KINDLY WAIT ");
         for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
        menu();
    }
    else
    {
        once :
        system("cls");
        printf("\n\t\t FOR DELETION :  \n");
        printf("\n\t\t PLEASE ENTER ACC_NO. :  ");
        scanf("%d",&acc);

        if(start->acc_no==acc&&start->next==NULL)
        {
            printf("\n\t\t ENTER PASSWORD :  ");
            scanf("%s",&confirm);
            if(strcmp(confirm,del)==0)
            {
            printf("\n\t\t DELETING  ");
                for(i=0;i<=6;i++)
                {
                    fordelay(100000000);
                    printf(".");
                }
            start = NULL;
            printf("\n\t\t PROCEEDING TOWARDS MENU ");
                for(i=0;i<=6;i++)
                {
                    fordelay(100000000);
                    printf(".");
                }
                menu();
            }
        }
        else if( (start->acc_no==acc )&& (start->next!=NULL))
        {
            printf("\n\t\t ENTER PASSWORD :  ");
            scanf("%s",&confirm);
            if(strcmp(confirm,del)==0)
            {
            printf("\n\t\t DELETING  ");
                for(i=0;i<=6;i++)
                {
                    fordelay(100000000);
                    printf(".");
                }
            start = start -> next ;
            printf("\n\t\t PROCEEDING TOWARDS MENU ");
                for(i=0;i<=6;i++)
                {
                    fordelay(100000000);
                    printf(".");
                }
                menu();
            }
        }
        else
        {
            while(ptr!=NULL)
            {
                if(ptr->acc_no==acc)
                {
                    flag=1;
                    break;
                }
                preptr=ptr;
                ptr=ptr->next;
            }
            if(flag==1)
            {
                printf("\n\t\t ENTER PASSWORD :  ");
            scanf("%s",&confirm);
            if(strcmp(confirm,del)==0)
            {
                preptr->next=ptr->next;
                free(ptr);
                printf("\n\t\t SUCCESSFULLY DELETED");
            }
                printf("\n\t\t PROCEEDING TOWARDS MENU ");

                for(i=0;i<=6;i++)
                {
                    fordelay(100000000);
                    printf(".");
                }
                menu();

            }
            if(flag==0)
            {
                printf("\n\n\t NO SUCH ACC FOUND : \n\n\t\t ENTER : 1 - TRY AGAIN  2 - EXIT   3 - MENU \n");
                printf("ENTER CHOICE :  ");
                scanf("%d",&choice);
                if(choice==3)
                {
                    menu();
                }
                if(choice==2)
                {
                    close();
                }
                if(choice==1)
                {
                    goto once;
                }
            }

        }

    }
}

void view_list()
{
    system("cls");
    int i,choice;
    struct node *ptr;
    ptr = start;

    if(start == NULL)
    {
        printf("\n\t\t NO DATA TO DISPLAY ");
        printf("\n\n\t\t BACK TO MENU ");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
            menu();
    }
    else
    {
        printf("\n\t\t ACC DETAILS ARE : \n\n");
        while(ptr!=NULL)
        {
            printf("NAME\t\tACC_NO\tPHONE N0.\tBALANCE\n");
            printf("%s\t",ptr->name);
            printf("%d\t",ptr->acc_no);
            printf("%lli\t\t",ptr->phone);
            printf("%lf",ptr->balance);
            ptr=ptr->next;
            printf("\n");
        }

        printf("\n\n\t\t -----END OF LIST -----\n\n");
        printf("\t\tENTER : 1 -- MENU ; 2 -- EXIT\n");
        printf("\n\t\tENTER CHOICE  :  ");
        scanf("%d",&choice);
        if(choice==1)
        {
            menu();
        }
        if(choice==2)
        {
            close();
        }
    }
}

void menu()
{   int choice;
    char temp;
    system("cls");
    system("color E");
    printf("\n\t\t   BANKING MANAGEMENT SYSTEM\n");
    printf("\n\t********** WELCOME TO THE MAIN MENU *********\n");
    printf("\n\t\t1.Create new account\n\t\t2.For transactions\n\t\t3.Check the details of existing account\n\t\t4.Removing existing account\n\t\t5.View customer's list\n\t\t6.Exit\n\n\t\tEnter your choice:   ");
    scanf("%d",&choice);
    scanf("%c",&temp);
    switch(choice)
    {
        case 1:new_acc();
        break;

        case 2:transact();
        break;

        case 3:see();
        break;

        case 4:erase();
        break;

        case 5:view_list();
        break;

        case 6:close();
        break;
    }
}

void main()
{
    char pass[9],password[9]="justdoit";
    int i=0,main_exit;
    system("color E");
    printf("\n\n\t\tEnter the password to login:  ");
    scanf("%s",pass);

    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
            menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try_again:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {
                        main();
                    }

            else if (main_exit==0)
                    {
                    close();
                    }
            else
                    {
                    printf("\nInvalid!");
                    fordelay(1000000000);

                    goto login_try_again;
                    }

        }
}
