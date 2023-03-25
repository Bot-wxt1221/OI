/*
矩阵快速幂模板 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 2;
const int mod = 1000000007;

//矩阵结构体 
struct Matrix{
    int a[maxn][maxn];
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

void output(Matrix a){
    for(int i=0;i<maxn;++i){
        for(int j=0;j<maxn;++j){
            cout << a.a[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    Matrix a;
    a.a[0][0] = 1;
    a.a[0][1] = 1;
    a.a[1][0] = 1;
    a.a[1][1] = 0;
    int n;
	cin>>n;
    Matrix ans = qpow(a, 10); 
    int aa=1, bb=1;
    int temp;
    int num = 3;   
    while(num<=n){
        temp = bb;
        bb = aa + bb;
        aa = temp;
        ++num;
    }
    cout<<bb;
    return 0;
}

