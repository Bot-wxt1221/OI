/*
矩阵快速幂模板 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 2;
const int mod = 10000;

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
    
    Matrix ans = qpow(a, 10); 
    cout << "a = ";
    output(ans);
    
    cout << "f(12) = [f(2), f(1)] = [1, 1] * a^10 = " << ans.a[0][0] + ans.a[1][0]; 
    
    cout << endl;
    cout << "斐波那契：" << endl;
    int aa=1, bb=1;
    int temp;
    cout << "f(1) = 1" << endl;
    cout << "f(2) = 1" << endl;
    int num = 3;   
    while(bb<200){
        temp = bb;
        bb = aa + bb;
        aa = temp;
        cout << "f(" << num << ") = " << bb << endl;
        ++num;
    }
    return 0;
}


