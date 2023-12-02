#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
inline int read();
int a[6005];
class node{
	public:
		int x,y,num;
		node(int xx=0,int yy=0,int zz=0){
			x=xx;
			y=yy;
			num=zz;
			return ;
		}
};
std::vector<node>to;
int dp[6005][6005];
int sum[6005];
int pp[5];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read();
    memset(dp,0xcf,sizeof(dp));
	memset(sum,0xcf,sizeof(sum));
    for(int i=1;i<=3*n;i++){
        a[i]=read();
    }
	int _max=0;
	int lazy=0;
	dp[a[1]][a[2]]=dp[a[2]][a[1]]=0;
	sum[a[1]]=sum[a[2]]=0;
	for(int ii=3;ii<3*n;ii+=3){
		std::sort(a+ii,a+ii+3);
		int a=::a[ii];
		pp[1]=a;
		int b=::a[ii+1];
		pp[2]=b;
		int c=::a[ii+2];
		pp[3]=c;
		if(a==b&&b==c){
			lazy++;
			continue;
		}
		if(b==c){
			std::swap(a,c);
			std::swap(pp[1],pp[3]);
		}
		if(a==b){
			for(int i=1;i<=n;i++){
				to.push_back(node(i,c,dp[i][a]+1));
			}
		}
		for(int i=1;i<=3;i++){
			std::vector<int>q;
			for(int j=1;j<=3;j++){
				if(i!=j){
					q.push_back(pp[j]);
				}
			}
			to.push_back(node(q[0],q[1],dp[pp[i]][pp[i]]+1));
		}
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n;j++){
				bool have=0;
				for(int kk=1;kk<=3;kk++){
					if(i!=kk&&j==pp[kk]){
						have=1;
					}
				}
				if(have){
					to.push_back(node(pp[i],j,_max));
				}else{
					to.push_back(node(pp[i],j,sum[j]));
				}
			}
		}
		for(int i=0;i<to.size();i++){
			dp[to[i].x][to[i].y]=std::max(dp[to[i].x][to[i].y],to[i].num);
			dp[to[i].y][to[i].x]=std::max(dp[to[i].y][to[i].x],to[i].num);
			sum[to[i].x]=std::max(sum[to[i].x],dp[to[i].x][to[i].y]);
			sum[to[i].y]=std::max(sum[to[i].y],dp[to[i].x][to[i].y]);
			_max=std::max(_max,dp[to[i].x][to[i].y]);
		}
		to.clear();
	}
	int ans=0;
	_max=std::max(_max,dp[a[n*3]][a[n*3]]+1);
	// for(int i=1;i<=n;i++){
	// 	for(int j=i;j<=n;j++){
	// 		if(i==a[n*3]&&j==a[n*3]){
	// 			ans=std::max(ans,dp[i][j]+1);
	// 		}else{
	// 			ans=std::max(ans,dp[i][j]);
	// 		}
	// 	}
	// }
	printf("%d",_max+lazy);
	return 0;
}
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
/*2
1 2 1 2 2 1
Description:

Example:
	1:
		In:

		Out:
More:

*/

