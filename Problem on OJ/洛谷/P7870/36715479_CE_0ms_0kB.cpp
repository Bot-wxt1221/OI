#include <iostream>
#include <cstdio>
#include <stack>
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
class node{
	public:
		int l,r;
};
stack<node>d;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		int a=read();
		if(a==1){
			node temp;
			temp.l=read();
			temp.r=read();
			d.push(temp);
		}else{
			int k=read();
			int ans=0;
			node temp=d.top();
			d.pop();
			while(k>0){
				if(temp.r-temp.l+1<=k){
					k-=(temp.r-temp.l+1);
					ans+=((temp.l+temp.r)*(temp.r-temp.l+1)/2);
				}else{
					int last=temp.r-k+1;
					ans+=((temp.r+last)*(k)/2);
					node tem;
					tem.l=temp.l;
					tem.r=last-1;
					d.push(tem);
					k=0;
				}
				if(d.size()>0)
					temp=d.top();
					d.pop();
				}
			}
			d.push(temp);
			printf("%lld\n",ans);
		}
	}
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

