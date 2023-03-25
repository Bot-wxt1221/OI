#include <iostream>
#include <cstdio>
#include <cstring>
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
bool map[55][55][5];
int pre[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m;
int ans=0;
bool vised[105][105];
void dfs(int x,int y);
int main(){
//	freopen("1.in","r",stdin);
//	freopen("castle_A.out","w",stdout);
	m=read();
	n=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int r;
			scanf("%d",&r);
			if(r>=8){
				r-=8;
				map[i][j][2]=1;
			}
			if(r>=4){
				r-=4;
				map[i][j][0]=1;
			}
			if(r>=2){
				r-=2;
				map[i][j][3]=1;
			}
			if(r>=1){
				r-=1;
				map[i][j][1]=1;
			}
		}
	}
	int total=0,_max=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(vised[i][j]==0){
				total++;
				ans=0;
				vised[i][j]=1;
				dfs(i,j);
				_max=max(_max,ans);
			}
		}
	}
	printf("%d\n%d",total,_max);
	int x,y;char to;
	for(int j=1;j<=m;j++){
		for(int i=n;i>=1;i--){
			if(map[i][j][3]){
				memset(vised,0,sizeof(vised));
				map[i][j][3]=0;
				map[i-1][j][2]=0;
				for(int ai=1;ai<=n;ai++){
					for(int aj=1;aj<=m;aj++){
						if(vised[ai][aj]==0){
							ans=0;
							vised[ai][aj]=1;
							dfs(ai,aj);
							if(ans>_max){
								x=i;
								y=j;
								to='N';
								_max=ans;
							}
						}
					}
				}
				map[i][j][3]=1;
				map[i-1][j][2]=1;
			}else if(map[i][j][0]){
				memset(vised,0,sizeof(vised));
				map[i][j][0]=0;
				map[i][j+1][1]=0;
				for(int ai=1;ai<=n;ai++){
					for(int aj=1;aj<=m;aj++){
						if(vised[ai][aj]==0){
							ans=0;
							vised[ai][aj]=1;
							dfs(ai,aj);
							if(ans>_max){
								x=i;
								y=j;
								to='E';
								_max=ans;
							}
						}
					}
				}
				map[i][j][0]=1;
				map[i][j+1][1]=1;
			}
			
		}
	}
	cout<<endl<<_max<<endl;
	cout<<x<<' '<<y<<' '<<to;
	return 0;
}
void dfs(int x,int y){
	ans++;
	for(int i=0;i<4;i++){
		if(map[x][y][i]==1){
			continue;
		}
		int nx=x+pre[i][0],ny=y+pre[i][1];
		if(vised[nx][ny]||nx<=0||ny<=0||nx>n||ny>m){
			continue;
		}
		vised[nx][ny]=1;
		dfs(nx,ny);
	}
	return ;
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

