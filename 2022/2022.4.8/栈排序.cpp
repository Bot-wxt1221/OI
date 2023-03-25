#include <iostream>
#include <cstdio>
#include <stack> 
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
stack<int>st;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	n=read();
	for(int i=1;i<=n;i++){
		st.push(read());
	} 
	stack<int>st1;
	int temp;
	int ans=0;
	while(!st.empty()){
		temp=st.top();
		st.pop();
		while(!st1.empty()&&temp<st1.top()){
			st.push(st1.top());
			st1.pop();
		}
		st1.push(temp);
	}
	while(!st1.empty()){
		temp=st1.top();
		st1.pop();
		st.push(temp);
	}
	while(!st.empty()){
		cout<<st.top()<<' ';
		st.pop();
	}
	cout<<endl<<ans;
	return 0;
}

