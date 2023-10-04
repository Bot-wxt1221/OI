//洛谷P1540, 手写循环队列 
#include <bits/stdc++.h>
const int N = 1003;               //队列大小

int Hash[N] = {0};            //用Hash检查内存中有没有单词 

struct myqueue { 
	int data[N];             //分配静态空间 
	/* 如果动态分配，这样写： int *data;    */
	int head, rear;          //队头、队尾
	bool init() {            //初始化
		/*如果动态分配，这样写：
		Q.data = (int *)malloc(N * sizeof(int)) ;
		if(!Q.data) return false;        */
		head = rear = 0;
		return true;
	}
	int size() {
		return (rear - head + N) % N;   //返回队列长度 
	}
	bool empty() {              //判断队列是否为空 
		if(size()==0) return true;
		else          return false;
	}
	bool push(int e) {          //队尾插入新元素。新的rear指向下一个空的位置 
		if((rear + 1) % N == head ) return false;    //队列满 
		data[rear] = e;
		rear = (rear + 1) % N;
		return true;
	}
	bool pop(int &e) {          //删除队头元素，并返回它 
		if(head == rear) return false;       //队列空 
		e = data[head];
		head = (head + 1) % N;
		return true;
	}
	int front() {
		return data[head];    //返回队首，但是不删除
	}
} Q;

int main() {
	Q.init();                    //初始化队列
	int m, n;
	scanf("%d%d", &m, &n);
	int cnt = 0;
	while(n--) {
		int en;
		scanf("%d",&en);    //输入一个英文单词
		if(!Hash[en]) {              //如果内存中没有这个单词
			++cnt;
			Q.push(en);              //单词进队列，放到队列尾部
			Hash[en] = 1;
			while(Q.size() > m) {      //内存满了
				int tmp;
				Q.pop(tmp);     //删除队头
				Hash[tmp] = 0;       //从内存中去掉单词
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}

