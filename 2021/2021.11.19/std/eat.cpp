#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n;
int a[80000+10],see[80000+10],sf[80000+10];//sf[i]��ʾ��һ����i�ߵ��� 

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
         //���i�ܿ���j����ô��һ���ܿ���j�ܿ����������ˣ���ֱ�Ӽ��sf[j] 
         sf[i]=j;//����sf[i] 
         see[i]=j-i-1;
     }
     long long ans=0;//ע��ans���ܻᱬint 
     for(int i=1;i<=n;i++)ans+=(long long)see[i];
     printf("%I64d\n",ans);
}

int main()
{
    init();
    work();
    return 0;
}
