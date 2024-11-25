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

int main()
{
   int n;

   head=createnode(4);
   head->next=createnode(5);
   head->next->next=createnode(6);
   head->next->next->next=createnode(7);
   head->next->next->next->next=createnode(8);// therefore 4 5 6 7 8 

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
void insertbefore()
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
    
    while(temp!=NULL && temp->data!=b)
            {
                prev=temp;
                temp=temp->next;
            }
            if(temp==head)
            {
                newnode->next=head;
                head=newnode;
            }
            else{
            newnode->next=prev->next;
            prev->next=newnode;
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
     
       while(temp!=NULL && temp->data!=a)
        {
            temp=temp->next;
        }
        temp->next=newnode;

}
void delete()//we assume that the value which is entered to be deleted is present there
{
    int d;
    printf("enter value to delete\n");
    scanf("%d",&d);
    struct node * temp=head;
    struct node* prev=temp;

        while(temp!=NULL && temp->data!=d)
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp==head)
        {
            head=head->next;
            free(temp);
        }
        else
        {
            prev->next=temp->next;
            free(temp);
        }
}
void display()
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}