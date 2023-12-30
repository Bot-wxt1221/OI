#include <iostream>
#include <cstdio>
#include <queue> 
#include <cstring>
namespace pro{
	int read();
	void add(int x,int y,int z);
	class node{
		public:
			int i,kk;
			int dis;
			node(int x,int y,int z){
				i=x;
				kk=y;
				dis=z;
				return ;
			}
	};
	bool operator < (node a,node b){
		return a.dis>b.dis;
	}
	std::priority_queue<node>qu;
	int dp[10005][105];
	int sure[10005][105];
	int fir[80005];
	int nxt[80005];
	int v[80005];
	int w[80005];
	int now;
	int solve(){
		int n=read(),m,k;
		m=read();
		k=read();
		for(int i=1;i<=n;i++){
			fir[i]=-1;
		}
		for(int i=1;i<=m;i++){
			int u=read();
			int v=read();
			int m=read();
			add(u,v,m); 
		}
		memset(dp,0x7f,sizeof(dp));
		dp[1][0]=0;
		qu.push(node(1,0,0));
		while(qu.size()>0){
			node temp=qu.top();
			qu.pop();
			while(qu.size()>0&&sure[temp.i][temp.kk]){
				temp=qu.top();
				qu.pop();
			}
      if(qu.size()==0){
        break;
      }
			sure[temp.i][temp.kk]=1; 
			for(int i=fir[temp.i];i!=-1;i=nxt[i]){
				int disto=dp[temp.i][temp.kk]+1;
				int distok=disto%k;
				if(dp[temp.i][temp.kk]<w[i]){
					int addk=(w[i]-dp[temp.i][temp.kk])/k;
					if((w[i]-dp[temp.i][temp.kk])%k!=0){
						addk++;
					}
					disto+=addk*k;
				}
				if(disto<dp[v[i]][distok]){
					dp[v[i]][distok]=disto;
					qu.push(node(v[i],distok,dp[v[i]][distok]));
				}
			}
		}
		if(dp[n][0]>=0x7f7f7f7f){
			printf("-1");
		}else{
			printf("%d",dp[n][0]);
		}
		return 0;
	}
};

int main(){
// 	freopen("bus.in","r",stdin);
// 	freopen("bus.out","w",stdout);
	return pro::solve();
}
void pro::add(int x,int y,int z){
	w[++now]=z;
	v[now]=y;
	nxt[now]=fir[x];
	fir[x]=now;
	return ;
}
int pro::read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		if(temp=='-'){
			f=-1;
		}
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}

