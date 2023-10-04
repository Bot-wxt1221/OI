//���P1540, STL queue
#include<bits/stdc++.h>
using namespace std;

int Hash[1003] = {0}; //�ù�ϣ����ڴ�����û�е��ʣ�hash[i]=1��ʾ����i���ڴ���
queue<int> mem;      //�ö���ģ���ڴ�

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	int cnt = 0;                         //��ʵ�Ĵ���
	while(n--) {
		int en;
		scanf("%d", &en);       //����һ��Ӣ�ĵ���
		if(!Hash[en]) {                  //����ڴ���û���������
			++cnt;
			mem.push(en);                //���ʽ����У��ŵ�����β��
			Hash[en]=1;                  //��¼�ڴ������������
			while(mem.size()>m) {        //�ڴ�����
				Hash[mem.front()] = 0;   //���ڴ���ȥ������
				mem.pop();               //�Ӷ�ͷȥ��
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}

