#include<bits/stdc++.h>
using namespace std;
int D[5000][5000];     //差分数组
//int a[5000][5000];   //原数组，不定义也行
int main(){
    int n,m;    scanf("%d%d",&n,&m);
    while(m--){
        int x1,y1,x2,y2;   scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        D[x1][y1]   += 1;   D[x2+1][y1]   -= 1;
        D[x1][y2+1] -= 1;   D[x2+1][y2+1] += 1;//计算差分数组
    }
    for(int i=1;i<=n;++i){//根据差分数组计算原矩阵的值（想象成求小格子的面积和）
        for(int j=1;j<=n;++j){ //把用过的D[][]看成a[][]，就不用再定义a[][]了
            //a[i][j] = D[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            //printf("%d ",a[i][j]);       //这两行和下面两行的效果一样
            D[i][j] += D[i-1][j] + D[i][j-1] - D[i-1][j-1];
            printf("%d ",D[i][j]);
        }
        printf("\n");//换行
    }
    return 0;
}

