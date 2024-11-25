#include<stdio.h>
#define size 100

char infix[size];
char postfix[size];
char st[size];
int top=-1;

void prece();
void push(char ele);
char pop();
void infixtopostfix();


int main()
{
    int i=0;
    printf("enter infix expression\n");
    scanf("%s",infix);//not that here & sign wont come as infix used as pointer
    infixtopostfix();
    printf("therefore the postfix expression is \n");
     while (postfix[i] != '\0')
    {
        printf("%c",postfix[i++]);
    }
    printf("\n");
    
    return 0;
}
int prec(char x)
{
   if(x=='^' || x=='%')return 3;
   else if(x=='*' || x=='/')return 2;
   else if(x=='+' || x=='-')return 1;
   else if(x=='(')return 0;
   else return -1;
}
void push(char ele)
{
    if(top==size-1)
    printf("overflow\n");
    else
    {
        st[++top]=ele;
    }
}
char pop()
{
    if(top==-1)
    {
    return -1;
    }
    return st[top--];
}
void infixtopostfix()
{
    int i=0;
    int j=0;
    char x;
    while(infix[i]!='\0')
    {
         x=infix[i];
        if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z') || (x >= '0' && x <= '9'))
        {
            postfix[j++]=x;
        }
        else if(x=='(')
        {
            push(x);
        }
        else if(x=='+' || x=='-' || x=='%' || x=='/' || x=='*' || x=='^')
        {
            while(prec(x)<=prec(st[top]) && top!=-1)
            {
                postfix[j++]=pop();
            }
            push(x);
        }
        else if(x==')')
        {
            while(top!=-1 && st[top]!='(')
            {
                postfix[j++]=pop();
            }
            if(top!=-1)pop();
        }
        i++;//infix expression ka aage ka part dikhane ke liye

    }
    while(top!=-1)
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';//this marks the end of postfix expression
}