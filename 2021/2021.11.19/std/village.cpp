#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf=0x3f3f3f3f;

int n,m,s,t;
int f[500+10];

struct edge
{
     int u,v,w;
     bool operator < (const edge &a)const 
     {
          return w>a.w;
     }
}e[5000+10];

int find(int x)
{
    if(f[x]==x)return x;
    return f[x]=find(f[x]);
}

int gcd(int a,int b)
{
    int r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

void init()
{
     freopen("village.in","r",stdin);
     freopen("village.out","w",stdout);
}

void readdata()
{
     scanf("%d%d",&n,&m);
     for(int i=1;i<=m;i++)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
     scanf("%d%d",&s,&t);
}

void work()
{
     int maxw,minw;
     double ans=inf;
     sort(e+1,e+m+1);
     for(int i=1;i<=m;i++)//对于每一条最大边
     {
         for(int j=1;j<=n;j++)f[j]=j;//记得每次都要初始化f[i]
         for(int k=i;k<=m;k++)//枚举最小边
         {
             int fu=find(e[k].u);
             int fv=find(e[k].v);
             if(fu!=fv)f[fu]=fv;
             if(find(s)==find(e[i].u)&&find(t)==find(e[i].u))//如果能从s到t
             {
                  if(e[i].w*1.0/e[k].w<ans)//需要跟新ans
                  {
                      maxw=e[i].w;
                      minw=e[k].w;
                      ans=maxw*1.0/minw;
                  }
                  break;
             }
         }
     }
     if(ans==inf)printf("Impossible\n");
     else//输出最简分数
     {
         int temp=gcd(maxw,minw);
         maxw/=temp;
         minw/=temp;
         printf("%d",maxw);
         if(minw!=1)printf("/%d",minw);
         printf("\n");
     }
     
}

int main()
{
    init();
    readdata();
    work();
    return 0;
}
