//g++  7.4.0

#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define int long long
using namespace std;
int a[1000005];
vector<int>to[1000005];
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
    to[0].push_back(0); 
    for(int i=1;i<=n;i++){
    	a[i]=read();
    	to[i].push_back(0);
	}
//	int t=0;
	for(int i=1;i<=n;i++){
		int temp;
		temp=read();
		if(a[i]==temp){
			to[a[i]].push_back(i);
		}
	}
	for(int i=0;i<=n;i++){
		to[i].push_back(n+1);
	}
	for(int i=0;i<=n;i++){
		for(int j=1;j<to[i].size();j++){
			ans=max(ans,to[i][j]-1-to[i][j-1]-i);
		}
	}
	printf("%lld",ans);
    return 0;
}