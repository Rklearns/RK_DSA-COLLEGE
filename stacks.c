#include<stdio.h>
#include<stdlib.h>

int top=-1;
#define size 5
int st[size];

void push(int ele);//function prototype
void pop();
void display();
void peek();

int main()
{
    int n;
    int val;
    do
    {
        printf("enter 1 for push\nenter 2 for pop\nenter 3 for display\nenter 4 for peek\nenter 5 for exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            printf("enter number to push\n");
            scanf("%d",&val);
            push(val);
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            peek();
            break;
            case 5:
            printf("exiting the code....\n");
            break;
            default:
            printf("INVALID CHOICE");
  }

    }while(n!=5);
    return 0;
}
void push(int ele)
{
    if(top==size-1)
    {
        printf("Stack overflow");
    }
    else
    {
        st[++top]=ele;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("Stack underflow");
    }
    else
    {
        printf("removed element is %d\n",st[top--]);
    }
}
void peek()
{
    if(top==-1)
    {
        printf("no peek\n");    
    }
    else
    {
        printf("peek element is %d\n",st[top]);
    }
}
void display()
{
    if(top==-1)
    {
        printf("nothing to display\n");
    }
    else
    {
        for(int i=top;i>=0;i--)
        {
            printf("%d ",st[i]);
        }
        printf("\n");
    }
}