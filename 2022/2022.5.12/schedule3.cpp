#include <cstdio>
#include <cstring>
#include <algorithm>
#define LEN 100005
using namespace std;
//代表任务的结构体
typedef struct pp{
	char name[100];
	int t;
} P;

P Q[LEN];
int head, tail;

void enqueue(P x){
	Q[tail] = x;
	tail = (tail + 1) % LEN;
} 

P dequeue(){
	P x = Q[head];
	head = (head + 1) % LEN;
	return x;
}

int main(){
	int elaps = 0, c;
	int n, q;
	P u;
	freopen("schedule.in", "r", stdin);
	freopen("schedule.out", "w", stdout);
	scanf("%d %d", &n, &q);
	
	//按顺序将所有任务添加至队列
	for (int i = 1; i <= n; i++){
		scanf("%s", Q[i].name);
		scanf("%d", &Q[i].t);
	} 
	head = 1; tail = n + 1;
	
	//模拟
	while (head != tail){
		u = dequeue();
		c = min(q, u.t);  //执行时间片 q 或所需时间 u.t 的处理
		u.t -= c;   //计算剩余的所需时间
		elaps += c; //累计已经过的时间
		if (u.t > 0) enqueue(u);  //如果处理尚未结束，则重新添加至队列
		else printf("%s %d\n", u.name, elaps); 
	} 
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}


