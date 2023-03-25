/*
矩阵快速幂模板 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;

const int maxn = 2;
const int mod = 1000000007;

//矩阵结构体 
struct Matrix{
    unsigned long long a[maxn+5][maxn+5];
    void init(){    //初始化为单位矩阵 
        memset(a, 0, sizeof(a));
        for(int i=0;i<maxn;++i){
            a[i][i] = 1;
        }
    }
};

//矩阵乘法 
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

//矩阵快速幂 
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
    Matrix a;
    a.a[0][0] = 1;
    a.a[0][1] = 1;
    a.a[1][0] = 1;
    a.a[1][1] = 0;
    unsigned  long long n;
	cin>>n;
    if(n<=2){
    	cout<<1;
    	return 0;
    }
    Matrix ans = qpow(a, n-2); 
    Matrix b;
    b.a[0][0]=b.a[0][1]=1;
    b.a[1][0]=b.a[1][1]=0;
    ans=mul(b,ans);
    cout<<ans.a[0][0]%mod;
    return 0;
}

