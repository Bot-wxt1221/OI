/*
���������εı߳�Ϊ 3 ����, ����ͼ�� 
a b c d
e f g h
i j k l  
m n o p
���һ��ʼ�Ѿ��� a �ƶ��� b����ô��Ҫ�� bdpn �������������
��һ���� b �����ֱ𷵻ص� f��j��n ��·�������ܱ������ʼ·
���غϣ�������� b����ô·��һ���� b �� a����������Ҫ�󲻷�����
������ص� f����ô����·���� f �� e �� a ��������ص� j������
j �� i �� e �� a ��������ص� n������ n �� m �� i �� e �� a��
�����⼸�������·������������ 1 ��·�������仰˵��ֻҪ�����
b ��������ֱ𷵻ص� f��j��n ��·������Ȼ������Ӿ����������
�𰸣��Ѿ��� a �ƶ��� e ���������������ζԳƣ��������մ���
����һ�������µ�·��������������

��������� b �������ص� f ��·����������ʱ�Ѿ��� b �ƶ���c��
��ô���൱���� cdpo ������������� c �����ֱ𷵻ص�g��k��o ��·
�������������Ѿ��� b �ƶ��� f���������� f �������ص� f ��·����
Ҳ���Ǽ��� fhpm ��������Σ����ݹ���̵� ��ǰһ���������ɡ�
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define SIZE 10
using namespace std;
long long route(int width, int height, int back_y);

int main(){
	int square;
	cin >> square;	
	cout << route(square, square, 0);
	return 0;
}

long long route(int width, int height, int back_y){
	if(width == 1) return (back_y == height) ? back_y : back_y + 2;
	if(height == 1) return (back_y == 0) ? 2 : 1;
	long long total = 0LL;
	if(back_y == 0){
		for(int i = 0; i < height; i++){
			total += 2 * route(width - 1, height, i + 1);
		}
	}
	else{
		for(int i = back_y; i <= height; i++){
			total += route(width - 1, height, i);
		}
		total += route(width, height - 1, back_y - 1);
	}
	return total;
}
