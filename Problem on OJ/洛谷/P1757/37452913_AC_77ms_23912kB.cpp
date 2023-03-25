#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
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
set<int>have;
vector<int>fen[1000005];
int use[1005];
int pay[1005];
int dp[1005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int m=read(),n=read();
	for(int i=1;i<=n;i++){
		use[i]=read();
		pay[i]=read();
		int temp=read();
		fen[temp].push_back(i);
		have.insert(temp);
	}
	for(set<int>::iterator ji=have.begin();ji!=have.end();ji++){
		for(int i=m;i>=1;i--){
			int _max=0;
			for(int mm=0;mm<fen[*ji].size();mm++){
				if(i-use[fen[*ji][mm]]>=0)
					_max=max(_max,dp[i-use[fen[*ji][mm]]]+pay[fen[*ji][mm]]);
			}
			dp[i]=max(dp[i],_max);
		}
	}
	printf("%d",dp[m]);
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


