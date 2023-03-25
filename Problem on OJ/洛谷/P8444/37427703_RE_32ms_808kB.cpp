//g++  7.4.0

#include <iostream>
#include <algorithm>
#include <cstdio>
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
using namespace std;
int a[100005];
int main()
{
    int n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    int w;
    w=read();
    sort(a+1,a+n+1);
    if(n==0||a[1]>w){
        printf("0");
        return 0;
    }
    int temp=upper_bound(a+1,a+n+1,w)-a-1;
    int more=a[temp];
    for(int i=1;i<temp;i++){
        more-=a[i];
        if(more<0){
            printf("%d",max(i-1,1));
            return 0;
        }
    }
    printf("%d",max(1,temp-1));
    return 0;
}