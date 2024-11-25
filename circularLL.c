#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
}*head=NULL;

struct node * createnode(int val)
{
    struct node *nn=(struct node*)malloc(sizeof(struct node));
    nn->data=val;
    nn->next=NULL;
    return nn;
}

void insertbefore();
void insertafter();
void display();
void delete();
struct node * createnode(int val);
void create();

int main()
{

   create();
int n;
  do{
    printf("enter 1 for insertbefore\nenter 2 for insertafter\nenter 3 for delete\nenter 4 for display\nenter 5 for exit\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        insertbefore();
        break;
        case 2:
        insertafter();
        break;
        case 3:
        delete();
        break;
        case 4:
        display();
        break;
        case 5:
        printf("exiting the code....");
        break;
        default:
        printf("enter appropriate value please\n");
        break;
    }
  }while(n!=5);
  return 0;
}
void insertbefore()//we presume all values present in LL before which we have to insert
{
    int val;
    int b;
    printf("enter value to insert\n");
    scanf("%d",&val);
    printf("enter node before which u have to insert\n");
    scanf("%d",&b);
    struct node* newnode=createnode(val);
    struct node* temp=head;
    struct node * prev=temp;
    
   if(head->data==b && head->next==head)//that is if only head is present then
   {
        newnode->next=head;
        head->next=newnode;
        head=newnode;
   }
   else
   {
    if(head->data==b)//head has to be deleted but there it isnt the only one in LL
    {
     while(temp->next!=head)
     {
        temp=temp->next;
     }
     newnode->next=temp->next;
     temp->next=newnode;
     head=newnode;
    }
    else
    {
        while(temp->data!=b && temp->next!=head)
        {
            prev=temp;
            temp=temp->next;
        }
       newnode->next= prev->next;
       prev->next=newnode;
    }
   }
}
  
void insertafter()// for these codes u can put that if temp==null value not found but here we are assuming that value always present in the code
{
    int val;
    int a;
    printf("enter value to insert\n");
    scanf("%d",&val);
    printf("enter node after which u have to insert\n");
    scanf("%d",&a);
    struct node* newnode=createnode(val);
    struct node* temp=head;
     
    while(temp->next!=head && temp->data!=a)
    {
        temp=temp->next;
    }
        newnode->next=temp->next;
        temp->next=newnode;
}
void delete()//we assume that the value which is entered to be deleted is present there
{
    int d;
    printf("enter value to delete\n");
    scanf("%d",&d);
    struct node * temp=head;
    struct node* prev=temp;
    struct node* delete;

    if(head->data==d && head->next==head)
    {
        free(head);
    }
    else
    {
        if(head->data==d)//if to be deleted item is head and list is not just one then
        {
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=head->next;
            delete=head;
            head=head->next;
            free(delete);//free the head
        }
        else
        {
            while(temp->next!=head && temp->data!=d)
            {
                prev=temp;
                temp=temp->next;
            }
            prev->next=temp->next;
            free(temp);
        }
    }
    
}
void display()
{
    struct node* temp=head;
    while(temp->next!=head)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void create()
{
    struct node * temp;
    for(int i=0;i<5;i++)
    {
        int val;
        struct node * nn=(struct node*)malloc(sizeof(struct node*));
        printf("enter value of node number %d:\n",i+1);
        scanf("%d",&val);

        nn->data=val;
        nn->next=NULL;

        if(head==NULL)
        {
            head=nn;
            temp=nn;
        }
        else
        {
            temp->next=nn;
            temp=nn;//or we can say temp=temp->next so that it goes ahead
        }
    }
        if(temp!=NULL)
        {
            temp->next=head;//the end of the LL will point to head
        }   
}