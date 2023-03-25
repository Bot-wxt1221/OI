//g++  7.4.0

#include <iostream>
#include <cstring>
#include <cstdio>
#define int long long
using namespace std;
int a[1000005];
int mex[1000005];
int vis[1000005];
int pos[1000005];
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
signed main()
{
    int n;
    n=read();
    int ans=0;
    for(int i=1;i<=n;i++){
    	a[i]=read();
	}
	int t=0;
	for(int i=1;i<=n;i++){
		int temp;
		temp=read();
		a[i]=max(a[i],temp);
		vis[a[i]]=1;
		while(vis[t]){
			t++;
		}
		mex[i]=t;
		ans=max(ans,i-mex[i]);
	}
	memset(vis,0,sizeof(vis));
	for(int i=n;i>=1;i--){
		if(vis[a[i]]!=0){
			pos[i]=vis[a[i]];
		}else{
			pos[i]=n+1;
		}
		vis[a[i]]=i;
	}
	for(int i=2;i<=n;i++){
		int to=pos[i]-1;
		ans=max(ans,to-i+1-a[i]);
	}
	printf("%lld",ans);
    return 0;
}