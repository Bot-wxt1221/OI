//��ɢ��ʾ��
#include<bits/stdc++.h>
const int N = 500010;   //�Լ�����һ����Χ
struct data {
	int val;              //Ԫ�ص�ֵ
	int id;               //Ԫ�ص�λ��
} olda[N];              //��ɢ��֮ǰ��ԭʼ����
int newa[N];            //��ɢ����Ľ��
bool cmp(data x,data y) {
	return x.val < y.val;    //����sort()
}
int main() {
	int n;
	scanf("%d",&n);                  //��Ԫ�ظ���
	for(int i=1; i<=n; i++) {
		scanf("%d",&olda[i].val);                //��Ԫ�ص�ֵ
		olda[i].id = i;                          //��¼Ԫ�ص�λ��
	}
	std::sort(olda+1,olda+1+n,cmp);              //��Ԫ�ص�ֵ����
	for(int i=1; i<=n; i++) {                    //���� newa[]
		newa[olda[i].id]=i; //���Ԫ��ԭ����λ����olda[i].id��������ֵ��Ϊi��i����ɢ�������ֵ
		if(olda[i].val == olda[i-1].val)          //������Ԫ�ص�ԭֵ��ͬ������ֵ��Ϊ��ͬ
			newa[olda[i].id] = newa[olda[i-1].id];
	}
	for(int i=1; i<=n; i++)  printf("%d ",newa[i]); //��ӡ��������
	return 0;
}

