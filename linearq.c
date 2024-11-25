#include<stdio.h>
#include<stdlib.h>
#define size 5

int rear=-1;
int front=-1;
int q[size];

void enqueue(int ele);
void dequeue();
void display();
void peek();

int main()
{
    int choice;
    int num;
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
         printf("exiting code...\n");
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
    if(rear==size-1)
    printf("queue overflow\n");
    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        q[rear]=ele;
    }
    else
    {
        q[++rear]=ele;
    }
}
void dequeue()
{
    if(front==-1 || rear==-1)
    {
        printf("no element can pe dequeued\n");
    }
    else{
    int removed=q[front];
    if(front==rear)//destroy the queue and initilize it to -1 again
    {
        front=-1;
        rear=-1;
    }
    else{
        front++;
    }
    printf("element that is deququed is %d\n",removed);
    }
}
void peek()
{
    if(front==-1 || rear==-1) printf("no peek present\n");
    else
    {
        printf("peek present is %d",q[front]);
    }
}
void display()
{
    if(front==-1) printf("nothing to display");
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",q[i]);
        }
        printf("\n");
    }
}
