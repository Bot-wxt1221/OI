//hdu 1556�ò���������
#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N],D[N];               //a������D�ǲ������
int main() {
	int n;
	while(~scanf("%d",&n)) {
		memset(a,0,sizeof(a));
		memset(D,0,sizeof(D));
		for(int i=1; i<=n; i++) {
			int L,R;
			scanf("%d%d",&L,&R);
			D[L]++;
			D[R+1]--;             //�����޸�
		}
		for(int i=1; i<=n; i++) {            //��ԭ����
			a[i] = a[i-1] + D[i];            //��֡���ǰ׺��a[]��a[i]��������i��ֵ
			if(i!=n)  printf("%d ", a[i]);   //�����ӡ���
			else      printf("%d\n",a[i]);
		}          //С���ɣ�14�е�17�У���a[]�ĳ�D[]Ҳ��
	}
	return 0;
}

