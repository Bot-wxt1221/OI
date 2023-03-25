#include <iostream>
#include <cstdio>
#include <deque>
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
deque<int>a;
int b[2000005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,m;
	n=read();m=read();
	for(int i=1;i<=m-1;i++){
		if(a.size()==0){
			cout<<0<<endl;
		}else{
			cout<<b[a.front()]<<endl;
		}
		b[i]=read();
		while(a.size()>0&&b[a.back()]>b[i])	a.pop_back();
		a.push_back(i);
	}
	for(int i=m;i<=n;i++){
		b[i]=read();
		cout<<b[a.front()]<<endl;
		while(a.size()>0&&b[a.back()]>b[i])	a.pop_back();
		a.push_back(i);
		if(a.front()==i-m){
			a.pop_front();
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
