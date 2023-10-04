#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
inline int read();
int a[200006];
int shu[200005];
int _bit(int a){
    return (a)&(-a);
}
int query(int i){
    int ans=0;
    while(i>0){
        ans+=shu[i];
        i-=_bit(i);
    }
    return ans;
}
void add(int i,int too){
    while(i<=200001){
        shu[i]+=too;
        i+=_bit(i);
    }
    return ;
}

int dp[200005];
int fr[200005];
int bk[200005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        a[i]=1+read();
    }
    int ans=0;
    dp[0]=0;
    for(int i=1;i<=n;i++){
        if(a[i]>dp[ans]){
            dp[++ans]=a[i];
        }
        int l=0,r=ans+1;
        int mid;
        while(r-l>1){
            mid=l+(r-l)/2;
            if(dp[mid]<a[i]){
                l=mid;
            }else{
                r=mid;
            }
        }
        dp[l+1]=std::min(dp[l+1],a[i]);
    }
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++){
        fr[i]=query(a[i]-1);
        add(a[i],1);
    }
    memset(shu,0,sizeof(shu));
    for(int i=n;i>=1;i--){
        bk[i]=query(a[i]-1);
        add(a[i],1);
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=fr[i]*bk[i];
    }
    printf("%lld\n",sum);
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


