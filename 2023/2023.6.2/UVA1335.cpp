#include <iostream>
#include <cstdio>
inline int read();
int n;
int b[100005];
int left[100005];
int right[100005];
bool check(int p){
    left[1]=b[1];
    right[1]=0;
    for(int i=2;i<=n;i++){
        if(i%2==1){
            right[i]=std::min(p-b[1]-right[i-1],b[i]);
            left[i]=b[i]-right[i];
        }else{
            left[i]=std::min(b[1]-left[i-1],b[i]);
            right[i]=b[i]-left[i];
        }
    }
    return left[n]==0;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    while(scanf("%d",&n)!=EOF&&n!=0){
        int ans=0;
        b[1]=read();
        for(int i=2;i<=n;i++){
            b[i]=read();
            ans=std::max(ans,b[i]+b[i-1]);
        }
        ans=std::max(ans,b[n]+b[1]);
        if(n==1){
            printf("%d\n",b[1]);
        }
        if(n%2==0){
            printf("%d\n",ans);
        }else{
            int l=ans,r=3*ans;
            while(l+3<r){
                int mid=(l+r)/2;
                if(check(mid)){
                    r=mid+1;
                }else{
                    l=mid-1;
                }
            }
            for(int i=l;i<=r;i++){
                if(check(i)){
                    printf("%d\n",i);
                    goto a;
                }
            }
            a:{};
        }
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
            .cph
		Out:
            .cph
More:

*/


