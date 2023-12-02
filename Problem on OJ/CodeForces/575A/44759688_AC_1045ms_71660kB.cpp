#include <iostream>
#include <cstdio>
#include <algorithm>
inline long long read();
long long s[50005],p;
class node{
    public:
        long long i,num;
        bool kind;
        node(long long xx=0,long long yy=0,bool zz=0){
            i=xx;
            num=yy;
            kind=zz;
            return ;
        }
}ss[100005];
bool cmp(node a,node b){
    return a.i<b.i;
}
class Matrix{
    public:
        long long map[4][4];
        Matrix(){
            for(long long i=1;i<=2;i++){
                for(long long j=1;j<=2;j++){
                    map[i][j]=0;
                    if(i==j){
                        map[i][j]=1;
                    }
                }
            }
            return ;
        }
}seq[50005],one;
Matrix operator * (Matrix a,Matrix b){
    Matrix ans;
    for(long long i=1;i<=2;i++){
        for(long long j=1;j<=2;j++){
            ans.map[i][j]=0;
            for(long long k=1;k<=2;k++){
                ans.map[i][j]+=(a.map[i][k]*b.map[k][j])%p;
                ans.map[i][j]%=p;
            }
        }
    }
    return ans;
}
Matrix tree[500005];
void build(long long now,long long l,long long r){
    if(l>r){
        return ;
    }
    if(l==r){
        tree[now]=seq[l];
        return ;
    }
    long long mid=(l+r)/2;
    build(now*2,l,mid);
    build(now*2+1,mid+1,r);
    tree[now]=tree[now*2]*tree[now*2+1];
    return ;
}
long long tomod;
void mod(long long now,long long l,long long r){
    if(l>r){
        return ;
    }
    if(l==r&&r==tomod){
        tree[now]=seq[l];
        return ;
    }
    if(r<tomod||tomod<l){
        return ;
    }
    long long mid=(l+r)/2;
    if(l<=tomod&&tomod<=mid){
        mod(now*2,l,mid);
    }else{
        mod(now*2+1,mid+1,r);
    }
    tree[now]=tree[now*2]*tree[now*2+1];
    return ;
}
long long ll,rr;
Matrix getans(long long now,long long l,long long r){
    if(l>r){
        return one;
    }
    if(r<ll||l>rr){
        return one;
    }
    if(ll<=l&&r<=rr){
        return tree[now];
    }
    long long mid=(l+r)/2;
    return getans(now*2,l,mid)*getans(now*2+1,mid+1,r);
}
Matrix pow(Matrix a,long long b){
    if(b==0){
        return one;
    }
    if(b&1){
        return pow(a,b-1)*a;
    }
    Matrix temp=pow(a,b/2);
    return temp*temp;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	#endif
    long long k=read();
    if(k==0){
        printf("%lld",0ll);
        return 0;
    }
    p=read();
    long long n=read();
    for(long long i=0;i<n;i++){
        s[i]=read()%p;
    }
    Matrix ysumm;
    for(long long i=0;i<n;i++){
        seq[i].map[1][1]=s[i];
        if(i-1>=0)
            seq[i].map[2][1]=s[i-1];
        else{
            seq[i].map[2][1]=s[n-1];
        }
        seq[i].map[1][2]=1;
        seq[i].map[2][2]=0;
        ysumm=ysumm*seq[i];
    }
    build(1,0,n-1);
    long long m=read();
    for(long long i=1;i<=m;i++){
        ss[i*2-1].i=read();
        ss[i*2-1].num=read()%p;
        ss[i*2-1].kind=0;
        ss[i*2].i=ss[i*2-1].i+1;
        ss[i*2].num=ss[i*2-1].num;
        ss[i*2].kind=1;
    }
    m=m*2;
    ss[++m].i=0;
    ss[m].kind=1;
    ss[m].num=1;
    std::sort(ss+1,ss+m+1,cmp);
    while(ss[m].i>=k){
        m--;
    }
    Matrix ans;
    ans.map[1][2]=1;
    ans.map[1][1]=ans.map[2][1]=ans.map[2][2]=0;
    bool fhave=0;
    long long li=1;
    ss[m+1].i=0x3f3f3f3f;
    for(long long i=1;i<=m;i++){
        if(ss[i].kind){
            seq[ss[i].i%n].map[2][1]=ss[i].num;
            tomod=ss[i].i%n;
            mod(1,0,n-1);
        }else{
            seq[ss[i].i%n].map[1][1]=ss[i].num;
            tomod=ss[i].i%n;
            mod(1,0,n-1);
        }
        if(ss[i].i/n!=ss[i+1].i/n&&(i!=m||k/n!=ss[m].i/n)){
            ll=0,rr=n-1;
            Matrix temp=ans*seq[0]*seq[1];
            temp=temp*seq[2];
            ans=ans*getans(1,0,n-1);
            if(i!=m)
                ans=ans*pow(ysumm,((ss[i+1].i/n)-(ss[i].i/n)-1));
            for(long long j=li;j<=i;j++){
                if(ss[j].kind){
                    if(ss[j].i%n!=0){     
                        seq[ss[j].i%n].map[2][1]=s[ss[j].i%n-1];
                    }else{
                        seq[ss[j].i%n].map[2][1]=s[n-1];
                    }
                    tomod=ss[j].i%n;
                    mod(1,0,n-1);
                }else{
                    seq[ss[j].i%n].map[1][1]=s[ss[j].i%n];
                    tomod=ss[j].i%n;
                    mod(1,0,n-1);
                }
            }
            temp=getans(1,0,n-1);
            li=i+1;
        }
    }
    if(k/n==ss[m].i/n){
        ll=0,rr=k%n-1;
        ans=ans*getans(1,0,n-1);
        printf("%lld",ans.map[1][1]);
        return 0;
    }
    if((((k)/n)-(ss[m].i/n))-1>=0){
        ans=ans*pow(ysumm,((k/n)-(ss[m].i/n))-1);
        // ans=ans*(seq[0]*seq[1]*seq[2]);
    }
    long long now=((k)/n)*n;
    for(long long i=now;i<k;i++){
        ans=ans*seq[i%n];
    }
    printf("%lld",ans.map[1][1]);
	return 0;
}
inline long long read(){
	long long x=0,f=1;char c=getchar();
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


