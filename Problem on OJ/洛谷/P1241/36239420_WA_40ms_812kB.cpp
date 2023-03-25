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
int stack[105];
int stack2[105];
bool vised[105];
char ma[105];
int top=0,top2=0;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	char a=100;
	int i=0;
	while(a!=EOF){
		i++;
		a=getchar();
		ma[i]=a;
		if(a=='('){
			stack[top++]=i;
		}else if(a=='['){
			stack2[top2++]=i;
		}else if(a==')'){
			if(top>0){
				top--;
				vised[i]=1;
				vised[stack[top]]=1;
			}
		}else if(a==']'){
			if(top2>0){
				top2--;
				vised[i]=1;
				vised[stack2[top2]]=1;
			}
		}
	}
	for(int j=1;j<=i;j++){
		if(vised[j]){
			cout<<ma[j];
		}else if(ma[j]=='('){
			cout<<"()";
		}else if(ma[j]=='['){
			cout<<"[]";
		}
	}
	return 0;
}
