#include<cstdio>
#include<algorithm>
#include<cstring>
const int INF=0x3f;
const int N=120;
int Hash[1005],cnt=0;                //用于离散化
struct matrix{int m[N][N]; };        //定义矩阵
matrix operator *(const matrix& a, const matrix& b){   //定义广义矩阵乘法
    matrix c;
    memset(c.m,INF,sizeof c.m);
    for(int i=1;i<=cnt;i++)          //i、j、k可以颠倒，因为对c来说都一样
        for(int j=1;j<=cnt;j++)
            for(int k=1;k<=cnt;k++)
               c.m[i][j] = std::min(c.m[i][j], a.m[i][k] + b.m[k][j]);
    return c;
}
matrix pow_matrix(matrix a, int n){  //矩阵快速幂，几乎就是标准的快速幂写法
    matrix ans = a;                  //矩阵初值ans = M^1
    n--;                             //上一行ans= M^1多了一次
    while(n) {                       //矩阵乘法：M^n
        if(n&1) ans = ans * a;
        a = a * a;
        n>>=1;
    }
    return ans;
}
int main(){
    int n,t,s,e;    scanf("%d%d%d%d",&n,&t,&s,&e);
    matrix a;                                //用矩阵存图
    memset(a.m,INF,sizeof a.m);
    while(t--){
        int u,v,w;     scanf("%d%d%d",&w,&u,&v);
        if(!Hash[u])   Hash[u] = ++cnt;      //对点离散化.  cnt就是新的点编号
        if(!Hash[v])   Hash[v] = ++cnt;
        a.m[Hash[u]][Hash[v]] = a.m[Hash[v]][Hash[u]] = w;
    }
    matrix ans = pow_matrix(a,n);
    printf("%d",ans.m[Hash[s]][Hash[e]]);
    return 0;
}

