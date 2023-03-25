#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
long long read(){
	char temp=getchar();
	long long f=1,x=0;
	while('0'>temp||temp>'9'){
		(temp=='-')?(f=-1):(1);
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
long long nxt[20005];
long long fir[1505];
long long v[20006];
long long now;
void add(long long x,long long y){
	now++;
	v[now]=y;
	nxt[now]=fir[x];
	fir[x]=now;
	return ;
}
long long dp1[2505];
long long choose1[2505];
long long dp2[2505];
long long choose2[2505];
long long vised[2505];
queue<long long>in;
long long Map[2505][2505];
long long score[2505];
void bfs(long long now,long long m); 
int main(){
	// freopen("holiday.in","r",stdin);
	// freopen("holiday.out","w",stdout);
	long long n=read();
	long long m=read();
	long long k=read();
	fir[1]=-1;
	for(long long i=2;i<=n;i++){
		fir[i]=-1;
		score[i]=read(); 
	}
	for(long long i=1;i<=m;i++){
		long long x=read();
		long long y=read();
		add(x,y);
		add(y,x);
	}
    memset(Map,0x3f,sizeof(Map));
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			vised[j]=0;
		}
		bfs(i,i);
	}
	for(long long i=2;i<=n;i++){
		for(long long j=2;j<=n;j++){
			if(i==j){
				continue;
			}
			if(Map[1][i]-1>k||Map[i][j]-1>k){
				continue;
			}
			if(score[i]+score[j]>=dp1[j]){
				dp2[j]=dp1[j];
				choose2[j]=choose1[j];
				dp1[j]=score[i]+score[j];
				choose1[j]=i;
			}else if(score[i]+score[j]>=dp2[j]){
				dp2[j]=score[i]+score[j];
				choose2[j]=i;
			}
		}
	}
	long long ans=0;
	for(long long i=2;i<=n;i++){
		for(long long j=2;j<=n;j++){
			if(i==j){
				continue;
			}
			if(Map[i][j]-1>k){
				continue; 
			}
			if(choose1[i]!=choose1[j]&&choose1[j]!=i&&choose1[i]!=j){
				ans=max(ans,dp1[i]+dp1[j]);
			}
			if(choose2[i]!=choose1[j]&&choose1[j]!=i&&choose2[i]!=j){
				ans=max(ans,dp2[i]+dp1[j]);
			}
			if(choose1[i]!=choose2[j]&&choose2[j]!=i&&choose1[i]!=j){
				ans=max(ans,dp1[i]+dp2[j]);
			}
		} 
	}
	printf("%lld",ans);
	return 0;
}
void bfs(long long now,long long m){
	in.push(now);
	Map[now][now]=0;
	while(in.size()>0){
		long long temp=in.front();
		in.pop();
		vised[temp]=1;
		for(long long i=fir[temp];i!=-1;i=nxt[i]){
			if(vised[v[i]]==1){
				continue;
			}
			vised[v[i]]=1;
			Map[m][v[i]]=Map[m][temp]+1;
			in.push(v[i]);
		}
	}
	return ;
}