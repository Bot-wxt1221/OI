#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
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
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	int n;
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
while(scanf("%lld",&n)!=EOF){
	int a[55];
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1,cmp);
	int l=1,r=1;
	int ans=0;
	int q1=1,q2=1;
	int now=0;
	bool aa;
	for(int i=1;i<=n;i++){
		if(a[i]==a[l]){
			r=i;
			aa=1;
		}else{
			aa=1;
			now++;
			if(now<=2){
				ans+=r-l+1;
			}else{
				int temp=q1+q2;
				ans+=temp*(r-l+1);
				q2=q1;
				q1=temp;
			}
			l=r=i;
		}
	}
	if(aa){
		now++;
			if(now<=2){
				ans+=r-l+1;
			}else{
				int temp=q1+q2;
				ans+=temp*(r-l+1);
				q2=q1;
				q1=temp;
			}
	}
	printf("%lld\n",ans);
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


