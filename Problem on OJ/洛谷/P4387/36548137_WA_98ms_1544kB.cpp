#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int read(){
	int x=0;
	char f=1,t=getchar();
	while('0'>t||t>'9'){
		f=(t=='-'?-1:f);
		t=getchar();
	}
	while('0'<=t&&t<='9'){
		x=(x<<3)+(x<<1)+(t^'0');
		t=getchar();
	}
	return x;
}
int a[100005];
int b[100005];
stack<int>c;
int main(){
	int q=read();
	for(int Q=1;Q<=q;Q++){
		c=stack<int>();
		int n=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		for(int i=1;i<=n;i++){
			b[i]=read();
		}
		bool win=1;
		int ib=1;
		for(int i=1;i<=n;i++){
			if(c.size()>0&&b[i]==c.top()){
				c.pop();
			}else{
				while(a[ib]!=b[i]){
					c.push(a[ib]);
					ib++;
				}
			}
			if(ib>n){
				win=0;
				break;
			}
		}
		if(win)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}