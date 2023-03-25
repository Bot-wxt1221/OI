#include <iostream>
#include <cstdio>
#include <algorithm>
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
class node{
	public:
		int data,i;
}a[200005];
bool cmp(node a,node b){
	return a.data==b.data?a.i<b.i:a.data<b.data;
}
//bool top[200005];//这个数是双端队列的队头 
int main(){
//	freopen("deque.in","r",stdin);
//	freopen("deque.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		a[i].data=read();
		a[i].i=i;
	}
	sort(a+1,a+n+1,cmp);
	int ans=0;
	int i=1;
	if(a[i].i<=a[i+1].i){
		ans++;
		while(a[i].i<=a[i+1].i&&i<=n)	i++;
	}
	for(;i<=n;){
		bool to=0;
		while(a[i].i>=a[i+1].i&&i<=n)	i++;
		i++;
		while(a[i].i<=a[i+1].i&&i<=n)	i++;
	}
	cout<<ans;
	return 0;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:
			6 3 6 0 9 6 3
		Out:
			2
More:

*/

