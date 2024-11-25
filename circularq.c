#include<stdio.h>
#define size 5

void enqueue();
void dequeue();
void peek();
void display();

int front=-1;
int rear=-1;
int q[size];
int main()
{
    int num;
    int choice;
    do  {
    printf("Queue list\n");
    printf("enter 1 for enqueue\n enter 2 for dequeue\n enter 3 for display\n enter 4 for peek\n enter 5 for exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("enter value to be pushed: ");
        scanf("%d",&num);
        enqueue(num);
        break;
         case 2:
        dequeue();
        break;
         case 3:
         display();
        break;
         case 4:
         peek();
        break;
         case 5:
        break;
        default:
        choice=5;
        printf("Invalid input");
        }
    }while(choice!=5);
    return 0;
}
void enqueue(int ele)
{
    if(front==-1 && rear==-1)
    {
        front++;
        rear++;
        q[rear]=ele;
    }
    else if(front==(rear+1)%size)
    {
     printf("cant enqueue\n");
    }
    else
    {
        rear=(rear+1)%size;
        q[rear]=ele;
    }
}  
void dequeue()
{
    if(front==-1 || rear==-1)printf("cant dequeue");
    else
    {
    int removed=q[front];
    if(front==rear)//destroy the queue
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front=(front+1)%size;
    }
    printf("The removed element is %d\n",removed);
    }
} 
void peek()
{
    if(front==-1 || rear==-1)printf("no peek\n");
    else
    {
        printf("peek element is %d\n",q[front]);
    }
}
void display()
{
    if(front==-1 || rear==-1)printf("nothing to display\n");
    else
    {
        int i=front;
        while(i!=rear)
        {
            printf("%d ",q[i]);
            i=(i+1)%size;
        }
        printf("%d\n",q[rear]);
    }
}