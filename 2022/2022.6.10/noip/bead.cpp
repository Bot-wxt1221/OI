#include <iostream>
#include <cstdio>
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
class gra{
	public:
		int map[100][100];
		gra(int n);
		inline void add(int,int);
};
gra::gra(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			map[i][j]=0;
		}
	}
}
inline void gra::add(int x,int y){
	map[x][y]=1;
	map[y][x]=-1;
	return ;
}
int main(){
	freopen("bead.in","r",stdin);
	freopen("bead.out","w",stdout);
	int n,m;
	n=read();
	m=read();
	gra a(n);
	for(int i=1;i<=m;i++){
		int aa=read(),bb;
		bb=read();
		a.add(aa,bb);
	}
	int ans=0;
	for(int m=1;m<=n;m++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a.map[i][m]==a.map[m][j]&&a.map[i][m]!=0){
					a.map[i][j]=a.map[i][m];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		int big=0,sml=0;
		for(int j=1;j<=n;j++){
			if(a.map[i][j]==1){
				big++;
			}else if(a.map[i][j]==-1){
				sml++;
			}
		}
		if(big>=(n+1)/2){
			ans++;
		}else if(sml>=(n+1)/2){
			ans++;
		}
	}
	printf("%d",ans);
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


