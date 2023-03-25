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
class node{
	public:
		int a,b;
};
node temp[500005];
stack<node>a;
int main(){
//	freopen("stack.in","r",stdin);
//	freopen("stack.out","w",stdout);
	int n,q,ans=0;
	n=read();
	q=read();
	for(int i=1;i<=n;i++){
		temp[i].a=read();
	}
	for(int i=1;i<=n;i++){
		temp[i].b=read();
	}
	for(int i=1;i<=q;i++){
		ans=0;
		while(a.size()>0){
			a.pop(); 
		} 
		int l,r;
		l=read();
		r=read();
		for(int j=l;j<=r;j++){
			while(a.size()>0&&(a.top().a==temp[j].a||a.top().b<=temp[j].b)){
				a.pop();
			}
			a.push(temp[j]);
			if(a.size()==1){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
