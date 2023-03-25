#include <iostream>
using namespace std;
const int pre[2][2]={{0,1},{1,0}};
int aa[10][10];
int _ans=0;
int n;
void dfs(int x,int y,int now,int a);
int main(){
	cin>>n;
	int a,b,c;
	do{
		cin>>a>>b>>c;
		aa[a][b]=c;
	}while(a!=0);
	dfs(1,1,0,0);
	cout<<_ans;
}
void dfs(int x,int y,int now,int a){
	if(x>n||y>n||x<=0||y<=0){
		return ;
	}
	if(x==n&&y==n&&a==0){
		dfs(1,1,now,1);
		return ;
	}
	if(x==n&&y==n&&a==1){
		_ans=max(_ans,now);
		return ;
	}
	for(int p=0;p<=1;p++){
		int nx=x+pre[p][0];
		int ny=y+pre[p][1];
		int temp=aa[nx][ny];
		aa[nx][ny]=0;
		dfs(nx,ny,temp+now,a);
		aa[nx][ny]=temp;
	}
	return ;
}