#include <cstdio>
#include <iostream>
using namespace std;

struct node{
	int data;
	int next;
};

int main(){
	struct node linklist[101];
	int n;
	//�������е���
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &linklist[i].data);
	int len = n;
	//��ʼ���ṹ�������next���� 
	for(int i = 1; i <= n; i++){
		if(i != n) linklist[i].next = i + 1;
		else linklist[i].next = 0;
	}
	//ֱ���ڽṹ������linklist��ĩβ����һ����
	len++;
	scanf("%d", &linklist[len].data);
	//�������ͷ����ʼ����
	int t = 1;
	while(t != 0){
		if(linklist[linklist[t].next].data > linklist[len].data){//�����ǰ�����һ������ֵ���ڴ����������������뵽�м�
			linklist[len].next = linklist[t].next;//�²���������һ������ŵ��ڵ�ǰ������һ�������
			linklist[t].next = len;//��ǰ������һ������ž����²������ı��
			break;//�����������ѭ��
		}
		t = linklist[t].next;
	}
	//������������е���
	t = 1;
	while(t != 0){
		printf("%d ", linklist[t].data);
		t = linklist[t].next;
	}
	
	return 0;
}
