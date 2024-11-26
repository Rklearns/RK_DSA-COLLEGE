#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* rear=NULL;
struct node* front=NULL;

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
    struct node * nn=(struct node*)malloc(sizeof(struct node));
    nn->data=ele;
    nn->next=NULL;
    if(rear==NULL && front==NULL)
    {
        rear=nn;
        front=nn;
    }
    else
    {
        rear->next=nn;
        rear=nn;
    }
}
void dequeue()
{
    if(front==NULL)printf("nothing to dequeue\n");
    else
    {
        printf("the node to be dequeud is %d\n",front->data);
        struct node * delete=front;
        front=front->next;
        free(delete);
    }
}
void peek()
{
    if(front==NULL)printf("no peek\n");
    else
    printf("peek element is %d\n",front->data);
}
void display()
{
    if(front==NULL)printf("no display\n");
    else
    {
        struct node* temp=front;
        while(temp!=rear)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",rear->data);
        printf("\n");
    }
}