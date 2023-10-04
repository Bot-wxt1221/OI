//洛谷P1540, STL queue
#include<bits/stdc++.h>
using namespace std;

int Hash[1003] = {0}; //用哈希检查内存中有没有单词，hash[i]=1表示单词i在内存中
queue<int> mem;      //用队列模拟内存

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	int cnt = 0;                         //查词典的次数
	while(n--) {
		int en;
		scanf("%d", &en);       //输入一个英文单词
		if(!Hash[en]) {                  //如果内存中没有这个单词
			++cnt;
			mem.push(en);                //单词进队列，放到队列尾部
			Hash[en]=1;                  //记录内存中有这个单词
			while(mem.size()>m) {        //内存满了
				Hash[mem.front()] = 0;   //从内存中去掉单词
				mem.pop();               //从队头去掉
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}

