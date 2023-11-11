#include<cstdio>
#include<algorithm>
#include<cstring>
const int INF=0x3f;
const int N=120;
int Hash[1005],cnt=0;                //������ɢ��
struct matrix{int m[N][N]; };        //�������
matrix operator *(const matrix& a, const matrix& b){   //����������˷�
    matrix c;
    memset(c.m,INF,sizeof c.m);
    for(int i=1;i<=cnt;i++)          //i��j��k���Եߵ�����Ϊ��c��˵��һ��
        for(int j=1;j<=cnt;j++)
            for(int k=1;k<=cnt;k++)
               c.m[i][j] = std::min(c.m[i][j], a.m[i][k] + b.m[k][j]);
    return c;
}
matrix pow_matrix(matrix a, int n){  //��������ݣ��������Ǳ�׼�Ŀ�����д��
    matrix ans = a;                  //�����ֵans = M^1
    n--;                             //��һ��ans= M^1����һ��
    while(n) {                       //����˷���M^n
        if(n&1) ans = ans * a;
        a = a * a;
        n>>=1;
    }
    return ans;
}
int main(){
    int n,t,s,e;    scanf("%d%d%d%d",&n,&t,&s,&e);
    matrix a;                                //�þ����ͼ
    memset(a.m,INF,sizeof a.m);
    while(t--){
        int u,v,w;     scanf("%d%d%d",&w,&u,&v);
        if(!Hash[u])   Hash[u] = ++cnt;      //�Ե���ɢ��.  cnt�����µĵ���
        if(!Hash[v])   Hash[v] = ++cnt;
        a.m[Hash[u]][Hash[v]] = a.m[Hash[v]][Hash[u]] = w;
    }
    matrix ans = pow_matrix(a,n);
    printf("%d",ans.m[Hash[s]][Hash[e]]);
    return 0;
}

