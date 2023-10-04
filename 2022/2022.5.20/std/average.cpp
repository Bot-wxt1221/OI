#include <cstdio>
#include <queue>
using namespace std;
 
int main(){
	freopen("average.in", "r", stdin);
	freopen("average.out", "w", stdout);
	int n1, n2, n, x;
	long long sum;
	while(scanf("%d%d%d", &n1, &n2, &n), n1&&n2&&n){
		priority_queue<int> q1;//最大值优先,保存最小的n2个 
		priority_queue<int, vector<int>, greater<int> > q2; //最小值优先,保存最大的n1个
		sum = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &x);
			sum += x;
			q1.push(x);
			q2.push(x);
			if(q1.size() > n2)	q1.pop();
			if(q2.size() > n1) q2.pop();
		}
		while(!q1.empty()){
			sum -= q1.top();
			q1.pop();
		}
		while(!q2.empty()){
			sum -= q2.top();
			q2.pop();
		}
		printf("%.6lf\n", 1.0 * sum / (n - n1 - n2));
	}
	return 0;
}

/*
输入：
1 2 5
1 2 3 4 5
4 2 10
2121187 902 485 531 843 582 652 926 220 155
0 0 0

输出：
3.500000
562.500000 


*/
