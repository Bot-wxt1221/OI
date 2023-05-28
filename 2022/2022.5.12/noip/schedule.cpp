#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

class node{
	public:
		char n[20];
		int t;
}aa; 
queue<node>a;
int main(){
	freopen("schedule.in","r",stdin);
	freopen("schedule.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%d",aa.n,&aa.t);
		a.push(aa);
	}
	int aaa=0;
	while(!a.empty()){
		node temp=a.front();
		a.pop();
		if(temp.t<=q){
			cout<<temp.n<<' '<<aaa+temp.t<<endl;
			aaa-=(q-temp.t);
		}else{
			temp.t-=q;
			a.push(temp);
		}
		aaa+=q;
	}
	return 0;
}
/*
Anything about this program:
Type:
	例题 
Description:
	队列中有 n 个进程。每个进程都有名称： namei 和 处理时间：timei。CPU 通过循环调度按顺序
处理这些进程。循环调度程序为每个进程提供确定的时间片,如果该进程未在时间片内执行完成，那么该
进程就会被中断。然后该进程将被恢复并移动到队列的末尾,然后调度程序随即开始处理队列中的下一个
进程。
Example:
	1:
		In:
			5 100
			p1 150
			p2 80
			p3 200
			p4 350
			p5 20
		Out:
			p2 180
			p5 400
			p1 450
			p3 550
			p4 800
More:
	不要把时间片时间变成 100 
*/

