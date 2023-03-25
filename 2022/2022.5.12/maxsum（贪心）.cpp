/*
贪心：逐个扫描序列中的元素，累加。
加一个正数时，和会增加；加一个负数时，和会减少。
如果当前得到的和变成了负数，这个负数和在接下来的累加中，会减少后面的求和。
所以抛弃它，从下一位置开始重新求和。
*/ 

#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("maxsum.in", "r", stdin);
	freopen("maxsum.out", "w", stdout);
	const int INF = 0x7fffffff;

	int t; cin >> t; //测试用例个数
	for(int i = 1; i <= t; i++){
		int n; cin >> n;
		int maxsum = -INF; //最大子序和，初始化为一个极小负数
		int start = 1, end = 1, p = 1; //起点，终点，扫描位置
		int sum = 0; //子序和
		for(int j = 1; j <= n; j++){
			int a; cin >> a; //读入一个元素		
			sum += a;
			if(sum > maxsum){
				maxsum = sum;
				start = p;
				end = j;
			}
			if(sum < 0){
				//扫到j 时，前面的最大子序和是负数，那么从下一个 j 重新开始求和。
				sum = 0;
				p = j + 1;
			}
		}
		//printf("Case %d:\n",i);
		//printf("%d %d %d\n", maxsum, start, end);
		cout << "Case " << i << ":\n";
		cout << maxsum << " " << start << " " << end << "\n";
		if(i != t) cout << "\n";
	}	
	return 0;
}

/*
输入:
2
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5

输出:
Case 1:
14 1 4

Case 2:
7 1 6
*/

