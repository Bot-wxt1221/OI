#include <iostream>
#include <cstdio>
using namespace std;
class node{
	public:
		node *to;
		int d;
		node(){
			to=NULL;
			d=0;
		} 
};
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
node *H=new node;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int m=read();
	for(int i=1;i<=m;i++){
		int temp=read();
		if(temp==0){//��i�����һ��Ԫ�� 
			int a,b;
			a=read();
			b=read();
			node *now=H;
			bool aa=1;
			for(int j=1;j<=a;j++){
				if(now==NULL){
					printf("�Ƿ�����");
					aa=0;
				}else
					now=now->to;
			}
			if(aa){
				node *ne=new node;
				ne->d=b;
				ne->to=now->to;
				now->to=ne;
			}
		}
		if(temp==1){//�������Ԫ�� 
			node *now=H;
			while(now->to!=NULL){
				now=now->to;
				cout<<now->d<<' ';
			}
		}
		if(temp==2){//ɾ��һ���� 
			int a;
			a=read();
			if(H->to==NULL){
				printf("�Ƿ�����");
				continue;
			}
			node *now=H;
			for(int j=1;j<=a-1;j++){
				now=now->to; 
			}
			node *tem=(now->to)->to;
			delete now->to;
			now->to=tem;
		} 
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

