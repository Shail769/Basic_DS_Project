#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Share
{
    char name[100];
    int quantity;
    float current_price;
    float buy_price;
    struct Share *next;
};
struct Share *head=NULL,*temp=NULL;
void Add_Share(char x[100],int q,float crp,float byp)
{
    struct Share *newnode = (struct Share *)malloc(sizeof(struct Share));
    strcpy(newnode->name,x);
    newnode->quantity = q;
    newnode->current_price = crp;
    newnode->buy_price = byp;
    newnode->next = NULL;
    if(head == NULL)
        head = newnode;
    else
    {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}
void disp(struct Share *a)
{
    struct Share *temp3;
    temp3 = a;
    while(temp3!=NULL)
    {
        printf("Share Name:%s\n" ,temp3->name);
        printf("Quantity of Shares:%d\n" ,temp3->quantity);
        printf("Current Price of Shares:%f\n" ,temp3->current_price);
        printf("Buying Price of Shares:%f\n" ,temp3->buy_price);
        temp3=temp3->next;
    }
}
void Delete_Share(char x[100])
{
    struct Share *temp1;
    temp = head;
    while(temp != NULL && strcmp(temp->name,x) != 0)
    {
        temp1=temp;
        temp=temp->next;
    }
    if(temp == NULL)
        printf("SHARE not Found");
    else
    {
        temp1->next=temp->next;
        printf("Deleted Share Details are:\n");
        disp(temp);
        free(temp);
    }
}
float net_profit(struct Share *a)
{
    float sum = 0.0;
    temp = a;
    while(temp!=NULL)
    {
        sum += (temp->quantity)*(temp->current_price - temp->buy_price);
        temp=temp->next;
    }
    return sum;
}
float profit_per_Share(char a[100])
{
    float s = 0.0;
    temp = head;
    while(temp != NULL && strcmp(temp->name,a) != 0)
        temp=temp->next;
    if(temp == NULL)
    {
        printf("SHARE not Found\n");
        return -1;
    }
    else
    {
        s = (temp->quantity)*(temp->current_price - temp->buy_price);
        return s;
    }
}
void main()
{
    int ch,d,decide;
    char a[100],b[100],c[100];
    float cp,bup;
    do
    {
        printf("\n==========STOCK MARKET PORTFOLIO==========\n\n\n");
        printf("1.Add a Share to Portfolio\n");
        printf("2.Delete a Share from the Portfolio\n");
        printf("3.See the NET PROFIT/LOSS\n");
        printf("4.See PROFIT/LOSS per SHARE\n");
        printf("5.Display Your Portfolio:\n");
        printf("Enter your Choice:");
        scanf("%d" ,&ch);
        switch(ch)
        {
            case 1:printf("Enter SHARE name:");
                   scanf("%s" ,a);
                   printf("Enter Quantity of SHARES:");
                   scanf("%d" ,&d);
                   printf("Enter Current Price of SHARE:");
                   scanf("%f" ,&cp);
                   printf("Enter Buying Price of SHARE:");
                   scanf("%f" ,&bup);
                   Add_Share(a,d,cp,bup);
                   break;
            case 2:if(head == NULL)
                   {
                        printf("No SHARES to Delete");
                        break;
                   }
                   printf("Enter the Name of the SHARE to Delete:");
                   scanf("%s" ,b);
                   Delete_Share(b);
                   break;
            case 3:printf("The NET PROFIT/LOSS in all the SHARES is:  Rs.%f\n" ,net_profit(head));
                   break;
            case 4:printf("Enter the Name of the SHARE to Check PROFIT/LOSS:\n");
                   scanf("%s" ,c);
                   if(profit_per_Share(c) == -1)
                        break;
                   else
                   {
                        printf("Profit/LOSS for SHARE %s is %f\n" ,c,profit_per_Share(c));
                        break;
                   }
            case 5:disp(head);
                   break;
            default:printf("Wrong Choice");
                    break;
        }
    printf("Do you Want to continue: YES(1) or NO(0)");
    scanf("%d" ,&decide);
    }while(decide == 1);
}

/*


==========STOCK MARKET PORTFOLIO==========


1.Add a Share to Portfolio
2.Delete a Share from the Portfolio
3.See the NET PROFIT/LOSS
4.See PROFIT/LOSS per SHARE
5.Display Your Portfolio:
Enter your Choice:1
Enter SHARE name:Infosys
Enter Quantity of SHARES:48
Enter Current Price of SHARE:1099.6
Enter Buying Price of SHARE:990.33
Do you Want to continue: YES(1) or NO(0)1

==========STOCK MARKET PORTFOLIO==========


1.Add a Share to Portfolio
2.Delete a Share from the Portfolio
3.See the NET PROFIT/LOSS
4.See PROFIT/LOSS per SHARE
5.Display Your Portfolio:
Enter your Choice:1
Enter SHARE name:TCS
Enter Quantity of SHARES:68
Enter Current Price of SHARE:766
Enter Buying Price of SHARE:800.91
Do you Want to continue: YES(1) or NO(0)1

==========STOCK MARKET PORTFOLIO==========


1.Add a Share to Portfolio
2.Delete a Share from the Portfolio
3.See the NET PROFIT/LOSS
4.See PROFIT/LOSS per SHARE
5.Display Your Portfolio:
Enter your Choice:5
Share Name:Infosys
Quantity of Shares:48
Current Price of Shares:1099.599976
Buying Price of Shares:990.330017
Share Name:TCS
Quantity of Shares:68
Current Price of Shares:766.000000
Buying Price of Shares:800.909973
Do you Want to continue: YES(1) or NO(0)1

==========STOCK MARKET PORTFOLIO==========


1.Add a Share to Portfolio
2.Delete a Share from the Portfolio
3.See the NET PROFIT/LOSS
4.See PROFIT/LOSS per SHARE
5.Display Your Portfolio:
Enter your Choice:3
The NET PROFIT/LOSS in all the SHARES is:  Rs.2871.079834
Do you Want to continue: YES(1) or NO(0)1

==========STOCK MARKET PORTFOLIO==========


1.Add a Share to Portfolio
2.Delete a Share from the Portfolio
3.See the NET PROFIT/LOSS
4.See PROFIT/LOSS per SHARE
5.Display Your Portfolio:
Enter your Choice:4
Enter the Name of the SHARE to Check PROFIT/LOSS:
Infosys
Profit/LOSS for SHARE Infosys is 5244.958008
Do you Want to continue: YES(1) or NO(0)1

==========STOCK MARKET PORTFOLIO==========


1.Add a Share to Portfolio
2.Delete a Share from the Portfolio
3.See the NET PROFIT/LOSS
4.See PROFIT/LOSS per SHARE
5.Display Your Portfolio:
Enter your Choice:4
Enter the Name of the SHARE to Check PROFIT/LOSS:
TCS
Profit/LOSS for SHARE TCS is -2373.878174
Do you Want to continue: YES(1) or NO(0)1

==========STOCK MARKET PORTFOLIO==========


1.Add a Share to Portfolio
2.Delete a Share from the Portfolio
3.See the NET PROFIT/LOSS
4.See PROFIT/LOSS per SHARE
5.Display Your Portfolio:
Enter your Choice:4
Enter the Name of the SHARE to Check PROFIT/LOSS:
MCX
SHARE not Found
Do you Want to continue: YES(1) or NO(0)1

==========STOCK MARKET PORTFOLIO==========


1.Add a Share to Portfolio
2.Delete a Share from the Portfolio
3.See the NET PROFIT/LOSS
4.See PROFIT/LOSS per SHARE
5.Display Your Portfolio:
Enter your Choice:2
Enter the Name of the SHARE to Delete:TCS
Deleted Share Details are:
Share Name:TCS
Quantity of Shares:68
Current Price of Shares:766.000000
Buying Price of Shares:800.909973
Do you Want to continue: YES(1) or NO(0)1

==========STOCK MARKET PORTFOLIO==========


1.Add a Share to Portfolio
2.Delete a Share from the Portfolio
3.See the NET PROFIT/LOSS
4.See PROFIT/LOSS per SHARE
5.Display Your Portfolio:
Enter your Choice:5
Share Name:Infosys
Quantity of Shares:48
Current Price of Shares:1099.599976
Buying Price of Shares:990.330017
Do you Want to continue: YES(1) or NO(0)0

Process returned 0 (0x0)   execution time : 149.515 s
Press any key to continue.

*/
