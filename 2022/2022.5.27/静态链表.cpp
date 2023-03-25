#include <iostream>
#include <cstdio>
using namespace std;
int read(){
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
int data[10005];
int front[10005];
int next[10005]; 
int used=1;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int m=read();
	front[0]=-1;
	next[0]=-1;
	for(int i=1;i<=m;i++){
		int temp=read();
		switch(temp){
			case 0:{//插入 
				int a=read(),b;
				b=read();
				if(front[0]==-1&&next[0]==-1){
					data[used]=b;
					front[0]=-1;
					next[0]=used;
					front[used]=0;
					next[used]=-1;
					used++;
				}
				int now=next[0];
				for(int i=1;i<=a&&now!=-1;i++){
					now=next[now];
				}
				data[used]=b;
				front[used]=now;
				next[used]=next[now];
				front[next[now]]=used;
				next[now]=used;
				used++;
				break;
			}
			case 1:{//删除 
				int a=read();
				int now=next[0];
				for(int i=2;i<=a&&now!=-1;i++){
					now=next[now];
				}
				int temp=next[next[now]];
				next[next[now]]=front[next[now]]=-1;
				next[now]=temp;
				front[temp]=now;
				break;
			}
			case 2:{//输出 
				int now=next[0];
				while(now!=-1){
					now=next[now];
					if(now!=-1) 
						cout<<data[now]<<' ';
				}
				break;
			}
		}
	}
	return 0;
}
/*
Anything about this program:
Type:
	实现 
Description:
	链表基础操作 
Example:
	1:
		In:
			6
			0 0 1
			0 0 2
			2
			1 1
			2
			0 0 1
		Out:
			2 1
			1
More:

*/

