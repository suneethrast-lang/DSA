#include<stdio.h>
#define size 10

int hashtable[size][size];
void intialize()
{
    for(int i=0;i<size;i++)
    {
        hashtable[i]=-1;
    }
}
int main()
{
    int heap[10]={90,70,60,50,40};
    int size=5;
    int newElement=100;

    printf("OG Heap\n");
    for(int i=0;i<size;i++)
    {
        printf("%d\t",heap[i]);
    }

    heap[size]=newElement;
    int index=size;
    size++;

    printf("Added Heap\n");
    for(int i=0;i<size;i++)
    {
        printf("%d\t",heap[i]);
    }

    while(index>0)
    {
        int par=(index-1)/2;

        if(heap[index]>heap[par])
        {
            int temp=heap[index];
            heap[index]=heap[par];
            heap[par]=temp;

            index=par;
        }
        else
        {
            break;
        }
    }

    printf("Changed Heap\n");
    for(int i=0;i<size;i++)
    {
        printf("%d\t",heap[i]);
    }

    return 0;
}

int hashfunction(int key)
{
    return key%size;
}

void insert(int key)
{
    int index=hashfunction(int key);
    while(hashtable[index]!=-1)
    {
        index=(index+1)%size;
    }
    hashtable[index]=key;
}

int main()
{
    
}