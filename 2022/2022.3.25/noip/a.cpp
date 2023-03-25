#include <iostream>
#include <cstdio>
#include <queue>
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
priority_queue<int>a;
priority_queue<int>b; 
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int n;
	n=read();
	for(int i=1;i<=n;i++){
		int temp=read();
		a.push(temp);
		b.push(-temp);
	}
	int _min;
	while(a.size()>1){
		int aa=a.top();
		a.pop();
		int ba=a.top();
		a.pop();
		a.push(aa*ba+1);
	}
	_min=a.top();
	int _max;
	while(b.size()>1){
		int aa=-b.top();
		b.pop();
		int ba=-b.top();
		b.pop();
		b.push(-(aa*ba+1));
	}
	_max=-b.top();
	cout<<_max-_min;
	return 0;
}

