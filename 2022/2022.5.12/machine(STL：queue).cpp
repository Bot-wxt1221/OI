#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int book[1003] = {0}; //�� book����ڴ�����û�е��ʣ�book[i]=1 ��ʾ���� i ���ڴ���
queue<int> mem; //�ö���ģ���ڴ�
int main(){
	freopen("machine.in", "r", stdin);
	freopen("machine.out", "w", stdout);
	int m, n;
	scanf("%d%d", &m, &n);
	int cnt = 0; //��ʵ�Ĵ���
	while(n--){
		int en;
		scanf("%d", &en); //����һ��Ӣ�ĵ���
		if(!book[en]){ //����ڴ���û���������
			++cnt;
			mem.push(en); //���ʽ����У��ŵ�����β��
			book[en]=1; //��¼�ڴ������������
			while(mem.size() > m){ //�ڴ�����
				book[mem.front()] = 0; //���ڴ���ȥ������
				mem.pop(); //�Ӷ�ͷȥ��
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}

/*
����:
3 7
1 2 1 5 4 4 1

���:
5
*/
