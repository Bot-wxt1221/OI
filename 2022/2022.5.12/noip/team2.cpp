#include <iostream>
#include <cstdio>
#include <queue> 
#include <cstring>
using namespace std;
int book[1000005];
bool go[1000005];
int main(){
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
	int t,n=1;
	scanf("%d",&t);
	char temp[10];
	while(t!=0){
		memset(go,0,sizeof(go));
		memset(book,0,sizeof(book));
		queue<int>b[1005];
		queue<queue<int> *>a;
		printf("Scenario #%d\n",n);
		for(int i=1;i<=t;i++){
			int m;
			scanf("%d",&m); 
			for(int j=1;j<=m;j++){
				int temp;
				scanf("%d",&temp);
				book[temp]=i;
			}
		}
		scanf("%s",temp);
		while(strcmp(temp,"STOP")!=0){
			if(strcmp(temp,"ENQUEUE")==0){
				int aa;
				scanf("%d",&aa);
				b[book[aa]].push(aa);
				if(go[book[aa]]==0){
					a.push(&(b[book[aa]]));
					go[book[aa]]=1;
				}
			}else{
				int temp=(*(a.front())).front();
//				cout<<(*(a.front())).front()<<endl;
				(*(a.front())).pop();
				if((*(a.front())).size()==0){
					go[book[temp]]=0;
					a.pop();
				} 
			}
			scanf("%s",temp);
		}
		n++;
		scanf("%d",&t);
//		printf("\n");
	} 
	return 0;
}
/*
Anything about this program:
Type:
	Example 
Description:
	队列和优先级队列是大多数计算机科学家都知道的数据结构。然而，团队队列并不为人所知，尽管它经常出现在日常生活中。例如，在午餐时间，餐厅窗口排队队列就是团队
队列。
在团队队列中，每个元素都属于一个团队。如果一个元素进入队列，它首先从头到尾搜索队列，检查它的一些队友（同一个团队的元素）是否已经在队列中。如果是，它就进
入他们后面的队列。如果不是，它在尾部进入队列并成为新的最后一个元素（运气不好）。出队就像在普通队列中一样：元素按照它们在团队队列中出现的顺序从头到尾进行
处理。
你的任务是编写一个模拟这种团队队列的程序。
输入将包含一个或多个测试用例。每个测试用例都以团队数量 t (1<=t<=1000) 开始。然后是 t 个团队描述，每个描述由属于该团队的元素数量和元素本身组成。元素是 0 -
999999范围内的整数。一个团队最多可以包含 1000 个元素。
最后是命令列表。共有三种不同的命令：
ENQUEUE x - 将元素 x 输入团队队列
DEQUEUE - 处理第一个元素并将其从队列中删除
STOP - 测试用例结束
对于 t，输入将以 0 值终止。
警告：一个测试用例可能包含多达 200000（二十万）条命令，因此团队队列的实现应该是高效的：一个元素的入队和出队都应该只花费恒定的时间。
Example:
	1:
		In:
			team.in/team2.in/team4.in
		Out:
			team.out/team2.out/team4.out
More:
	1 简化模型：不一定要真正维护整个队列，因为涉及实现双端队列的插入，要找到插入位置时间复杂度不可接受
	2 注意细节：是谁把sizeof(book)写成sizeof(0) 清0 
	3 尽量减少标记数组：避免产生矛盾导致内存溢出
	老版本，内存未经优化 
*/

