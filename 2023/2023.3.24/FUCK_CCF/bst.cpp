#include <iostream>
#include <cstdio>
#include <stack>
inline int read();

std::stack<int>st;
int l[300005];
int dep[300005];
int r[300005];
int a[300005];
int x[300005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("bst.in","r",stdin);
	freopen("bst.out","w",stdout);
	#endif
    int n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		x[a[i]]=i;
	}
	st.push(0);
	for(int i=1;i<=n;i++){
		while(x[i]<st.top()&&st.size()>0){
			st.pop();
		}
		l[i]=a[st.top()];
		st.push(x[i]);
	}
	st=std::stack<int>();
	st.push(0);
	for(int i=n;i>=1;i--){
		while(x[i]<st.top()&&st.size()>0){
			st.pop();
		}
		r[i]=a[st.top()];
		st.push(x[i]);
	}
	printf("%d ",0);
	int ans=0;
	for(int i=2;i<=n;i++){
		dep[a[i]]=std::max(dep[l[a[i]]],dep[r[a[i]]])+1;
		ans+=dep[a[i]];
		printf("%d ",ans);
	}
	return 0;
}
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


