#include<stdio.h>
#define Max 10
int graph[Max][Max]={
    {0,1,1,0,0},
    {1,0,0,1,0},
    {1,0,0,0,1},
    {0,1,0,0,0},
    {0,0,1,0,0},
};

int visited[Max]={}
int queue[Max];
int front=-1,rear=-1;
int n=5;

int enqueue(int x)
{
    if(front==-1)
    {
        front=1;
    }
    queue[++rear]=x;
}

int dequeue()
{
    if(front>rear||front==-1)
    {
        return 0;
    }
    int value=queue[rear];
    rear--;
    return value;
}

void BFS(int start)
{
    enqueue(start);
    visited[start]=1;
    while(front>=rear)
    {
        int node=dequeue();
        printf("%d",node);
        for(int i=0;i<n;i++) //Go till the n=5, n is the no.of verticles it is there for the traversing through the column part of the graph
        {
            if(graph[node][i]==1 && visited[i]==0) //Checking condition, whether there exists a edge and whether the in the visited array, it is 0(i.e., not visited)
            {
                enqueue(i);
                visited[i]=1;
            }
        }
    }
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include<stdio.h>
#define Max 10
int graph[Max][Max]={
    {0,1,1,0,0},
    {1,0,0,1,0},
    {1,0,0,0,1},
    {0,1,0,0,0},
    {0,0,1,0,0},
};

int visited[Max]={}
int stack[Max];
int top=-1;
int n=5;

int push(int x)
{
    if(top==Max-1)
    {
        return 0;
    }
    stack[++top]=x;
}

int pop()
{
    if(top==-1)
    {
        return 0;
    }
    int value=stack[top];
    top--;
    return value;
}

void DFS(int start)
{
    push(start);
    visited[start]=1;
    printf("DFS traversal starts from:%d\n",start);

    while(top==-1)
    {
        int node=stack[top];
        int found=0;

        for(int i=0;i<n;i++) //Go till the n=5, n is the no.of verticles it is there for the traversing through the column part of the graph
        {
            if(graph[node][i]==1 && visited[i]==0) //Checking condition, whether there exists a edge and whether the in the visited array, it is 0(i.e., not visited)
            {
                push(i);
                visited[i]=1;
                printf("%d",i);
                found=1;
                break;
            }
        }

        if(found==0)
        {
            pop();
        }
    }
}

int main()
{
    DFS(0)
    return 0;
}