/*
"����·��" ���� "����·��"��򵥺ܶࡣ
�Զ���ĺ����� x�������� yΪ׼�����Ҽ�
¼ 0�����¼�¼ 1���Դ˼�¼ͨ���Ķ��㣬
Ҳ����ͨ���ݹ�������������������������ǡ�
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define SIZE 10
using namespace std;
int square;
long long count = 0;
bool is_used[SIZE][SIZE][2];
void route(int x, int y, bool is_first_time);

int main(){
	cin >> square;
	memset(is_used, false, sizeof(is_used));
	route(0, 0, true);
	cout << count;
	return 0;
}

void route(int x, int y, bool is_first_time){
	if( (x == square) && (y == square) ){
		if(is_first_time){
			route(0, 0, false);
		}
		else{
			count++;
		}
	}
	if(x < square){
		if(!is_used[x][y][0]){
			is_used[x][y][0] = true;
			route(x + 1, y, is_first_time);
			is_used[x][y][0] = false;
		}
	}
	if(y < square){
		if(!is_used[x][y][1]){
			is_used[x][y][1] = true;
			route(x, y + 1, is_first_time);
			is_used[x][y][1] = false;
		}
	}
	return;	
}
