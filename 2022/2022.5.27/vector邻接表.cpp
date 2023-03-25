#include <iostream>
#include <cstdio>
#include <vector>
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
int v[10005];
int w[10005];
vector<int>a[10005];
int now=0;
inline void add(int u1,int v1,int w1){
	now++;
	v[now]=v1;
	w[now]=w1;
	a[u1].push_back(now);
}
int n,m;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();m=read();int _min=0x3f3f3f3f;
	for(int i=1;i<=m;i++){
		int a=read(),b,c;
		b=read();
		c=read();
		add(a,b,c);
		_min=min(_min,c);
	}
	cout<<_min<<endl; 
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].size();j++){
			if(w[a[i][j]]==_min){
				cout<<i<<' '<<v[a[i][j]]<<' '<<w[a[i][j]]<<endl;
			}
		}
	}
	
	return 0;
}
/*
Anything about this program:
Type:
	Note 
Description:
	´æÓÐÏòÍ¼ 
Example:
	1:
		In:
			5 6
			1 2 1
			2 3 1
			2 5 1
			3 5 2
			5 4 4
			5 1 6
		Out:
			1
			1 2 1
			2 3 1
			2 5 1
More:

*/

