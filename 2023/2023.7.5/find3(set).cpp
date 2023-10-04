/*
通过定义结构体和重载运算符，将set维护成一个有序的集合，
每次插入前，去找到当前这个数字最接近的值的前驱和后驱，比较前驱和后驱，找到最小的j，
如果找不到大于等于这个数字，能么需要判断end()（注意stl中全部都是以左闭右开的形式来保存的），
去直接输出end()-1，同理如果是begin()，直接输出begin()+1
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
