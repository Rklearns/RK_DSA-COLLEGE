#include<stdio.h>
#define size 100

char infix[size];
char prefix[size];
char st[size];
int top=-1;

int prec(char x);
void push(char ele);
char pop();
void infixtoprefix();
void reversestring(char * x);


int main()
{
    int i=0;
    printf("enter infix expression\n");
    scanf("%s",infix);//not that here & sign wont come as infix used as pointer
    infixtoprefix();
    printf("therefore the prefix expression is \n");
     while (prefix[i] != '\0')
    {
        printf("%c",prefix[i++]);
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
void infixtoprefix()
{
    int i=0;
    int j=0;
    char x;
    reversestring(infix);
    while(infix[i]!='\0')
    {
         x=infix[i];
        if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z') || (x >= '0' && x <= '9'))
        {
            prefix[j++]=x;
        }
        else if(x=='(')
        {
            push(x);
        }
        else if(x=='+' || x=='-' || x=='%' || x=='/' || x=='*' || x=='^')
        {
            while(prec(x)<=prec(st[top]) && top!=-1)
            {
                prefix[j++]=pop();
            }
            push(x);
        }
        else if(x==')')
        {
            while(top!=-1 && st[top]!='(')
            {
                prefix[j++]=pop();
            }
            if(top!=-1)pop();
        }
        i++;//infix expression ka aage ka part dikhane ke liye

    }
    while(top!=-1)
    {
        prefix[j++]=pop();
    }
    prefix[j]='\0';//this marks the end of postfix expression
    reversestring(prefix);
}
void reversestring(char *str)
{
 int start=0;
 int end=0;
while(str[end]!='\0')
{
    end++;//finds length 

}
end=end-1;
 while(end>start)
 {
    char temp=str[start];
    str[start]=str[end];
    str[end]=temp;
    start++;
    end--;
 }
 int i=0;
 while(str[i]!='\0')//reversing the brackets
 {
    if(str[i]=='(')
    str[i]=')';
    else if(str[i]==')')
    {
    str[i]='(';
    }
    i++;
    
 }

}