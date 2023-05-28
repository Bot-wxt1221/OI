#include <iostream>
#include <cstdio>
#include <stack>
#define MAXN 1000
using namespace std;
int pre[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
bool vis[MAXN+5][MAXN+5][9];
class pos{
	public:
		int x,y,fpos;
};
int maze[MAXN+5][MAXN+5];
stack <pos> dfs;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>maze[i][j];
		}
	}
	pos temp;
	temp.x=1,temp.y=1;//��ʼ�� 
	temp.fpos=-1;//��ʵ���򣬺����1�ͱ��0�� 
	dfs.push(temp);//����ջ 
	while(!dfs.empty()){
		if(dfs.top().x>n||dfs.top().x<0||dfs.top().y>m||dfs.top().y<0||maze[dfs.top().x][dfs.top().y]||vis[dfs.top().x][dfs.top().y][dfs.top().fpos]){
			vis[dfs.top().x][dfs.top().y][dfs.top().fpos]=0;//�߽��ж� 
			dfs.pop();
			continue;
		}
		else if(dfs.top().fpos==7){
			vis[dfs.top().x][dfs.top().y][dfs.top().fpos]=0;
			dfs.pop();//�߽��ж� 
			continue; 
		}else{
			vis[dfs.top().x][dfs.top().y][dfs.top().fpos]=1;//��� 
			if(dfs.top().x==4&&dfs.top().y==4){
				while(dfs.size()>0){
					cout<<dfs.top().x-1<<' '<<dfs.top().y-1<<endl;//��� 
					dfs.pop();
				}
				return 0;
			}
			dfs.top().fpos++;//��������� 
			pos temp2=dfs.top();
			temp2.x+=pre[temp2.fpos][0];
			temp2.y+=pre[temp2.fpos][1];
			temp2.fpos=-1;//ǧ��Ҫ���ǰ�qwq 
			dfs.push(temp2); 
	}
	}
	cout<<"no answer.";
	return 0;
}
