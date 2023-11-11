struct matrix{ int m[N][N]; };     //������󣬳���N�Ǿ��������������
matrix operator * (const matrix& a, const matrix& b){   //����*Ϊ����˷���ע��const
    matrix c;   
    memset(c.m, 0, sizeof(c.m));  //����
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            for(int k = 0; k<N; k++)
              //c.m[i][j] += a.m[i][k] * b.m[k][j];                   //��ȡģ
                c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % mod;//ȡģ
    return c;
}

matrix pow_matrix(matrix a, int n){  //��������ݣ��������ͨ�����ݼ���һ��
    matrix ans;   
    memset(ans.m,0,sizeof(ans.m));
    for(int i=0;i<N;i++)  ans.m[i][i] = 1; //��ʼ��Ϊ��λ����������ͨ�����ݵ�ans=1
    while(n) {
        if(n&1) ans = ans * a;       //���ܼ�дΪans *= a�������*������
        a = a * a;
        n>>=1;
    }
    return ans;
}


