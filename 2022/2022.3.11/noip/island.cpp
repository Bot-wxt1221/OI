
/*
模板题，按单位价值从大到小考虑 
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
void work();
class node{
	public:
		int n,v;
		double so; 
}a[105];
bool cmp(node a,node b){
	return a.so>b.so;
}
int main(){
	freopen("island.in","r",stdin);
	freopen("island.out","w",stdout);
	int k;
	k=read();
	for(int i=1;i<=k;i++){
		work();
	}
	return 0;
}
void work(){
	int w,s;
	w=read();
	s=read();
	for(int i=1;i<=s;i++){
		a[i].n=read();
		a[i].v=read();
		a[i].so=double(a[i].v)/a[i].n;//记得强转 
	}
	sort(a+1,a+s+1,cmp);
	double ans=0;
	for(int i=1;i<=s;i++){
		if(w>=a[i].n){//装的完 
			ans+=a[i].v;
			w-=a[i].n;
		}else{//装不完 
			ans+=a[i].so*w;
			w=0;
		}
	}
	printf("%.2lf\n",ans);
}
