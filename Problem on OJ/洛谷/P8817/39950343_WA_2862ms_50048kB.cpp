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
long long dp[4][2505];
long long choose[4][2505];
long long vised[2505];
queue<long long>in;
long long Map[2505][2505];
long long score[2505];
void bfs(long long now,long long m); 
int main(){
//	freopen("holiday.in","r",stdin);
//	freopen("holiday.out","w",stdout);
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
			if(score[i]+score[j]>=dp[1][j]){
                dp[3][j]=dp[2][j];
                choose[3][j]=choose[2][j];
				dp[2][j]=dp[1][j];
				choose[2][j]=choose[1][j];
				dp[1][j]=score[i]+score[j];
				choose[1][j]=i;
			}else if(score[i]+score[j]>=dp[2][j]){
                dp[3][j]=dp[2][j];
                choose[3][j]=choose[2][j];
				dp[2][j]=score[i]+score[j];
				choose[2][j]=i;
			}else if(score[i]+score[j]>=dp[3][j]){
                dp[3][j]=score[i]+score[j];
				choose[3][j]=i;
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
			for(int ia=1;ia<=3;ia++){
                for(int ja=1;ja<=3;ja++){
                    if(choose[ia][i]!=choose[ja][j]&&choose[ia][i]!=j&&choose[ja][j]!=i){
                        ans=max(ans,dp[ia][i]+dp[ja][j]);
                    }
                }
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