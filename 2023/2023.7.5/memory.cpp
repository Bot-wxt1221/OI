//�ڴ���� (ģ��)
/*
���⣺(������)ģ���ڴ���䡣
��⣺���͵�ģ���⣺
1.ά��һ�����̵�����ÿ���ڵ����̿�ʼʱ��t����������ʱ��p��
���ڴ��е��׵�ַs��ռ���ڴ��Сm,����һ�ڵ�ָ�롣
2.ά��һ�����У���ʾ��û�пռ����еĽ��̡�
3.ά��һ���ͷ��ڴ������ʱ��nexttime��ÿ����һ���½��̵�ʱ����
���̿�ʼʱ�䲻С��nexttime����ʾ�н�������֮ǰ�ѽ��������ܲ�ֹһ
���������������ɾ������ѭ�������׽����Ƿ��пռ����У�����У���
�����ȼ��루ע�⿪ʼʱ��Ҫ��Ϊֹ�̵�nexttime�������Ƕ����ֵ�ˣ���
����¶���Ľ��̼��������������С�
�����������������������ٶ�ʣ��Ķ��к�����������������ϡ�
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const int inf = 1 << 28;
int n,m;
struct node {
       int m, t, p, s, next;
} a[10000];

int Q[10000], head, tail, c, root, nexttime;

//�����ڴ�(��������)
bool alloc(int pos, int t) {
	if (!root || a[root].s - 0 >= a[pos].m) {
		a[pos].next=root;
		root=pos;
		a[pos].t=t;
		a[pos].s=0;
		return true ;
	}
	int i;
	for (i = root; a[i].next != 0; i = a[i].next) {
		if (a[i].s + a[i].m - 1 + a[pos].m < a[a[i].next].s) {
			a[pos].next = a[i].next;
			a[i].next = pos;
			a[pos].s = a[i].s + a[i].m;
			a[pos].t = t;
			return true;
		}
	}
	if (i && (n - (a[i].s + a[i].m)) >= a[pos].m) {
		a[i].next = pos;
		a[pos].next = 0;
		a[pos].s = a[i].s + a[i].m;
		a[pos].t = t;
		return true;
	}
	return false;
}

//ɾ�������Ľ��̣�������н���,����nexttime
void free_and_pop() {
	int pre = root, temp = inf;
	for (int i = root; i;) {
		if (a[i].t + a[i].p == nexttime) {
			if (i == root) {
				root = a[root].next;
				i = root;
			}
			else {
				i = a[pre].next = a[i].next;
			}
		}
		else {
			if (a[i].t + a[i].p < temp) temp = a[i].t + a[i].p;
			pre = i;
			i = a[i].next;
		}
	}
	while (head < tail) {
		if (!alloc(Q[head],nexttime)) break; 
		else { temp = min(temp, a[Q[head]].t + a[Q[head]].p); ++head;}
	} 	
	nexttime = temp;
}

//�����¶���Ľ���
void insert(int pos) {
	while (a[pos].t >= nexttime)  free_and_pop();
	if (!alloc(pos,a[pos].t)) { Q[tail++] = pos; }
	else nexttime = min(nexttime, a[pos].t + a[pos].p);
}

//�������Ķ����еĽ���
int SolveRemain() {
	while (head<tail) {
		free_and_pop();
	}
	int lasttime = nexttime;
	for (int i = root; i; i = a[i].next) {
		lasttime = max(lasttime, a[i].t + a[i].p);
	}
	return lasttime;
}

int main() {
//    freopen("memory.in","r",stdin);
//    freopen("memory.out","w",stdout);
	scanf("%d", &n);
    head = tail = c = root = 0;
    nexttime = inf;
    for (int i = 1; ; i++) {
        scanf("%d%d%d", &a[i].t, &a[i].m, &a[i].p);
		if (a[i].t == 0 && a[i].m == 0 && a[i].p == 0) break;
        insert(i);
    }
    
    printf("%d\n%d\n", SolveRemain(), tail);
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}
