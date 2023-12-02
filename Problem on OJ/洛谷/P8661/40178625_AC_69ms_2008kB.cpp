#include <iostream>
#include <algorithm>
#include <cstdio>
inline int read();
class node{
	public:
		int ts,id;
		node(){
			ts=id=0;
		}
}a[100005];
bool yes[100005];
bool operator < (node a,node b){
	return a.id==b.id?a.ts<b.ts:a.id<b.id;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	#endif
    register int n=read();
    register int d=read();
	d--;
    register int k=read();
	for(register int i=1;i<=n;i++){
		a[i].ts=read();
		a[i].id=read();
	}
	std::stable_sort(a+1,a+n+1);
	register int l=0,r=0,have=0;
	a[0].id=-1;
	for(register int i=1;i<=n;i++){
		if(a[i].id!=a[i-1].id){
			l=i;
			r=i;
			have=1;
			if(k==1){
				yes[a[i].id]=1;
			}
		}else{
			r++;
			have++;
			while(a[r].ts-a[l].ts>d){
				l++;
				have--;
			}
			if(have>=k){
				yes[a[r].id]=1;
			}
		}
	}
	for(int i=0;i<=100000;i++){
		if(yes[i]){
			printf("%d\n",i);
		}
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

