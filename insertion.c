#include<stdio.h>
#define n 5   //here I am defining global variables as n 5
int arr[n];

void insertionsort();//function prototype

int main()
{
    printf("enter array elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("array before sorting is\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    insertionsort();

    printf("array after sorting is\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}

void insertionsort()
{
    for(int i=1;i<n;i++)//lets take eg of 4 1 2 0 3 then 1 4 2 0 3 then 1 2 4 0 3 basically keep swapping
    {
        int check=i-1;
        while(check>=0 && arr[check]>arr[check+1])
        {
            int t;
            t=arr[check];
            arr[check]=arr[check+1];
            arr[check+1]=t;
            check--;
        }
    }
}
