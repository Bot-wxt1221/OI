#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n;
int a[80000+10],see[80000+10],sf[80000+10];//sf[i]表示第一个比i高的人 

void init()
{
     freopen("eat.in","r",stdin);
     freopen("eat.out","w",stdout);
}

void work()
{
     scanf("%d",&n);
     for(int i=1;i<=n;i++)scanf("%d",&a[i]);
     for(int i=n;i>=1;i--)
     {
         int j=i+1;
         while(j<=n&&a[i]>a[j])j=sf[j];
         //如果i能看到j，那么就一定能看到j能看到的所有人，则直接检查sf[j] 
         sf[i]=j;//跟新sf[i] 
         see[i]=j-i-1;
     }
     long long ans=0;//注意ans可能会爆int 
     for(int i=1;i<=n;i++)ans+=(long long)see[i];
     printf("%I64d\n",ans);
}

int main()
{
    init();
    work();
    return 0;
}
