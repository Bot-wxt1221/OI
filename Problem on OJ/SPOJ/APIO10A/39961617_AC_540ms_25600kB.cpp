#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int a,b,c;
int l,r;
int x[1000005];
int que[1000005];
int dp[1000005];
inline int X(int j){
	return x[j];
}
inline int Y(int j){
	return dp[j]+a*x[j]*x[j]-b*x[j];
}
inline int B(int i){
	return dp[i]-a*x[i]*x[i]-b*x[i]-c;
}
inline int K(int i){
	return 2*x[i]*a;
}
signed main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	#endif
	int t=read();
	while(t--){
	l=r=0;
    int n=read();
	a=read();
	b=read();
	c=read();
	for(int i=1;i<=n;i++){
		x[i]=read();
		x[i]+=x[i-1];
	}
	for(int i=1;i<=n;i++){
		while(l<r&&Y(que[l])-Y(que[l+1])<K(i)*(X(que[l])-X(que[l+1]))){
			l++;
		}
		int &j=que[l];
		int XX=x[i]-x[j];
		dp[i]=dp[j]+a*(XX*XX)+b*XX+c;
		while(l<r&&((Y(que[r])-Y(que[r-1]))*(X(que[r])-X(i)))>((Y(que[r])-Y(i))*(X(que[r])-X(que[r-1])))){
			r--;
		}
		que[++r]=i;
	}
	printf("%lld\n",dp[n]);
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


