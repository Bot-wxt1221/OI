#include <cstdio>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#define N 10005
int n,L,P;
struct node{
    int dis, add;//���룬�ɼ����� 
}port[N];

bool cmp(node a, node b){
    return a.dis > b.dis;//�����뽵�� 
}

void solve(){
    priority_queue<int> que;
    //ans:���ʹ��� pos:��ǰ�ɵ����λ�� k:��k������վ
    int ans = 0, pos = P, k = 0;
    while(pos < L) {
    	while(pos >= L - port[k].dis && k < n){
    		que.push(port[k].add);
    		k++;
		}
		if(que.empty()){
			printf("-1\n");
			return;
		}
		else{
			pos += que.top();
			que.pop();
			ans++;
		}
	}
	printf("%d\n", ans);
}

int main(){
	freopen("expedition.in", "r", stdin);
	freopen("expedition.out", "w", stdout);
    while(~scanf("%d", &n)){
        for(int i = 0; i < n; i++)
            scanf("%d %d", &port[i].dis, &port[i].add);
        scanf("%d%d", &L, &P);
        sort(port, port+n, cmp);
        solve();
    }
    return 0;
}

/*
���룺
4
4 4
5 2
11 5
15 10
25 10

�����
2 


*/
