#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
class pos{
	public:
		int x,y;
		pos(){
			x=y=0;
		}
};
stack <pos> a;
stack <pos> b;
int cnat;
const int to[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int n;
bool vised[20][20];
bool vised2[20][20];
pos bx[20];
pos by[20];
void dfs(int step,int x,int y);
void dfs2(int step,int x,int y);
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cnat=0;
	cin>>n;
	dfs(0,0,0);
	cout<<cnat;
	return 0;
}
void dfs(int step,int x,int y){
	if(step>n*2){
		return;
	}
	if(x<0||y<0||x>n||y>n){
			return;
		}
	if(x==n&&y==n){
		dfs2(0,n,n);
		return;
	}
	for(int i=0;i<2;i++){
		pos aa;
		aa.x=x+to[i][0],aa.y=y+to[i][1];
		if(aa.x<0||aa.y<0||aa.x>n||aa.y>n){
			continue;
		}
		if(vised[aa.x][aa.y]==1){
			continue;
		}
		a.push(aa);
		vised[aa.x][aa.y]=1;
		dfs(step+1,aa.x,aa.y);
		vised[aa.x][aa.y]=0;
		a.pop();
	}
	return;
}
void dfs2(int step,int x,int y){
	if(step>n*2){
		return;
	}
	if(x<0||y<0||x>n||y>n){
		return;
	}
	if(x==0&&y==0){
		int i=0;
		stack <pos> aa=a;
		stack <pos> ba=b;
		while(aa.size()>0){
			bx[++i]=aa.top();
			aa.pop();
		}
		int j=0;
		while(ba.size()>0){
			by[++j]=ba.top();
			ba.pop();
		}
		int cnt=0;
		for(int a=1;a<=i;a++){
			if(bx[a].x==by[a].x||bx[a].y==by[a].y){
				cnt++;
			}
		}
		bool can=0;
		if(cnt>=2){
			can=1;
		}
		cnt=0;
		for(int a=1;a<=i;a++){
			if(bx[a].x==by[a].x&&bx[a].y==by[a].y){
				cnt++;
			}
		}
		if(cnt!=0){
			can=1;
		}
		if(!can){
			return;
		}
		cnat++;
		return;
	}
	for(int i=2;i<4;i++){
		pos aa;
		aa.x=x+to[i][0],aa.y=y+to[i][1];
		if(aa.x<0||aa.y<0||aa.x>n||aa.y>n){
			continue;
		}
		if(vised2[aa.x][aa.y]==1){
			continue;
		}
		vised2[aa.x][aa.y]=1;
		b.push(aa);
		dfs2(step+1,aa.x,aa.y);
		vised2[aa.x][aa.y]=0;
		b.pop();
	}
	return;
}
