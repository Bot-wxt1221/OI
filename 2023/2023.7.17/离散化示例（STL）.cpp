#include<bits/stdc++.h>
using namespace std;
const int N = 500010;  // �Լ�����һ����Χ
int olda[N];           // ��ɢ��ǰ
int newa[N];           // ��ɢ����
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&olda[i]);      //��Ԫ�ص�ֵ
		newa[i] = olda[i];
	}
	sort(olda+1,olda+1+n);         //����
	int cnt = n;
	//cnt = unique(olda+1,olda+1+n)-(olda+1);  //ȥ�أ�cnt��ȥ�غ������
	for(int i=1; i<=cnt; i++)                //���� newa[]
		newa[i]=lower_bound(olda+1,olda+1+n,newa[i])-olda;
	//������ȵ�Ԫ�ص�λ�ã����λ�þ�����ɢ�������ֵ
	for(int i=1; i<=cnt; i++)   printf("%d ",newa[i]); //��ӡ��������
	printf("\n cnt=%d",cnt);
	return 0;
}

