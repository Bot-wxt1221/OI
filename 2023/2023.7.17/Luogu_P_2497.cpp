#include <iostream>
#include <cstdio>
#include <cmath>
#include <deque>
#define int long long
inline int read();
int x[500005];
int r[500005];
int v[500005];
int a[500005];
int temp[500005];
double dp[500005];
int qu[2000005];
int head,tail;
double X(int i){
    return 1.0/(2*std::sqrt(r[i]));
}
double Y(int i){
    return -dp[i]+(double(x[i]))/(2*std::sqrt(r[i]));
}
double K(int i){
    return x[i];
}
double B(int i){
    return v[i];
}
bool cmp(int i,int j,int i2,int j2){
    // return (Y(i)-Y(j))/(X(i)-X(j))<(Y(i2)-Y(j2))/(X(i2)-X(j2));
    return (Y(i)-Y(j))*(X(i2)-X(j2))<(Y(i2)-Y(j2))*(X(i)-X(j));
}
void cdq(int l,int r){
    if(l>=r){
        return ;
    }
    int mid=(l+r)/2;
    cdq(l,mid);
    head=tail=0;
    for(int i=l;i<=mid;i++){
        while(head>tail&&cmp(i,qu[head],qu[head],qu[head-1])){
            head--;
        }
        qu[++head]=i;
    }
    for(int i=mid+1;i<=r;i++){
        while(head>tail&&x[i]*(X(qu[tail+1])-X(qu[tail+2]))<(Y(qu[tail+1])-Y(qu[tail+2]))){
            tail++;
        }
        int j=qu[tail+1];
        double to=(dp[j]+v[i]+((x[i]-x[j])/(2*std::sqrt(::r[j]))));
        dp[i]=std::min(dp[i],to);
    }
    cdq(mid+1,r);
    int l1=l,l2=mid+1;
    int now=l-1;
    while(l1<=mid&&l2<=r){
        if(a[l1]>=a[l2]){
            temp[++now]=a[l1];
            l1++;
        }else{
            temp[++now]=a[l2];
            l2++;
        }
    }
    while(l1<=mid){
        temp[++now]=a[l1];
        l1++;
    }
    while(l2<=r){
        temp[++now]=a[l2];
        l2++;
    }
    for(int i=l;i<=r;i++){
        a[i]=temp[i];
    }
    
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	int n=read(),m;
    m=read();
    for(int i=1;i<=n;i++){
        x[i]=read();
        r[i]=read();
        v[i]=read();
        a[i]=r[i];
        dp[i]=0x3f3f3f3f;
    }
    dp[1]=v[1];
    cdq(1,n);
    double ans=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        if(r[i]+x[i]>=m){
            ans=std::min(ans,dp[i]);
        }
    }
    printf("%.3lf",ans);
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


