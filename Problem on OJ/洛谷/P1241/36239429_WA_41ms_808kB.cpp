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
		int num;
		char n;
};
node stack[105];
bool vised[105];
char ma[105];
int top=0,top2=0;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	char a=100;
	node temp;
	int i=0;
	while(a!=EOF){
		i++;
		a=getchar();
		ma[i]=a;
		if(a==')')
			for(int j=i-1;j>=1;j--){
				if(ma[j]=='('){
					vised[j]=vised[i]=1;
					break;
				}
			}
		if(a==']')
			for(int j=i-1;j>=1;j--){
				if(ma[j]=='['){
					vised[j]=vised[i]=1;
					break;
				}
			}
	}
	for(int j=1;j<=i;j++){
		if(vised[j]){
			cout<<ma[j];
		}else if(ma[j]=='('||ma[j]==')'){
			cout<<"()";
		}else if(ma[j]=='['||ma[j]==']'){
			cout<<"[]";
		}
	}
	return 0;
}