//hdu 1556�ò���������
#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int D[N];               //a������D�ǲ������
int main() {
	int n;
	while(~scanf("%d",&n)) {		
		memset(D, 0, sizeof(D));
		for(int i = 1; i <= n; i++) {
			int L, R;
			scanf("%d%d", &L, &R);
			D[L]++;
			D[R+1]--;             //�����޸�
		}
		for(int i = 1; i <= n; i++) {            //��ԭ����
			D[i] = D[i-1] + D[i];            //�����ǰ׺�ͣ����Ѿ�ʹ�ù��Ľ�С��D[]������������Լ�ռ� 
			if(i != n)  printf("%d ", D[i]);   //�����ӡ���
			else      printf("%d\n", D[i]);
		}          //С���ɣ�14�е�17�У���a[]�ĳ�D[]Ҳ��
	}
	return 0;
}

/*
���룺
3
1 1
2 2
3 3
3
1 1
1 2
1 3
0

�����
1 1 1
3 2 1
*/ 
