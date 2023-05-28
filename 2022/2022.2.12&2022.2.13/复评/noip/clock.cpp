/*
由于每次操作最多4次，所以直接爆枚，AC本题，代码实现上坑很多 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int now[10][10];
int go[100];
bool con[9][3][3]={{{1,1,0},{1,1,0},{0,0,0}},{{1,1,1},{0,0,0},{0,0,0}},{{0,1,1},{0,1,1},{0,0,0}},{{1,0,0},{1,0,0},{1,0,0}},{{0,1,0},{1,1,1},{0,1,0}},{{0,0,1},{0,0,1},{0,0,1}},{{0,0,0},{1,1,0},{1,1,0}},{{0,0,0},{0,0,0},{1,1,1}},{{0,0,0},{0,1,1},{0,1,1}}};
int vis[100];
int use=0;
int _min=99999999;
void dfs(int step);
int main(){
	freopen("clock.in","r",stdin);
	freopen("clock.out","w",stdout);
	for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				cin>>now[i][j];
			}
		}
	dfs(0);
	if(_min==99999999){
		cout<<"No answer.";
		return 0;
	}
	sort(go+1,go+_min+1);
	for(int i=1;i<=_min;i++){
		cout<<go[i]+1<<' ';
	}
	return 0;
}
void dfs(int step){
	if(step==9){
		int now[10][10];
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				now[i][j]=::now[i][j];
			}
		}
		for(int i=0;i<9;i++){
			for(int ushf=1;ushf<=vis[i];ushf++){
				for(int x=0;x<3;x++){
					for(int y=0;y<3;y++){
						if(con[i][x][y]){
							now[x][y]=(now[x][y]+1)%4;
						}
					}
				}
			}
		}
		for(int x=0;x<3;x++){
			for(int y=0;y<3;y++){
				if(now[x][y]){
					return ;
				}
			}
		}
		if(_min>=use){
			_min=use;
			int now=1;
			for(int i=0;i<9;i++){
				for(int j=1;j<=vis[i];j++)
					go[now++]=i;
			}
		}
		return ;
	}
	for(int i=0;i<4;i++){
		vis[step]=i;
		use+=i;
		dfs(step+1);
		use-=i;
	}
}
