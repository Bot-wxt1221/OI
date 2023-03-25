#include <iostream>
#include <cstdio>
using namespace std;
char aa[1505][1505];
bool vised[1505][1505];
int have[100005];
const int pre[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,-1},{1,1},{-1,1},{-1,-1}};
void dfs(int x,int y);
int a,b;
int temp=0;
int main(){
//	freopen("star.in","r",stdin);
//	freopen("star.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			cin>>aa[i][j];
		}
	}
	int count=0,ans=0;
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			if((!vised[i][j])&&aa[i][j]=='*'){
//				count++;
				temp=0;
				dfs(i,j);
				have[temp]++;
			}
			
		}
	}
	for(int i=1;i<=100000;i++){
		if(have[i]){
			ans=max(ans,have[i]*i);
			count++;
		}
	} 
	cout<<count<<' '<<ans;
	return 0;
}
void dfs(int x,int y){
	if(x<=0||y<=0||x>a||y>b){
		return ;
	}
	if(vised[x][y]||aa[x][y]=='.'){
		return ;
	}
	vised[x][y]=1;
	temp++;
	for(int i=0;i<8;i++){
		dfs(x+pre[i][0],y+pre[i][1]);
	}
	return ;
}