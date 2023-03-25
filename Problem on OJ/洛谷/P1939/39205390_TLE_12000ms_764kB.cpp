
#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
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
const int maxn = 3;
const int mod = 1000000007;
struct Matrix{
    unsigned long long a[maxn+5][maxn+5];
    void init(){ 
        memset(a, 0, sizeof(a));
        for(int i=0;i<maxn;++i){
            a[i][i] = 1;
        }
    }
};

Matrix mul(Matrix a, Matrix b){
    Matrix ans;
    for(int i=0;i<maxn;++i){
        for(int j=0;j<maxn;++j){
            ans.a[i][j] = 0;
            for(int k=0;k<maxn;++k){
                ans.a[i][j] += a.a[i][k] * b.a[k][j];
                ans.a[i][j] %= mod; 
            }
        }
    } 
    return ans;
}
Matrix qpow(Matrix a, int n){
    Matrix ans;
    ans.init();
    while(n){
        if(n&1) ans = mul(ans, a);
        a = mul(a, a);
        n /= 2;
    } 
    return ans;
}
signed main(){
    freopen(".in","r",stdin);
	freopen("war.out","w",stdout);
    int T=read();
    while(T--){
    Matrix a;
    a.a[0][0] = 1;
    a.a[0][1] = 0;
    a.a[0][2] = 1;
    a.a[1][0] = 1;
    a.a[1][1] = 0;
    a.a[1][2] = 0;
    a.a[2][0] = 0;
    a.a[2][1] = 1;
    a.a[2][2] = 0;
    unsigned  long long n;
	n=read();
    if(n<=3){
    	cout<<1<<endl;
    	continue;
    }
    Matrix ans = qpow(a, n-3); 
    Matrix b;
    b.a[0][0]=b.a[0][1]=b.a[0][2]=1;
    ans=mul(b,ans);
    cout<<ans.a[0][0]%mod<<endl;
    }
    return 0;
}
