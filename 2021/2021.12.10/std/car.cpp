/*
�������Ĺؼ����ڣ��Ѿ�ͨ���ĵ�·�����ٴ�ͨ����Ҳ����˵��
��Ҫ���Ѿ�ͨ����λ�ü�¼���������⣬ֻ��ֱ�л�����ת�����
ҲҪ������һ���ƶ��ķ���
������ǰ� "���ߺ������Ƿ��Ѿ�ͨ��"�ֱ𱣴浽�����Ȼ
���ö���������ʾ��������ĺ��ߺ������Ƿ��Ѿ�ʹ�ù���
1---��ͨ����  0---û��ͨ��
����ǰ�з����õݹ������û���߹������е�·��
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#define SIZE 8
using namespace std;
int W, H; //��ȣ����������߶ȣ������� 
int DIR[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};  //ǰ�������ϡ����¡��� 

int Search(int x, int y, int dir, int left[], int bottom[]);
 
int main(){
	freopen("car.in", "r", stdin);
	freopen("car.out", "w", stdout);
	cin >> W >> H;
	int left[SIZE], bottom[SIZE];
	memset(left, 0, sizeof(left));   // �ö����Ʊ�ʾĳ�������Ƿ���ͨ��
	memset(bottom, 0, sizeof(bottom));	// �ö����Ʊ�ʾĳ�������Ƿ���ͨ��
	cout << Search(0, 0, 3, left, bottom);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

int Search(int x, int y, int dir, int left[], int bottom[]){
	int left_l[SIZE], bottom_l[SIZE];
	for(int i = 0; i <= H; i++){
		left_l[i] = left[i];
	}
	for(int i = 0; i <= W; i++){
		bottom_l[i] = bottom[i];
	}
	
	int pos;
	//�Ѿ�Խ�������ͨ����������޷�ǰ��
	if(dir == 0 || dir == 2){  //ǰ���ƶ������
		pos = min(y, y + DIR[dir][1]);
		if(pos < 0 || y + DIR[dir][1] > H) return 0;
		if( ( left_l[pos] & (1 << x) ) > 0 ) return 0;
		left_l[pos] |= (1 << x);  //�����߱��Ϊ��ͨ��
	} 
	else{ //�����ƶ������
		pos = min(x, x + DIR[dir][0]);
		if(pos < 0 || x + DIR[dir][0] > W) return 0;
		if( ( bottom_l[pos] & (1 << y) ) > 0 ) return 0;
		bottom_l[pos] |= (1 << y);  // �Ѻ��߱��Ϊ��ͨ��
	}
	
	int next_x = x + DIR[dir][0], next_y = y + DIR[dir][1];
	if(next_x == W && next_y == H) return 1;  //�����յ������
	
	int cnt = 0;
	//ǰ��
	cnt += Search(next_x, next_y, dir, left_l, bottom_l);
	//��ת
	dir = (dir + 1) % 4;
	cnt += Search(next_x, next_y, dir, left_l, bottom_l); 
	return cnt;
}
























































