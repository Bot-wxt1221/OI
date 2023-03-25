#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

typedef long long LL;
const int N = 1010;
int n;
queue<int> q[N];
int b[1000050];
int T;

inline void in(int x,int y){
	if(q[y].empty())
		q[0].push(y);
	q[y].push(x);
	return;
}

inline void out(){
	int i = q[0].front();
	printf("%d\n", q[i].front());
	q[i].pop();
	if(q[i].empty()) q[0].pop();
	return;
}

inline void work(){
	char s[20];
	int x;
	while(~scanf("%s",s)){
		if(s[0]=='S') return ;
		if(s[0]=='E'){
			scanf("%d",&x);
			in(x,b[x]);
		}
		else if(s[0]=='D'){
			out();
		}
	}
	return;	
}

int main(){
	while(scanf("%d",&n), n){
		printf("Scenario #%d\n", ++T);
		for(int i = 1, x, y; i <= n; ++i){
			scanf("%d", &x);
			while(x--)
				scanf("%d", &y), b[y] = i;
		}
		for(int i = 0; i <= n; ++i) 
			q[i] = queue<int>();
		work();
		puts("");
	}
	return 0;
}

/*
Sample Input
2
3 101 102 103
3 201 202 203
ENQUEUE 101
ENQUEUE 201
ENQUEUE 102
ENQUEUE 202
ENQUEUE 103
ENQUEUE 203
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
2
5 259001 259002 259003 259004 259005
6 260001 260002 260003 260004 260005 260006
ENQUEUE 259001
ENQUEUE 260001
ENQUEUE 259002
ENQUEUE 259003
ENQUEUE 259004
ENQUEUE 259005
DEQUEUE
DEQUEUE
ENQUEUE 260002
ENQUEUE 260003
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
0



Sample Output
Scenario #1
101
102
103
201
202
203
Scenario #2
259001
259002
259003
259004
259005
260001
*/
