#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int book[1003] = {0}; //用 book检查内存中有没有单词，book[i]=1 表示单词 i 在内存中
queue<int> mem; //用队列模拟内存
int main(){
	freopen("machine.in", "r", stdin);
	freopen("machine.out", "w", stdout);
	int m, n;
	scanf("%d%d", &m, &n);
	int cnt = 0; //查词典的次数
	while(n--){
		int en;
		scanf("%d", &en); //输入一个英文单词
		if(!book[en]){ //如果内存中没有这个单词
			++cnt;
			mem.push(en); //单词进队列，放到队列尾部
			book[en]=1; //记录内存中有这个单词
			while(mem.size() > m){ //内存满了
				book[mem.front()] = 0; //从内存中去掉单词
				mem.pop(); //从队头去掉
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}

/*
输入:
3 7
1 2 1 5 4 4 1

输出:
5
*/
