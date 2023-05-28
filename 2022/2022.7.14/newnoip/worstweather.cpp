#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
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
int f[500005][100];
int to[500005];
int b[500005];
int query(int l, int r) {
	if(l>r){
		return -1E9;
	}
    int p = log2(r-l+1);
    return max(f[l][p], f[r - (1 << p) + 1][p]);
}
int n;
signed main(){
	freopen("worstweather.in","r",stdin);
	freopen("worstweather.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		int y=read();
		int r=read();
		f[i][0]=r;
		to[i]=y;
		b[i]=r;
	}
	for(int k=1;k<=log2(n);k++){
		for(int i=1;i<=n;i++){
			f[i][k]=max(f[i][k-1],f[i+(1<<(k-1))][k-1]);
		}
	}
	int m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		int fx=lower_bound(to+1,to+n+1,x)-to;
		int fy=lower_bound(to+1,to+n+1,y)-to;
		if(to[fx]!=x&&to[fy]!=y){
			printf("maybe\n");
		}else if(to[fx]==x&&to[fy]==y){
			if(b[fx]<b[fy]){
				printf("false\n");
			}else{
				int t=query(fx+1,fy-1);
				if(t<b[fy]){
					if(fy-fx==y-x){
						printf("true\n");
					}else{
						printf("maybe\n");
					}
				}else{
					printf("false\n");
				}
			}
		}
		else if(to[fx]==x&&to[fy]!=y){
			int t=query(fx+1,fy-1);
			if(t>=b[fx]){
				printf("false\n");
			}else{
				printf("maybe\n");
			}
		}else{
			int t=query(fx,fy-1);
			if(t>=b[fy]){
				printf("false\n");
			}else{
				printf("maybe\n");
		}
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



