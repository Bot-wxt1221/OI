#include <cstdio>
#include <iostream>
using namespace std;

const int MAXQSIZE = 1003; //队列大小
int book[MAXQSIZE] = {0}; //用 book 检查内存中有没有单词
struct myqueue {
	int data[MAXQSIZE]; //分配静态空间
	/* 如果动态分配，就这样写： int *data; */
	int front; //队头，指向队头的元素
	int rear; //队尾，指向下一个可以放元素的空位置
	bool init(){ //初始化
		/*如果动态分配，就这样写：
		Q.data = (int *)malloc(MAXQSIZE * sizeof(int)) ;
		if(!Q.data) return false; */
		front = rear = 0;
		return true;
	}
	int size() { //返回队列长度
		return (rear - front + MAXQSIZE) % MAXQSIZE;
	}
	bool push(int e) { //队尾插入新元素。新的rear 指向下一个空的位置
		if((rear + 1) % MAXQSIZE == front ) return false; //队列满
		data[rear] = e;
		rear = (rear + 1) % MAXQSIZE;
		return true;
	}
	bool pop(int &e) { //删除队头元素，并返回它
		if(front == rear) return false; //队列空
		e = data[front];
		front = (front + 1) % MAXQSIZE;
		return true;
	}
} Q;

int main(){
	freopen("machine.in", "r", stdin);
	freopen("machine.out", "w", stdout);
	Q.init(); //初始化队列
	int m,n; scanf("%d%d",&m,&n);
	int cnt = 0;
	while(n--) {
		int en; scanf("%d",&en); //输入一个英文单词
		if(!book[en]) { //如果内存中没有这个单词
			++cnt;
			Q.push(en); //单词进队列，放到队列尾部
			book[en]=1;
			while(Q.size()>m) { //内存满了
				int tmp;
				Q.pop(tmp); //删除队头
				book[tmp] = 0; //从内存中去掉单词
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
