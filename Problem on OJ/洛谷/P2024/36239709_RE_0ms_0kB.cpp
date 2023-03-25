#include<cstdio>
int fa[5000005];
int n,k,ans;
int find(int x)
{
    if(x!=fa[x]) fa[x]=find(fa[x]);
    return fa[x];
}
int Union(int x,int y)
{
    int r1=find(fa[x]),r2=find(fa[y]);
    fa[r1]=r2;
}
int main()
{
    int x,y,z;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=3*n;++i) fa[i]=i; 
    for(int i=1;i<=k;++i) 
    {
        scanf("%d%d%d",&z,&x,&y);
        if(x>n||y>n) {ans++; continue;}
        if(z==1)
        {
            if(find(x+n)==find(y)||find(x+2*n)==find(y)) {ans++; continue;}
            Union(x,y); Union(x+n,y+n); Union(x+2*n,y+2*n);
        }
        else if(z==2)
        {
            if(x==y) {ans++; continue;}
            if(find(x)==find(y)||find(x+2*n)==find(y)) {ans++; continue;}
            Union(x,y+2*n); Union(x+n,y); Union(x+2*n,y+n);
        }
    }
    printf("%d\n",ans);
    return 0;
}