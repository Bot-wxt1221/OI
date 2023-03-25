#include <iostream>
#include <cstdio>
#include <cstring>
//#include <algorithm>
#include <deque>
using namespace std;
deque<int> q[1010], p;
int c[1000010], n, m, x, t;
char s[10];

int main(){
	while(cin >> n && n){
		p.clear();
		for(int i = 1; i <= n; i++) q[i].clear();
		for(int i = 1; i <= n; i++){
			scanf("%d", &m);
			for(int j = 1; j <= m; j++) scanf("%d", &x), c[x] = i;
		}
		printf("Scenario #%d\n", ++t);
		while(~scanf("%s", s) && s[0]!='S'){
			if(s[0] == 'E'){
				scanf("%d", &x);
				if(!q[c[x]].size()) p.push_back(c[x]);
				q[c[x]].push_back(x);
			}
			else{
				x = p.front();
				printf("%d\n", q[x].front());
				q[x].pop_front();
				if(!q[x].size()) p.pop_front();
			}
		}			
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
