/*
我们可以这样思考：为使绳子不交叉，只要"从任意位置划分范围，
并在各自范围中结对就可以"。不过要注意，每个范围中的人数必须为
偶数。
很显然，2 个人的时候有 1 种结对方式。所以，在划分的 2 个范围
中各自计算结对方式，再把 2 个范围内的结对方式数相乘就可以了。

dp[i] = ∑dp[j] * dp[i-j-1], dp[0] = 1, 0 <= j < i, 1 <= i <= n/2
即第 i 个范围的不交叉方案数 =  dp[0]*dp[i-1]+dp[1]*dp[i-2]+...+dp[i-1]*dp[0] 
相当于固定第 i 个位置（范围），前 i-1 个位置（范围）可以任选一段（从j处断开）
分成两部分，再把 2 个范围内的结对方式数相乘，最后累加每个断开位置（j）的方案数。 

结果为卡特兰数。 
*/
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n = 16;
	int dp[20];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 1; i <= n / 2; i++){	
		for(int j = 0; j < i; j++){
			dp[i] += dp[j]*dp[i - j - 1];
		}
	} 
	cout << dp[n/2];
	
	return 0;
}
