#include<stdio.h>
int arr[7];
void quick(int low, int high); 

int main()
{
    printf("enter array elements\n");
    for(int i=0;i<7;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("array before sorting is  ");
    for(int i=0;i<7;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    quick(0,6);
    printf("array after sorting is  ");
    for(int i=0;i<7;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
void quick(int low,int high)
{
    int pivot=arr[low];//make our pivot the low element
    int i=low;
    int j=high;
    if(low>=high)return;
    while(i<j)
    {
        while(arr[i]<=pivot && i<=high)
        {
            i++;
        }
        //now i is an index that is higher than arr[low]
        while(arr[j]>pivot)
        {
            j--;
        }
        if(j>i)//if j is greater than i this means swap else if j crosses i and i is larger than j we can replace pivot with j also j is the partition
        {
            int t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        } 
    }
    int t=arr[low];
    arr[low]=arr[j];
    arr[j]=t;
    
    quick(low,j-1);
    quick(j+1,high);
 }


