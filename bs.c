#include<stdio.h>
int arr[5];

int bs(int target);

int main()
{
int target;
printf("enter array elements in sorted order\n");
for(int i=0;i<5;i++)
{
scanf("%d",&arr[i]);
}
printf("enter number to be searched\n");
scanf("%d",&target);
int result=bs(target);
if(result==0)
printf("no element found\n");
else
{
printf("number found");
}

return 0;
}
int bs(int target)
{
    int start=0;
    int end=4;
    while(end>=start)
    {
        int mid=start+(end-start)/2;
        if(target==arr[mid])return 1;
        else if(target>arr[mid])
        {
            start=mid+1;
        }
        else if(target<arr[mid])
        {
            end=mid-1;
        }
    }
    return 0;

}