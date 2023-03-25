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
class node{
	public:
		int n,num;
};
node stack[105];
bool vised[105];
string ma;
int top=0;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	char a=100;
	while(a!=EOF){
		a=getchar();
		ma=ma+a;
		int b;
		if(a=='('||a==')'){
			b=1;
		}else if(a=='['||a==']'){
			b=2;
		}
		if(top>0&&stack[top-1].n==b){
			top--;
			vised[stack[top].num]=vised[ma.size()-1]=1;
		}else{
			node temp;
			temp.n=b;
			temp.num=ma.size()-1;
			stack[top++]=temp;
		}
	}
	for(int i=0;i<ma.size();i++){
		if(!vised[i]){
			if(ma[i]=='['||ma[i]==']'){
				cout<<"[]";
			}else if(ma[i]=='('||ma[i]==')'){
				cout<<"()";
			}
		}else{
			cout<<ma[i];
		}
	}
	return 0;
}
