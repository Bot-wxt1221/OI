#include <iostream>
#include <cstdio>
using namespace std;
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
class node{
	public:
		int data,left,right;
		node();
}b[1000005];
node::node(){
	data=left=right=0;
	return ;
}
int now=1;
int f;
int find1(int ,int );
void insert(int,int);
void dele(node ,int );
int main() {
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	n=read();
	for(int i=1;i<=n;i++){
		int n=read(),m;
		m=read();
		switch(n){
			case 1://insert
			{
				insert(1,m);
				break;
			}
			case 2://delete
			{
				dele(b[1],m);
				break;
			}
			case 3://find
			{
				printf("%d",b[find1(1,m)].data==m);
				break;
			}
		}
	}
	return 0;
}
void insert(int a,int n){
	if(n==b[a].data){
		return ;
	}
	if(b[a].left==0&&n<b[a].data){
		now++;
		b[now].data=n;
		b[a].left=now;
	}
	else if(b[a].right==0&&n>b[a].data){
		now++;
		b[now].data=n;
		b[a].right=now;
	}else if(n<b[a].data){
		insert(b[a].left,n);
	}else{
		insert(b[a].right,n);
	}
	return ;
}
void dele(node a,int n){
	f=1;
	int temp=find1(1,n);
	if(b[temp].left!=0&&b[temp].right!=0){
		int q=temp;
		int m=b[temp].left;
		while(b[m].data!=0){
			q=m;
			m=b[m].right;
		}
		b[temp].data=b[m].data;
		if(temp!=q){
			b[q].right=b[m].left;
		}else{
			b[q].left=b[m].left;
		}
	}else{
		int q;
		if(b[temp].right==0){
			q=temp;
			temp=b[temp].left;
		}
		else if(b[temp].left==0){
			q=temp;
			temp=b[temp].right;
		}
		if(f==1){
			b[1]=b[temp];
		}else if(q==b[f].left){
			b[f].left=temp;
		}else{
			b[f].right=temp;
		}
	}
}
int find1(int a,int n){
	if(b[a].data==n){
		return a;
	}
	if(b[a].right==0&&b[a].left==0){
		return 0;
	}
	f=a;
	if(n<b[a].data){
		return find1(b[a].left,n);
	}else{
		return find1(b[a].right,n);
	}
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



