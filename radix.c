#include<stdio.h>
#define n 5
int arr[n];

void radixsort();
int getmax();
void countingsort(int exp);

int main()
{
    printf("enter 5 elements: ");
    for(int i=0;i<n;i++)
    {
    scanf("%d",&arr[i]);
    }
    printf("\n");
    radixsort();
    printf("elements after sorting are: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
return 0;
   
}
int getmax()
{
    int max=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        max=arr[i];
    }
    return max;
}
void radixsort()
{
    int max=getmax();
    int exp;
    for(exp=1;max/exp>0;exp*=10)
    {
        countingsort(exp);
    }
}
void countingsort(int exp)
{
    //first we have to count number of digits hence we make count array
    int count[10]={0};
    int output[n];
    for(int i=0;i<n;i++)
    {
        int digits=(arr[i]/exp)%10;
        count[digits]++;//here we have found frequency of all digits
    }
    //now lets find prefix sum
    for(int i=1;i<10;i++)
    {
        count[i]=count[i]+count[i-1];//here prefix sum array is formed
    }
    
    for(int i=n-1;i>=0;i--)
    {
        int digit=(arr[i]/exp)%10;
        output[count[digit]-1]=arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i]; // Update the original array with sorted elements
    }
}