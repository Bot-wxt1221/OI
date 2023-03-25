#include <cstdio>
#include <iostream>
using namespace std;

struct node{
	int data;
	int next;
};

int main(){
	struct node linklist[101];
	int n;
	//读入已有的数
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &linklist[i].data);
	int len = n;
	//初始化结构体数组的next变量 
	for(int i = 1; i <= n; i++){
		if(i != n) linklist[i].next = i + 1;
		else linklist[i].next = 0;
	}
	//直接在结构体数组linklist的末尾增加一个数
	len++;
	scanf("%d", &linklist[len].data);
	//从链表的头部开始遍历
	int t = 1;
	while(t != 0){
		if(linklist[linklist[t].next].data > linklist[len].data){//如果当前结点下一个结点的值大于待插入数，将数插入到中间
			linklist[len].next = linklist[t].next;//新插入数的下一个结点标号等于当前结点的下一个结点编号
			linklist[t].next = len;//当前结点的下一个结点编号就是新插入数的编号
			break;//插入完成跳出循环
		}
		t = linklist[t].next;
	}
	//输出链表中所有的数
	t = 1;
	while(t != 0){
		printf("%d ", linklist[t].data);
		t = linklist[t].next;
	}
	
	return 0;
}
