#include <iostream>
#include <cstdio>
#include <stack>
inline int read();
int to[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int a[105][105];
class node{
    public:
        int x,y,sta;
        node(){
        }
        node(int xx,int yy,int s){
            x=xx;
            y=yy;
            sta=s;
        }
};
std::stack<node>b;
int main(){
	#ifdef ONLINE_JUDGE
	#else
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	#endif
	int n=read(),m=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=read();
        }
    }
    int x=read(),y=read();
    b.push(node(1,1,0));//入口
    a[1][1]=1;
    while(b.size()>0){
        node temp=b.top();
        if(temp.sta==4){//方向走完了，直接退栈
            a[temp.x][temp.y]=0;
            b.pop();
            continue;
        }
        b.top().sta++;//更新状态，同时由于单独开了temp来存，不影响后续计算
        int nx=temp.x+to[temp.sta][0];
        int ny=temp.y+to[temp.sta][1];
        if(0<nx&&0<ny&&nx<=n&&ny<=n&&a[nx][ny]==0){
            a[nx][ny]=1;
            b.push(node(nx,ny,0));
            if(nx==x&&ny==y){//判断是否到达终点
                std::stack<node>c=b;//为了不影响原栈，复制一份进行计算
                while(c.size()>0){
                    printf("%d %d\n",c.top().x,c.top().y);
                    c.pop();
                }
                printf("Found\n");
            }
        }
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


