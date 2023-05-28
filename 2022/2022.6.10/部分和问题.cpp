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
bool choice[30];
int a[30];
int total=0;
int n,k;
bool c=0;
void dfs(int step);
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	dfs(1);
	if(c==0){
		cout<<"No";
	}else{
		cout<<"Yes";
	}
	return 0;
}
void dfs(int step){
	if(total>k){
		return ;
	}
	if(step==n+1){
		if(k==total){
			c=1;
			for(int i=1;i<=n;i++){
				if(choice[i]){
					cout<<a[i]<<' ';
				}
			}
			cout<<endl;
		}
		return;
	}
	choice[step]=0;
	dfs(step+1);
	choice[step]=1;
	total+=a[step];
	dfs(step+1);
	total-=a[step];
	choice[step]=0;
	return ;
}
/*
Anything about this program:
Type:
	水题 
Description:
	在一个序列中选若干数使它们和等于k 
Example:
	1:
		In:
			4 13
			1 2 4 7
		Out:
			2 4 7
			Yes
	2:
		In:
			4 15
			1 2 4 7
		Out:
			No 
More:

*/


