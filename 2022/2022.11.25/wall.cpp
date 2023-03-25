#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
inline int read();
const int maxn=3;
int mod=10000;
struct Matrix{
    unsigned long long a[maxn+5][maxn+5];
    int n,m;
    Matrix(int nn=5,int mm=5){ 
        n=nn;
        m=mm;
        memset(a, 0, sizeof(a));
        for(int i=1;i<=maxn;++i){
            a[i][i] = 1;
        }
    }
};

Matrix mul(Matrix a, Matrix b){
    Matrix ans(a.n,b.m);
    for(int i=1;i<=a.n;++i){
        for(int j=1;j<=b.m;++j){
            ans.a[i][j] = 0;
            for(int k=1;k<=a.m;++k){
                ans.a[i][j] += a.a[i][k] * b.a[k][j];
                ans.a[i][j] %= mod; 
            }
        }
    } 
    return ans;
}
Matrix qpow(Matrix a, int n){
    if(n==0){
        Matrix m(a.n,a.n);
        return m;
    }
    if(n%2==0){
        Matrix temp=qpow(a,n/2);
        return mul(temp,temp);
    }
    return mul(qpow(a,n-1),a);
}
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen("wall.in","r",stdin);
	freopen("wall.out","w",stdout);
	#endif
    int n=read();
    if(n==1){
        printf("1");
        return 0;
    }   
    if(n==2){
        printf("2");
        return 0;
    }
    n-=3;
    Matrix po(3,3),yuan(1,3);
    po.a[2][1]=po.a[2][3]=1;
    po.a[3][1]=2;
    po.a[2][2]=0;
    po.a[1][2]=1;
    po=qpow(po,n);
    yuan.a[1][1]=5;
    yuan.a[1][2]=2;
    yuan.a[1][3]=2;
    yuan=mul(yuan,po);
    if(yuan.a[1][1]<1000&&n>=10){
        putchar('0');
    }
    if(yuan.a[1][1]<100&&n>=10){
        putchar('0');
    }
    if(yuan.a[1][1]<10&&n>=10){
        putchar('0');
    }
    printf("%d",yuan.a[1][1]);
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


