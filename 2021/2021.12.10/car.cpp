#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int cnt=0,n,m;
const int disa[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//0 right 1 up 2 right 3 down 
bool vised[10][10][4];
void dfs(int dis,int x,int y);
int main(){
	freopen("car.in","r",stdin);
	freopen("car.out","w",stdout);
	cin>>m>>n;
	dfs(0,1,1);
	cout<<cnt;
	return 0;
}
void dfs(int dis,int x,int y){
	if(x==n+1&&y==m+1){
		cnt++;
		return;
	}
	if(x>n+1||y>m+1||x<=0||y<=0){
		return;
	}
	for(int i=0;i<=1;i++){
		int a=(dis+i)%4;

		if(vised[x+disa[a][0]][y+disa[a][1]][a]==1||vised[x+disa[a][0]][y+disa[a][1]][(a+2)%4]==1){//²»ÖØ¸´×ß 
			continue;
		}
		vised[x+disa[a][0]][y+disa[a][1]][a]=1;
		vised[x+disa[a][0]][y+disa[a][1]][(a+2)%4]=1;
		dfs(a,x+disa[a][0],y+disa[a][1]);
		vised[x+disa[a][0]][y+disa[a][1]][a]=0;
		vised[x+disa[a][0]][y+disa[a][1]][(a+2)%4]=0;
	}
	return;
}
