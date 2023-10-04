#include<bits/stdc++.h>
using namespace std;
int D[5000][5000];     //差分数组
//int a[5000][5000];   //原数组，不定义也行
int main(){
    int n,m;    scanf("%d%d",&n,&m);
    while(m--){
        int x1, y1, x2, y2;   scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        D[x1][y1]   += 1;   D[x2+1][y1]   -= 1;
        D[x1][y2+1] -= 1;   D[x2+1][y2+1] += 1;//计算差分数组
    }
    //不用差分递推公式，直接求前缀和 
	for(int i = 1; i <= n; ++i) { 
        for(int j = 1; j < n; ++j) {   //注意这里是 j<n 
            D[i][j+1] += D[i][j];  //把i看作定值，先累加计算j方向             
        }
    }
    for(int j = 1; j <= n; ++j) { 
        for(int i = 1; i < n; ++i) {   //注意这里是 i<n 
            D[i+1][j] += D[i][j];  //把j看作定值，再累加计算i方向             
        }
    }
    for(int i = 1; i <= n; ++i) {  //打印 
        for(int j = 1; j <= n; ++j) {   //注意这里是 j<n 
            printf("%d ", D[i][j]);             
        }
        printf("\n");
	}
	  
    return 0;
}

