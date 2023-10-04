#include <iostream>
#include <cstdio>
#define int long long
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
int next[100005];
int pre[100005];
int ghead(){
	for(int i=1;i<=n;i++){
		if(pre[i]==-1){
			return i;
		}
	}
}
void link(int x,int y){
	next[x]=y;
	pre[y]=x;
	return ;
}
signed main(){
	freopen("move2.in","r",stdin);
	freopen("move.out","w",stdout);
	int aaa=1;
	while(scanf("%lld%lld",&n,&m)!=EOF){
		for(int i=0;i<=n+1;i++){
			next[i]=i+1;
			pre[i]=i-1;
		}
		next[n+1]=-1;
		pre[0]=-1;
		bool now=0;
		for(int i=1;i<=m;i++){
			int aa=read();
			if(aa==4){
				now=!now;
			}else {
				int x,y;
				x=read();
				y=read();
			if((aa==1&&now==0)||((aa==2)&&(now==1))){
				link(pre[x],next[x]);
				link(pre[y],x);
				link(x,y);
			}else if((aa==2&&now==0)||((aa==1)&&(now==1))){
				link(pre[x],next[x]);
				int nex=next[y];
				link(y,x);
				link(x,nex);
			}else if(aa==3&&next[y]==x){
				link(pre[x],y);
				link(y,x);
				link(x,next[y]);
			}else if(aa==3){
				int pr=pre[y];
				link(pre[x],y);
				int ne=next[y];
				link(y,next[x]);
				link(pr,x);
				link(x,ne);
			}
		}
		}
		printf("Case %d: ",aaa);
		unsigned long long ans=0;
		int head=0;
		for(int i=1;i<=n;i++){
			if(pre[i]==0){
				head=i;
				break;
			}
		}
		int anow=head;
		int j=1;
		while(anow!=n+1){
			if(j%2==1){
				ans+=anow;
			}
			j++;
			anow=next[anow];
		}
		if(now&&(n%2==0)){
			ans=((n*(n+1))/2)-ans;
		}
		printf("%lld\n",ans);
		aaa++;
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


