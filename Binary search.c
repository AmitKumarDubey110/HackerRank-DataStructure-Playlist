//binary search

#include <stdio.h>
#include <conio.h>

int linearsearch(int arr[],int size,int element);

int main()
{

    int arr[100], element, size,i;

    printf("enter the size of array\n");
    scanf("%d", &size);
    printf("enter the element of array\n"); 
    scanf("%d", &element);
    
    printf("enter the number\n");
    for ( i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    } 

    int k=linearsearch(arr,size,element);
    
printf("%d is find at index number  %d",element,k);

}

int linearsearch(int arr[],int size,int element)

{
    int low,high,mid;
    low=0;
    high=arr[size-1];
    while (low<=high)
    {
        mid=(low+high)/2;
        if (arr[mid]==element)
        {
            return mid;

        }
        else if (arr[mid]<element)
        {
            low=(mid+1);
        }
        else{
            high=mid-1;
        }
        
    }
}
