#include <iostream>
#include <cstdio>
#include <set>
#define int long long
inline int read();
int a[100005];
int ans;
int temp[100005];
void sort(int l,int r){
    if(l>=r){
        return ;
    }
    int mid=(l+r)/2;
    sort(l,mid);
    sort(mid+1,r);
    int l1=l,l2=mid+1,l3=0;
    while(l1<=mid&&l2<=r){
        if(a[l1]>=a[l2]){
            temp[++l3]=a[l2++];
        }else{
            temp[++l3]=a[l1++];
            ans+=(r-l2+1);
        }
    }
    while(l1<=mid){
        temp[++l3]=a[l1++];
        // ans+=(r-l2+1);
    }
    while(l2<=r){
        temp[++l3]=a[l2++];
    }
    for(int i=l;i<=r;i++){
        a[i]=temp[i-l+1];
    }
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("snooker.in","r",stdin);
	freopen("snooker.out","w",stdout);
	#endif
    int n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=read()-m;
        a[i]+=a[i-1];
    }
    sort(1,n);
    for(int i=1;i<=n;i++){
        if(a[i]>0){
            ans++;
        }
    }
    printf("%lld",ans);
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


