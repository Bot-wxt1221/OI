#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int maxn=1000+10;

int n,m,x,k=1,ans=0;
int head[maxn];
int way[maxn]={0};
int dis[maxn],vis[maxn]={0};

struct edge
{
    int v,w,next;
}e[100000+10];

void adde(int u,int v,int w)
{
     e[k].v=v;
     e[k].w=w;
     e[k].next=head[u];
     head[u]=k++;
}

void init()
{
     freopen("sword.in","r",stdin);
     freopen("sword.out","w",stdout);
}



int readdata()
{
    memset(head,-1,sizeof(head));
    int a,b,c;
    scanf("%d%d%d",&n,&m,&x);
    for(int i=1;i<=m;i++)
    {        
        scanf("%d%d%d",&a,&b,&c);
        adde(a,b,c);
    }
}

void spfa(int x)
{
     memset(dis,0x3f3f3f3f,sizeof(dis));
     queue<int >q;
     dis[x]=0;
     q.push(x);
     vis[x]=1;
     while(!q.empty())
     {
         int u=q.front();
         q.pop();
         vis[u]=0;
         for(int i=head[u];i!=-1;i=e[i].next)
         {
             int v=e[i].v;
             if(dis[v]>dis[u]+e[i].w)
             {
                  dis[v]=dis[u]+e[i].w;
                  if(!vis[v])
                  {
                      q.push(v);
                      vis[v]=1;
                  }
             }
         }
     }
}


void work()
{
     spfa(x);
     for(int i=1;i<=n;i++)way[i]=dis[i];
     for(int i=1;i<=n;i++)
     {
         if(i!=x)
         {
             spfa(i);
             way[i]+=dis[x];
         }
     }
     for(int i=1;i<=n;i++)
     {
          if(ans<way[i])ans=way[i];
     }
     printf("%d\n",ans);
}

int main()
{
    init();
    readdata();
    work();
    //while(1);
    return 0;
}
