
/*
每次选最大的两个进行合并  
*/
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
priority_queue<int>a;//每次选最大的两个进行合并 
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
}//快读 
int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	int n,k,ans=0;
	n=read();
	k=read();
	for(int i=1;i<=n;i++){
		a.push(read());
	}
	while(a.size()>1){//模拟 
		int x,y;
		x=(a.top());
		a.pop();
		y=(a.top());
		a.pop();
		a.push((x+y)/k);//k不要写成2 
	}
//	cout<<a.size();
	cout<<a.top();
	return 0;
}

