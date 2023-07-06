/*
ͨ������ṹ����������������setά����һ������ļ��ϣ�
ÿ�β���ǰ��ȥ�ҵ���ǰ���������ӽ���ֵ��ǰ���ͺ������Ƚ�ǰ���ͺ������ҵ���С��j��
����Ҳ������ڵ���������֣���ô��Ҫ�ж�end()��ע��stl��ȫ������������ҿ�����ʽ������ģ���
ȥֱ�����end()-1��ͬ�������begin()��ֱ�����begin()+1
*/
#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

struct node {
	int num,id;
	bool operator <(node a) const {
		return num < a.num;
	}
};
set<node>s;

int main() {
	int n;
	freopen("find.in", "r", stdin);
	freopen("find.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if(i == 1) {
			s.insert(node {tmp,i});
			continue;
		}
		set<node>::iterator right = s.lower_bound(node {tmp, 0}), left = right;
		left--;
		if(right == s.end()) {
			printf("%d %d\n", tmp - left->num, left->id);
		} else if(right == s.begin()) {
			printf("%d %d\n", right->num - tmp, right->id);
		} else if((tmp - left->num) <= (right->num - tmp)) {
			printf("%d %d\n", tmp- left->num, left->id);
		} else {
			printf("%d %d\n", right->num - tmp, right->id);
		}
		s.insert(node {tmp, i});
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
