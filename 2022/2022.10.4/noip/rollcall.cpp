#include <iostream>
#include <cstdio>
#include <queue>
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
priority_queue<int>temp;
priority_queue<int>a;
int temp2[300005];
int aa[300005],b[300006];
int main(){
	freopen("rollcall.in","r",stdin);
	freopen("rollcall.out","w",stdout);
	int n=read(),m;
	m=read();
	for(int i=1;i<=n;i++){
		aa[i]=read();
	}
	for(int i=1;i<=m;i++){
		b[i]=read();
		for(int j=b[i-1]+1;j<=b[i];j++){
			a.push(aa[j]);
			if(a.size()>m){
				a.pop();
			}
		}
		if(a.size()<=i){
			printf("%d\n",a.top());
		}else{
			int siz=a.size()-i;
			for(int i=1;i<=siz;i++){
				temp2[i]=a.top();
				a.pop();
			}
			printf("%d\n",a.top());
			for(int i=1;i<=siz;i++){
				a.push(temp2[i]);
			}
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



