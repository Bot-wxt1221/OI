#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	int data[101], right[101];
	int n;
	//�������е���
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &data[i]);
	int len = n;
	//��ʼ������right
	for(int i = 1; i <= n; i++){
		if(i != n)	right[i] = i + 1;
		else right[i] = 0;
	}
	//ֱ��������data��ĩβ����һ����
	len++;
	scanf("%d", &data[len]);
	//�������ͷ����ʼ����
	int t = 1;
	while(t != 0){
		if(data[right[t]] > data[len]){//�����ǰ�����һ������ֵ���ڴ����������������뵽�м�
			right[len] = right[t];//�²���������һ������ŵ��ڵ�ǰ������һ�������
			right[t] = len;//��ǰ������һ������ž����²������ı��
			break;//�����������ѭ��
		}
		t = right[t];
	}
	//������������е���
	t = 1;
	while(t != 0){
		printf("%d ", data[t]);
		t = right[t];
	}
	
	return 0;
}
