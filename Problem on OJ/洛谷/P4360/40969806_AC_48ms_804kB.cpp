#include <iostream>
#include <cstdio>
inline int read();
int l,r;
int que[20005];
int w[20006],s[20006],d[20005];
inline double slope(int j,int k){return 1.0*(d[j]*s[j]-d[k]*s[k])/(s[j]-s[k]);}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	#endif
    int n=read(),sum=0,ans=0x3f3f3f3f;
    for(register int i=1;i<=n;i++){
        w[i]=read();
        d[i]=read();
    }
    for(register int i=n;i>=1;i--){
        d[i]+=d[i+1];
    }
    for(register int i=1;i<=n;i++){
        s[i]=s[i-1]+w[i];
        sum+=w[i]*d[i];
    }
    for(register int i=1;i<=n;i++){
        while(l<r&&slope(que[l],que[l+1])>d[i]) ++l;
        int &j=que[l];
        ans=std::min(ans,sum-d[j]*s[j]-d[i]*(s[i]-s[j]));
        while(l<r&&slope(que[r-1],que[r])<slope(que[r],i)) --r;
        que[++r]=i;
    }
    printf("%d",ans);
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

