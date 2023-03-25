#include <iostream>
#include <cstdio>
#include <cmath>
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
inline int dist(int x1,int y1,int z1,int x2,int y2,int z2){
	return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))+((z1-z2)*(z1-z2)));
}
int fa[1005];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool win;
bool vised[1005];
int a[1005],b[1005],c[1005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read();
	while(T--){
		vector<int>under;
		vector<int>up;
		int n=read(),h,r;
		h=read();
		r=read();
		for(int i=1;i<=n;i++){
			fa[i]=i;
			a[i]=read();
			b[i]=read();
			c[i]=read();
			if(c[i]<=(r*2)){
				under.push_back(i);
			}
			if(c[i]>=(h-r*2)){
				up.push_back(i);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dist(a[i],b[i],c[i],a[j],b[j],c[j])<=r*2){
					fa[find(i)]=find(j);
				}
			}
		}
		bool konw=1;
		for(int i=0;i<under.size()&&konw;i++){
			for(int j=0;j<up.size()&&konw;j++){
				if(find(under[i])==find(up[i])){
					printf("Yes\n");
					konw=0;
				}
			}
		}
		if(konw==1){
			printf("No\n");
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

