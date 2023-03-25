/*
按照脂肪多少排序，脂肪最多的优先考虑 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
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
int _max[1005];
int more_m[1005];
class node{
	public:
		int a,b;
}dish[1005];
bool cmp(node a,node b){
	return a.a>b.a;
}
int main(){
	freopen("diet.in","r",stdin);
	freopen("diet.out","w",stdout);
	int n,m,k;
	n=read();m=read();k=read();
	for(int i=1;i<=k;i++){
		_max[i]=read();
		more_m[i]=_max[i];
	}
	for(int i=1;i<=n;i++){
		dish[i].a=read();
		dish[i].b=read();
	}
	sort(dish+1,dish+n+1,cmp);
	int ans=0,morem=m;
	for(int i=1;i<=n;i++){
		if(morem>=1&&more_m[dish[i].b]>=1){//贪心 
			morem--;
			more_m[dish[i].b]--;
			ans+=dish[i].a;
		}
	}
	cout<<ans;
	return 0;
}

