#include<stdio.h>

int q[8];//code for bfs and dfs
int vis[8];
int front=-1;
int rear=-1;
int adj[8][8] = {
    0, 1, 1, 1, 0, 0, 0, 0,
    1, 0, 0, 0, 1, 1, 0, 0,
    1, 0, 0, 0, 0, 0, 1, 0,
    1, 0, 0, 0, 0, 0, 0, 1,
    0, 1, 0, 0, 0, 0, 0, 1,
    0, 1, 0, 0, 0, 0, 0, 1,
    0, 0, 1, 0, 0, 0, 0, 1,
    0, 0, 0, 1, 1, 1, 1, 0

};//so we basically have elements in graph as 0,1,2,3,4,5,6,7


void dfs(int s);//defining the function prototype
void bfs(int s);
void enqueue(int item);
int dequeue();

int main()
{
    int s;
    int n;
    printf("enter source of the matrix: ");
    scanf("%d",&s); 

    
    do
    {
        printf("enter 1 for bfs:\nenter 2 for dfs:\nenter 3 for exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            for(int i=0;i<8;i++)
            {
             vis[i]=0;//initializing all visited to 0 first
            }
            bfs(s);
            break;
            case 2:
            for(int i=0;i<8;i++)
            {
            vis[i]=0;//initializing all visited to 0 first
            }
            dfs(s);
            break;
            case 3:
            printf("exiting the code....\n");
            break;
        }
    } while (n!=3);
    
    return 0;
}
void bfs(int s)
{

  enqueue(s);
  int p=dequeue();
  if(p!=-1)
  {
    printf("%d ",p);
  }
  vis[p]=1;

  while(p!=-1)
  {

  for(int j=0;j<8;j++)
  {
        if(adj[p][j]==1 && vis[j]==0)
        {
            vis[j]=1;
            printf("%d ",j);
            enqueue(j);
        }  
  }
  p=dequeue();
  }

  //if some nodes are untouched we shall touch them now 
  for(int i=0;i<8;i++)
  {
    if(vis[i]==0)
    bfs(i);
  }

}

void enqueue(int item)
{
 if(rear==7)
 {
 printf(" bfs completed");
 }
 if(front ==-1 && rear==-1)
 {
    front++;
    rear++;
    q[rear]=item;
 }
 else
 {
    q[++rear]=item;
 }
}

int dequeue()
{
 if(front==-1 || front>rear)
 {
    return -1;
 }
 int remove=q[front];
 front++;
 return remove;
}


void dfs(int s)
{
printf("%d ",s);//print the source index first
vis[s]=1;

for(int i=0;i<8;i++)
{
    if(adj[s][i]==1 && vis[i]==0)
    {
        vis[i]=1;
        dfs(i);
    }
}

}