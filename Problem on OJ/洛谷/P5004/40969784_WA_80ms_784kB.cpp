#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int maxn ;
const int mod = 1000000007;
struct Matrix{
    unsigned long long a[20][15+5];
    void init(){ 
        memset(a, 0, sizeof(a));
        for(int i=1;i<=maxn;++i){
            a[i][i] = 1;
        }
    }
    void init(int aa){ 
        memset(a, 0, sizeof(a));
        for(int i=1;i<=maxn;++i){
            a[i][i] = aa;
        }
    }
};

Matrix mul(Matrix a, Matrix b){
    Matrix ans;
    for(int i=1;i<=maxn;++i){
        for(int j=1;j<=maxn;++j){
            ans.a[i][j] = 0;
            for(int k=1;k<=maxn;++k){
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
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read(),m=read();
    if(n<m+1){
        printf("%d\n",2);
        return 0;
    }
    Matrix temp;
    temp.init(0);
    for(int i=1;i<=m+1;i++){
        temp.a[1][i]=i+1;
    }
    Matrix p;
    p.init(0);
    maxn=m+1;
    for(int i = 1 ; i <= m ;i++)
    {
        p.a[i+1][i] = 1;
    }
    p.a[1][m+1] = 1;
    p.a[m+1][m+1] = 1;
    temp=mul(temp,qpow(p,n-m-1));
    printf("%lld",temp.a[1][m+1]);
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


