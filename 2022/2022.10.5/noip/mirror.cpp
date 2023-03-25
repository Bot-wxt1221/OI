#include <iostream>
#include <cstdio>
#include <algorithm>
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
class node{
	public:
		int x,y,i;
		char a;
}a[1000005];
class node2{
	public:
		int mi,pos;
		node2(int m,int p){
			mi=m;
			pos=p;
		}
		node2(){
			
		}
};
node2 to[1000005][4];
int vised[1000005][4];
bool cmp1(node a,node b){
	return a.x==b.x?a.y<b.y:a.x<b.x;
}
bool cmp2(node a,node b){
	return a.y==b.y?a.x<b.x:a.y<b.y;
}
bool cmp3(node a,node b){
	return a.i<b.i;
}
int main(){
	freopen("mirror.in","r",stdin);
	freopen("mirror.out","w",stdout);
	int n=read(),m,T;
	m=read();
	T=read();
	for(int i=1;i<=n;i++){
		a[i].x=read();
		a[i].y=read();
		a[i].a=getchar();
		a[i].i=i;
	}
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++){
		if(a[i+1].x!=a[i].x){
			to[a[i].i][1]=node2(-1,-1);
		}else{
			if(a[i+1].a=='\\')
				to[a[i].i][1]=node2(a[i+1].i,2);
			else
				to[a[i].i][1]=node2(a[i+1].i,4);
		}
		if(a[i-1].x!=a[i].x){
			to[a[i].i][3]=node2(-1,-1);
		}else{
			if(a[i-1].a=='\\')
				to[a[i].i][3]=node2(a[i-1].i,4);
			else
				to[a[i].i][3]=node2(a[i-1].i,2);
		}
	}
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++){
		if(a[i+1].y!=a[i].y){
			to[a[i].i][4]=node2(-1,-1);
		}else{
			if(a[i+1].a=='\\')
				to[a[i].i][4]=node2(a[i+1].i,3);
			else
				to[a[i].i][4]=node2(a[i+1].i,1);
		}
		if(a[i-1].y!=a[i].y){
			to[a[i].i][2]=node2(-1,-1);
		}else{
			if(a[i-1].a=='\\')
				to[a[i].i][2]=node2(a[i-1].i,1);
			else
				to[a[i].i][2]=node2(a[i-1].i,3);
		}
	}
	node2 temp;
	for(int i=1;i<=n;i++){
		if(a[i].y==0){
			temp.mi=a[i].i;
			if(a[i].a=='\\'){
				temp.pos=3;
			}else {
				temp.pos=1;
			}
			int To=T;
			vised[temp.mi][temp.pos]=a[i].x-1;
			T-=a[i].x;
//			T+=1;
			if(T<=0){
				printf("%d %d",To+1,1);
				return 0;
			}
			break;
		}
	}
	sort(a+1,a+n+1,cmp3);
	while(1){
		node2 temp2=to[temp.mi][temp.pos];
		if(temp2.mi==-1){
			int x=a[temp.mi].x,y=a[temp.mi].y;
			if(temp.pos==1){
				y+=T;
			}else if(temp.pos==2){
				x-=T;
			}else if(temp.pos==3){
				y-=T;
			}else{
				x+=T;
			}
			printf("%d %d",x,y);
			return 0;
		}
		int go=max(abs(a[temp.mi].x-a[temp2.mi].x),abs(a[temp.mi].y-a[temp2.mi].y));
		T-=max(abs(a[temp.mi].x-a[temp2.mi].x),abs(a[temp.mi].y-a[temp2.mi].y));
		if(T<=0){
			int x=a[temp.mi].x,y=a[temp.mi].y;
			if(temp.pos==1){
				y+=go;
			}else if(temp.pos==2){
				x-=go;
			}else if(temp.pos==3){
				y-=go;
			}else{
				x+=go;
			}
			printf("%d %d",x,y);
			return 0;
		}
		temp=temp2;
	}
	
	
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



