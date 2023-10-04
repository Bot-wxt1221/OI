#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
inline int read();
std::queue<int>a;
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int T=read();
    while(T--){
        a=std::queue<int>();
        int n=read();
        int s=read();
        int sum=0;
        int ans=0x3f3f3f3f3f3f3f3fll;
        for(int i=1;i<=n;i++){
            int temp=read();
            if(sum<s){
                a.push(temp);
                sum+=temp;
                if(sum>=s){
                    while(sum-a.front()>=s){
                        sum-=a.front();
                        a.pop();
                    }
                    ans=std::min(ans,(int)(a.size()));
                }
            }else{
                a.push(temp);
                sum+=temp;
                while(sum-a.front()>=s){
                    sum-=a.front();
                    a.pop();
                }
                ans=std::min(ans,(int)(a.size()));
            }
        }
        if(ans==0x3f3f3f3f3f3f3f3fll){
            printf("0\n");
        }else
            printf("%lld\n",ans);
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


