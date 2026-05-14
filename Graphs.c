//Ajacency Matrix
#include<stdio.h>
#define Max 100
int main()
{
    int n,e; //n=Nodes, e=Edges
    int adj[Max][Max]={0}; //Initialize everything to 0
    printf("Enter the no.of vertices:");
    scanf("%d",&n);

    printf("Enter the no.of edges:");
    scanf("%d",&e);

    //Main function code
    for(int i=0;i<e;i++)
    {
        int u,v;
        printf("Enter the edge-1 and edge-2, where they are connected:");
        scanf("%d,%d",&u,&v);
        adj[u][v]=1;
        adj[v][u]=1;
    }

    //To print the matrix 
    for(int i=0;i<n;i++)
    {
        for(int j=0; j<n; j++)  
        {
            printf("%d",adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}