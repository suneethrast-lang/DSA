#include<stdio.h>
#define max 10
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
//Q-1
void mergeSort(int arr[],int left,int right)
{
    while(left<=right)
    {
        int mid=(left+right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

void merge(int arr[],int left, int mid, int right)
{
    int i=left, j=mid+1, k=left;
    int temp[100];
    while(i<=mid && j<=right)
    {
        if(arr[i]>=arr[j])
        {
            temp[k]=arr[j];
            j++, k++;
        }
        else
        {
            temp[k]=arr[i];
            i++, k++;
        }
    }

    while(j<=mid)
    {
        temp[k]=arr[j];
        j++, k++;
    }

    while(i<=mid)
    {
        temp[k]=arr[i];
        i++, k++;
    }
}

//Q-2,3
void *create_tree(struct node *root, int key)
{
    if(root==NULL)
    {
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->data=key;
        temp->left=NULL;
        temp->right=NULL;

        return temp;
    }
    else if(key>root->data)
    {
        root->right=create_tree(root->right,key);
    }
    else if(key<root->data)
    {
        root->left=create_tree(root->left,key);
    }
    else
    {
        return root;
    }

    return root;
}

void preorder(struct node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    printf("Preorder traversal\n");
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    printf("Inorder traversal\n");
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}

void postorder(struct node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    printf("Preorder traversal\n");
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}


//Q-4
void min_function(struct node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    else
    {
        while(root->left!=NULL)
        {
            root=root->left;
        }
    }
    return root;
}

struct node *deletion(struct node *root, int value)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(value>root->data)
    {
        root->right=deletion(root->right,key);
    }
    else if(value<root->data)
    {
        root->left=deletion(root->left,key);
    }
    else
    {
        struct node *temp=min_function(root->right);
        root->data=temp->data;
        temp->data=deletion(root->right,temp->data)
    }

    return root;
}

//Q-5
void binary_search(int arr[],int n, int value)
{
    int left=0;
    int right=n-1;
    while(left<=right)
    {
        int mid=(left+right)/2
        if(arr[mid]==value)
        {
            return value;
        }
        else if(arr[mid]>value)
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    return NULL;
}

//Q-6
int graph[max][max]=
{
    {0,1,1,0,0},
    {1,0,1,1,0},
    {1,1,0,0,1},
    {0,1,0,0,1},
    {0,0,1,1,0}
}

int visited={0};
int rear=front=-1;
int queue[max];

void enqueue(int value)
{
    if(rear==-1)
    {
        front=0;
    }
    rear++;
    queue[rear]=value;
}

void dequeue()
{
    if(front>rear||front==-1)
    {
        return 0;
    }
    int value=queue[front];
    front--;
    return value;
}

void BFS(int start)
{
    enqueue(start);
    visited[start]=1;
    while(front>=rear)
    {
        int value=dequeue()
        print("%d\t",value);
        for(int i=0;i<n;i++)
        {
            if(graph[start][i]==1 && visited[i]==0)
            {
                enqueue(i);
                visited[i]=1;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        printf("%d\t",queue[i]);
        a[i]=queue[i];
    }
}

int main()
{
    BFS(0);
    return 0;
}

//Q-7
int graph[max][max]=
{
    {0,1,1,0,0},
    {1,0,1,1,0},
    {1,1,0,0,1},
    {0,1,0,0,1},
    {0,0,1,1,0}
}

int visited={0};
int top=-1;
int stack[max];

void push(int value)
{
    if(rear==max-1)
    {
        return 0;
    }
    top++;
    stack[top]=value;
}

void pop()
{
    if(top==-1)
    {
        return 0;
    }
    int value=stack[front];
    front--;
    return value;
}

void DFS(int start)
{
    push(start);
    visited[start]=1;
    while(top!=-1)
    {
        int value=pop()
        int found=0
        for(int i=0;i<n;i++)
        {
            if(graph[start][i]==1 && visited[i]==0)
            {
                enqueue(i);
                visited[i]=1;
                printf("%d\t",i);
                found=1;
                break;
            }
        }

        if(found==0)
        {
            pop();
        }
    }

    for(int i=0;i<n;i++)
    {
        printf("%d\t",queue[i]);
        a[i]=queue[i];
    }
}

int main()
{
    DFS(0);
    return 0;
}

//Q-8
int main()
{
    int heap[10]={10,20,30,40,50,60};
    int size=6;
    int value;
    printf('Enter the value::');
    scanf("%d",value);

    printf("Before adding\n");
    for(int i=0;i<size;i++)
    {
        printf("%d\t",heap[i]);
    }

    heap[size]=value;
    int index=size;
    size++;

    printf("after adding\n");
    for(int i=0;i<size;i++)
    {
        printf("%d\t",heap[i]);
    }

    while(index>0)
    {
        int par=(index-1)/2;
        if(heap[index]<heap[par]) //change the symbol
        {
            int temp=heap[index]
            heap[index]=heap[par]
            heap[par]=temp;

            index=par;
        }
        else
        {
            break;
        }
    }

    printf("after adding and sorting\n");
    for(int i=0;i<size;i++)
    {
        printf("%d\t",heap[i]);
    }
}

//Q-9
int main()
{
    int heap[10]={90,70,60,40,50,30};
    int size=6;
    int value;
    printf('Enter the value::');
    scanf("%d",value);

    printf("Before adding\n");
    for(int i=0;i<size;i++)
    {
        printf("%d\t",heap[i]);
    }

    heap[size]=value;
    int index=size;
    size++;

    printf("After adding\n");
    for(int i=0;i<size;i++)
    {
        printf("%d\t",heap[i]);
    }

    while(index>0)
    {
        int par=(index-1)/2;
        if(heap[index]>heap[par]) //change the symbol
        {
            int temp=heap[index]
            heap[index]=heap[par]
            heap[par]=temp;

            index=par;
        }
        else
        {
            break;
        }
    }

    printf("After adding and sorting\n");
    for(int i=0;i<size;i++)
    {
        printf("%d\t",heap[i]);
    }
}

//Q-10
int hashtable[max];
void init()
{
    for(int i=0;i<max;i++)
    {
        hashtable[i]=-1
    }
}
int hashfunction(int value)
{
    return value%max;
}

int insert(int key)
{
    int value=hashfunction(key);
    while(hashtable[value]!=-1)
    {
        value=(value+1)%size;
    }
    hashtable[value]=key;
}