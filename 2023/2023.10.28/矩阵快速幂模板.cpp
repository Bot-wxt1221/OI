struct matrix{ int m[N][N]; };     //定义矩阵，常数N是矩阵的行数和列数
matrix operator * (const matrix& a, const matrix& b){   //重载*为矩阵乘法。注意const
    matrix c;   
    memset(c.m, 0, sizeof(c.m));  //清零
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            for(int k = 0; k<N; k++)
              //c.m[i][j] += a.m[i][k] * b.m[k][j];                   //不取模
                c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % mod;//取模
    return c;
}

matrix pow_matrix(matrix a, int n){  //矩阵快速幂，代码和普通快速幂几乎一样
    matrix ans;   
    memset(ans.m,0,sizeof(ans.m));
    for(int i=0;i<N;i++)  ans.m[i][i] = 1; //初始化为单位矩阵，类似普通快速幂的ans=1
    while(n) {
        if(n&1) ans = ans * a;       //不能简写为ans *= a，这里的*重载了
        a = a * a;
        n>>=1;
    }
    return ans;
}


