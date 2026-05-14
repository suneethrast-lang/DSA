#include <stdio.h>

void merge(int a[], int left, int mid, int right)
{
    int i=left;      
    int j=mid + 1;   
    int k=left;      
    int temp[100];     
   
    while(i<=mid && j<=right)
    {
        if(a[i]<=a[j])
        {
            temp[k] = a[i];
            i++,k++;
        }
        else
        {
            temp[k] = a[j];
            j++,k++;
        }
    }

    // Copy sorted elements back to original array
    while(i <= mid)
    {
        temp[k] = a[i];
        i++,k++;
    }
    
    // Copy sorted elements back to original array
    while(j <= right)
    {
        temp[k] = a[j];
        j++,k++;
    }

    // Copy back sorted elements and print it 
    printf("Sorted array\n");
    for(int i = left; i <= right; i++)
    {
        a[i] = temp[i];
        printf("%d\t",temp[i]);
    }
}


void mergeSort(int a[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int main()
{
    int a[6] = {70,30,50,10};
    int n = 4;

    printf("Unsorted array\n");
    for(int i=0;i<6;i++)
    {
        printf("%d\t",a[i]);
    }
    mergeSort(a,0,n-1);
    return 0;
}