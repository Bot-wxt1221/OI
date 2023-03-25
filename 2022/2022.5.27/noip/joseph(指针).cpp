#include <iostream>
#include <cstdio>
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
		int data;
		node *next;
};
node *H=new node;
int main(){
	freopen("joseph.in","r",stdin);
	freopen("joseph.out","w",stdout);
	int n,m;
	n=read();m=read();
	node *l=H;
	for(int i=1;i<=n;i++){
		node *ne=new node;
		ne->next=NULL;
		ne->data=i;
		l->next=ne;
		l=ne;
	}
	node *now=H;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m-1;j++){
			now=now->next;
			if(now==NULL){
				now=H->next;
			}
		}
		node *temp=now->next;
		if(temp==NULL){
			temp=H->next;
		}
		cout<<temp->data<<' ';
		now->next=(temp)->next;
		delete temp;
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


