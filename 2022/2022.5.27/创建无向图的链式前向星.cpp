//��������ͼ����ʽǰ���� 
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 100000 + 5;
int maxx[maxn], head[maxn];
int n, m, x, y, w, cnt;

struct Edge{
	int to, w, next;
} e[maxn];

void add(int u, int v, int w) { //���һ����u--v 
 	e[cnt].to = v;
 	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt++;
} 

void printg(){ //�����ʽǰ����
	cout << "----------��ʽǰ�������£�----------" << endl;
	for(int v = 1; v <= n; v++) {
		cout << v << "��  ";
		for(int i = head[v]; ~i; i = e[i].next) {
			int v1 = e[i].to, w1 = e[i].w;
			cout << "[" << v1 << " " << w1 << "]\t";
		}
		cout << endl;
	}
}

int main() {
	cin >> n >> m;
	memset(head, -1, sizeof(head));
	cnt = 0;
	for(int i = 1; i <= m; i++) {
		cin >> x >> y >> w;
		add(x, y, w); //��ӱ�
		add(y, x, w); //��ӷ���� 
	}
	printg();
	return 0;
}
/*
4 5
1 2 5
1 4 3
2 3 8
2 4 12
3 4 9
*/
