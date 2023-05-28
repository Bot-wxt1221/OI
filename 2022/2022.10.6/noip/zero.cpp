#include <iostream>
#include <cstdio>
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
int n,m;
int x[100005];
int pre[100005];
int search(int p,int now){
	if(now<0){
		now=-now;
	}
	int l=1,r=m;
	while(r-l>=10){
		int mid=(l+r)/2;
		if(pre[mid]-pre[p]<now){
			l=mid-1;
		}else{
			r=mid+1;
		}
	}
	for(int i=l;i<=r;i++){
		if(pre[i]-pre[p]>=now){
			return i;
		}
	}
	return r;
}
int main(){
	freopen("zero.in","r",stdin);
	freopen("zero.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		x[i]=read();
	}
	for(int i=1;i<=m;i++){
		pre[i]=pre[i-1]+read();
	}
	for(int i=1;i<=n;i++){
		int now=0;
		bool ans=0;
		while(now<=m){
			int prenow=now;
			now=search(now,x[i]);
			if(x[i]<0){
				x[i]+=pre[now]-pre[prenow];
			}else{
				x[i]-=pre[now]-pre[prenow];
			}
			if(x[i]==0){
				printf("Yes %d\n",now);
				ans=1;
				break;
			}
			if(now==m){
				break;
			}
		}
		if(ans==0){
			printf("No %d\n",x[i]);
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



