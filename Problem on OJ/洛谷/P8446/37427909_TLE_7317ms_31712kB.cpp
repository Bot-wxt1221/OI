//g++  7.4.0

#include <iostream>
#include <cstring>
#include <cstdio>
#define int long long
using namespace std;
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
int a[4000005];
signed main()
{
    int n=read();
	bool pianfen=0;
    for(int i=1;i<=n;i++){
    	a[i]=read();
    	if(a[i]!=a[i-1]){
    		pianfen=1;
		}
	}
	if(pianfen==0){
		printf("%lld",-1);
	}else{
		int ans=-10000;
		for(int i=1;i<=n;i++){
			int mx=a[i],mi=a[i];
			for(int j=i;j<=n;j++){
				mx=max(mx,a[j]);
				mi=min(mi,a[j]);
				ans=max(ans,mx-mi-(j-i+1));
			}
		}
		printf("%lld",ans);
	}
    return 0;
}