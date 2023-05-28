#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
//using namespace std;  //使用会导致编译失败因为<cmath>
void f(int n, long long m, long long &x, long long &y)
{
    if(n == 0)    //边界
        return ;
    long long k = pow(2, n-1), l;
    for(l=0;l<4;l++)
        if((l+1)*k*k>=m)break;  //查找递归上一等级的区域
    f(n-1,m-(l*k*k),x,y);   //递归
    long long ax=x,ay=y;    //提前定义会错误
    switch(l)
    {
        case 0:x=ay;y=ax;break;
        case 1:y+=k;break;  
        case 2:x+=k;y+=k;break;
        case 3:x=ay;y=ax;x=k-x-1;y=k-y-1;x+=k;break;
    }
    return ;
}
int main()
{
    freopen("stupid.in","r",stdin);
    freopen("stupid.out","w",stdout);
	long long x1,y1,x2,y2,s,d;
    int L,N;
    scanf("%d",&L);
    for(int i=1;i<=L;i++)
    {
        scanf("%d %lld %lld",&N,&s,&d);
        x1=y1=x2=y2=0;
        f(N,s,x1,y1);
        f(N,d,x2,y2);
        long long ii=round(sqrt(pow((x1-x2)*10,2)+pow((y1-y2)*10,2)));
        printf("%lld\n",ii);
    }
}
