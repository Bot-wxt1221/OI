#include<bits/stdc++.h>
using namespace std;
int D[5000][5000];     //�������
//int a[5000][5000];   //ԭ���飬������Ҳ��
int main(){
    int n,m;    scanf("%d%d",&n,&m);
    while(m--){
        int x1, y1, x2, y2;   scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        D[x1][y1]   += 1;   D[x2+1][y1]   -= 1;
        D[x1][y2+1] -= 1;   D[x2+1][y2+1] += 1;//����������
    }
    //���ò�ֵ��ƹ�ʽ��ֱ����ǰ׺�� 
	for(int i = 1; i <= n; ++i) { 
        for(int j = 1; j < n; ++j) {   //ע�������� j<n 
            D[i][j+1] += D[i][j];  //��i������ֵ�����ۼӼ���j����             
        }
    }
    for(int j = 1; j <= n; ++j) { 
        for(int i = 1; i < n; ++i) {   //ע�������� i<n 
            D[i+1][j] += D[i][j];  //��j������ֵ�����ۼӼ���i����             
        }
    }
    for(int i = 1; i <= n; ++i) {  //��ӡ 
        for(int j = 1; j <= n; ++j) {   //ע�������� j<n 
            printf("%d ", D[i][j]);             
        }
        printf("\n");
	}
	  
    return 0;
}

