#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
priority_queue<int>a;
signed main(){
	freopen("snow.in","r",stdin);
	freopen("snow.out","w",stdout);
	int n=read(),k,now=0;
	k=read();
	bool more=0;
	for(int i=1;i<=n;i++){
		int temp=read();
		if(temp>0){
			now+=temp;
		}else{
			if(now>0){
				a.push(now);
				if(a.size()>k){
					a.pop();
					more=1;
				}
				now=0;
			}
			
		}
	}
	if(now>0){
		a.push(now);
		if(a.size()>k){
			a.pop();
			more=1;
		}
		now=0;
	}
	int total=0;
	int m=(more==1?k:a.size());
	for(int i=1;i<=m;i++){
		total+=a.top();
		a.pop();
	} 
	printf("%lld",total);
	return 0;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/


