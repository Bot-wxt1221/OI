#include <iostream>
#include <cstdio>
#include <stack>
inline int read();
int seq[1000005];
int dp[1000005];
std::stack<int>a;
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("temperatures.in","r",stdin);
	freopen("temperatures.out","w",stdout);
	#endif
    int n=0;
    while(scanf("%d",&seq[++n])!=-1);
    n--;
    a.push(n);
    dp[n]=0;
    for(int i=n-1;i>=1;i--){
        while(a.size()>0&&seq[i]>=seq[a.top()]){
            a.pop();
        }
        if(a.size()>0){
            dp[i]=a.top()-i;
        }else{
            dp[i]=0;
        }
        a.push(i);
    }
    for(int i=1;i<=n;i++){
        printf("%d ",dp[i]);
    }
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


