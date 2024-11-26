#include<stdio.h>
int arr[7];
#define n 7
int calculate_fibo(int target);
int main()//here n=7
{
    int target;
    printf("enter array elements\n");
    for(int i=0;i<7;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter number to be searched\n");
    scanf("%d",&target);
    int result=calculate_fibo(target);
    if(result==-1)
    printf("not found\n");
    else
    {
        printf("fount at index %d ",result);
    }
    return 0;

}
int calculate_fibo(int target)
{
    int fib2=0;
    int fib1=1;
    int fib=fib1+fib2;
    int offset=-1;
    int index=0;

   while(fib<n)//find least number greater than or equal to length of array 
   {
    fib2=fib1;
    fib1=fib;
    fib=fib1+fib2;
   }
   while(fib>1)
   {
    //we have to find minimum of offset+fib2 and n-1 that is 6 therefore
     index=(offset+fib2)>n-1?n-1:offset+fib2;
   //cuz elimination toh n-1 se badha nai ho sakta na

   /*dekho order kuch aisa hai

   left mei fibo2 aata hai and right mei fibo1 aata hai 
   toh agar target badha hua then left walo ko hatana pdega 
   therefore fibo 2 ko hatana padega therefore we move only by one
   else by 2

   */
    if(target>arr[index])//eliminate the left therefore fib2 eliminated
    {
     offset=index;//ye left ke elements eliminated
     fib=fib1;
     fib1=fib2;
     fib2=fib-fib1;
    }
    else if(target<arr[index])//no point of updating offset 
    {
        fib=fib2;//fib 1 eliminated
        fib1=fib1-fib2;
        fib2=fib-fib1;
    }
    else 
    {
        return index;
    }

   }
    if(fib1==1 && arr[offset+1]==target){return arr[offset+1];}
    return -1;
}