/*
本题是约瑟夫问题的变种，唯一的区别就是：原版问题中，从1开始数数，而在本题中，规定第一个删除的数是m。

约瑟夫问题作为链表的经典应用，出现在很多数据结构与程序设计语言的书籍中。

可惜链表法的时间复杂度为O(nk)，无法承受本题这样大的规模。

如果像本题这样只关心最后一个被删除的编号，而不需要完整的删除顺序，则可以用递推法求解。

假设编号为0～n-1的n个数排成一圈，从0开始每k个数删除一个，最后留下的数字编号记为f(n)，
则f(1)=0，f(n)=(f(n-1)+k) % n。为什么呢？因为删除一个元素之后，可以把所有元素重新编号。 

本题第一个删除的数为 m，因此答案为(m-k+1+f[n]) % n(6)。注意，本题虽然不是动态规划，但思路是相通的
*/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 5;
int f[MAXN];  //f[i]---表示从编号 0 开始，每数 k 个数就删除一个，最后剩下的一个数的编号。 

int main() {
//	freopen("one.in", "r", stdin);
//	freopen("one.out", "w", stdout);
	int n, k, m;
	while(scanf("%d%d%d", &n, &k, &m) == 3 && n) {
		f[1] = 0;
		for(int i = 2; i < n; i++) f[i] = (f[i - 1] + k) % i;  //递推打表 
		//int ans = (m - k + 1 + f[n]) % n;
		int ans = (f[n-1] + m) % n + 1;   //编号修正为 1 开始 
		if (ans <= 0) ans += n;
		printf("%d\n", ans);
	}
	
	return 0;
}

/*
Sample Input
8 5 3
100 9999 98
10000 10000 10000
0 0 0

Sample Output
1
93
2019
*/
