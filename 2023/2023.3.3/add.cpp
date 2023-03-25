//最佳加法表达式
/*
问题描述：
有一个由1..9组成的数字串(长度为 n)。问如果将 m个加号（非正号）插入到这个数字串中，
在各种可能形成的可计算表达式中，值最小的那个表达式的值是多少？

输入格式：
多组数据，每组数据输入如下： 
输入第一行是整数 m。
输入第二行是长度为 n 的数字串。 

输出格式：
对每组数据，输出一行，即最小加法表达式的值。

输入样例1：
1
1234

输出样例1：
46

输入样例2：
2
123456
1
123456
4
12345

输出样例2：
102
579
15

数据范围：
1 <= n <= 50
0 <= m <= n - 1
*/ 

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 55; 
struct BIG_INT {  //定义大整数，重载 +， <
	int len;  //大整数长度
	int a[MAXN]; //大整数存储数组
	BIG_INT() {  //默认初始化, 定义一个大整数时默认的初始化值 
		len = 1;
		memset(a, 0, sizeof(a));
	} 
	BIG_INT(const char *str, int L) { //指定参数的初始化，即将长度为 L 的数字串转换为对应的大整数 
		memset(a, 0, sizeof(a));
		len = L;
		for(int i = 0; i < len; i++) {
			a[L - i - 1] = str[i] - '0';
		} 
	}
	//重载大整数加法： +
	BIG_INT operator + (const BIG_INT &x) const {
		int MAX_LEN = max(len, x.len); //加数和被加数的长度，取大的长度  
		int c = 0;  //进位 
		BIG_INT result;
		result.len = MAX_LEN;
		for(int i = 0; i < MAX_LEN; i++) {
			result.a[i] = a[i] + x.a[i] + c;
			c = result.a[i] / 10;
			result.a[i] %= 10;
		} 
		if(1 == c) { //处理最高位进位 
			result.len = MAX_LEN + 1;
			result.a[MAX_LEN] = c;
		} 
		return result;	
	} 
	//重载大整数比较： <
	bool operator < (const BIG_INT &x) const {
		if(len > x.len) return false;
		else if(len < x.len) return true;
		else {
			for(int i = len - 1; i >= 0; i--) {
				if(a[i] < x.a[i]) return true;
				else if(a[i] > x.a[i]) return false;
			}
			return false;
		}		
	}  	
};

char num_str[MAXN]; 
BIG_INT num[MAXN][MAXN];  //num[i][j]--- 表示 num_str[i]~ num_str[j]数字串对应的大整数 
BIG_INT dp[MAXN][MAXN];  //dp[i][j]--- i个加号放到前j个数字中间，所能得到的最佳表达式的值
//dp方程： dp[i][j] = min{dp[i-1][k] + num[k+1][j]} , i <= k < j;
BIG_INT INF;  //定义无穷大 

int main() {
	freopen("add.in", "r", stdin);
	freopen("add.out", "w", stdout);
	int m;  //加法次数 	
	INF.len = MAXN - 1;
	INF.a[MAXN - 2] = 1; //初始化无穷大的值 
		
	while(cin >> m) { 
		cin >> num_str;
		int n = strlen(num_str);
		//初始化 num[i][j]
		for	(int i = 1; i <= n; i++) {
			for(int j = i; j <= n; j++) {
				num[i][j] = BIG_INT(num_str + i - 1, j - i + 1);
				/*
				cout << i << "~" << j << " : "; 
				for(int k = num[i][j].len - 1; k >= 0; k--)
    				cout << num[i][j].a[k];
				cout << endl;	
				*/			
			}
		}
		
		//初始化dp边界：dp[0][j] = 前 j 个数字串对应的大整数
		for(int j = 1; j <= n; j++) {
			dp[0][j] = BIG_INT(num_str, j);
		} 
		//递推打表 dp[i][j]
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				if(j < i + 1) { // 不存在加号的数量比数字个数还多的状态，初始化为无穷大 
					dp[i][j] = INF; 
				}
				else { //递推最佳表达式的值 
					BIG_INT MIN = INF;
					for(int k = i; k < j; k++) {
						MIN = min(MIN, dp[i - 1][k] + num[k + 1][j]);
					} 
					dp[i][j] = MIN;
				}
			}
		} 
		//输出 dp[m][n]
		for(int i = dp[m][n].len - 1; i >= 0; i--)
    		cout << dp[m][n].a[i];
		cout << endl;	
		
	}
	return 0;
}

