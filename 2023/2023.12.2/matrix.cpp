#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
char temp[100005][105];
int sum[100005][105];
int siz[100005];
int x1[100005];
int yy1[100005];
int x2[100005];
int ans[100005];
int y2[100005];
inline int getsum(int x,int y,int siz){
	if(x==0||y==0){
		return 0;
	}
	return ((int)(y/siz))*sum[x][siz]+sum[x][y%siz];
}

signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	#endif
    int r=read();
    int c=read();
	int maxsiz=0;
    for(int i=1;i<=r;i++){
		scanf("%s",temp[i]+1);
		siz[i]=strlen(temp[i]+1);
		// temp[i][0]=temp[i][siz[i]];
		maxsiz=std::max(maxsiz,siz[i]);
	}
	int q=read();
	for(int i=1;i<=q;i++){
		x1[i]=read();
		yy1[i]=read();
		x2[i]=read();
		y2[i]=read();
	}
	for(int ii=1;ii<=100;ii++){
		for(int i=1;i<=r;i++){
			for(int j=1;j<=ii;j++){
				if(siz[i]==ii){
					sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+temp[i][j]-'0';
				}else{
					sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
				}
			}
		}
		for(int i=1;i<=q;i++){
			ans[i]+=getsum(x2[i],y2[i],ii)-getsum(x1[i]-1,y2[i],ii)-getsum(x2[i],yy1[i]-1,ii)+getsum(x1[i]-1,yy1[i]-1,ii);
		}
	}
	for(int i=1;i<=q;i++){
		printf("%d\n",ans[i]);
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


