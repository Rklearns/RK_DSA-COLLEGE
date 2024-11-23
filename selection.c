#include<stdio.h>
#define n 5   //here I am defining global variables as n 5
int arr[n];

void selectionsort();//function prototype

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
    selectionsort();

    printf("array after sorting is\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}

void selectionsort()
{
    int right=0;
    for(int i=0;i<n-1;i++)
    {
        int min=i;//stores the index which has the least element
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                 min=j;
            }
        }
        int t;
        t=arr[i];
        arr[i]=arr[min];
        arr[min]=t;
    }
}
