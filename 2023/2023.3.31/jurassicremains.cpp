#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30;
//等价问题：选择尽量多的数，使得它们的 xor（异或）值为0。

int bitcount(int x) {
	return x == 0 ? 0 : bitcount(x/2) + (x&1);
}
 
int A[MAXN];  //骨头字符串序列中每个字母出现次数的奇偶性：1---奇次， 0---偶次
map<int, int> T;  // T[x] = i，表示 xor值为 x 对应的骨头字符串的子集编号（即选择了多少个骨头字符串） 
string bone; 


int main() {
	freopen("jurassicremains.in", "r", stdin);
	freopen("jurassicremains.out", "w", stdout);
	int N; 
	while(cin >> N) {
		for(int i = 0; i < N; i++) {
			cin >> bone;
			A[i] = 0;
			for(int j = 0; j < bone.length(); j++) {
				A[i] ^= (1 << (bone[j] - 'A'));				
			}
		}
		
		// 计算前 N/2 个元素的所有子集的 xor值, 记录在 T 中 
		T.clear();
		int n1 = N / 2;
		for(int i = 0; i < (1 << n1); i++) {
			int x = 0;
			for(int j = 0; j < n1; j++)  if(i & (1 << j)) x ^= A[j];
			if(!T.count(x) || bitcount(T[x]) < bitcount(i)) T[x] = i;
		}
		
		// 枚举后 n2个元素的所有子集，并在 T中查找
		int n2 = N - n1;	
		int ans = 0;
		for(int i = 0; i < (1 << n2); i++) {
			int x = 0;
			for(int j = 0; j < n2; j++)  if(i & (1 << j)) x ^= A[n1+j];
			if(T.count(x) && bitcount(ans) < bitcount(T[x]) + bitcount(i)) ans = (i << n1) ^ T[x];
		}
		
		// 输出结果
		cout << bitcount(ans) << endl;
		
		for(int i = 0; i < N; i++) if(ans & (1 << i)) cout << i + 1 << " ";
		cout << endl;
	}	
	
	return 0;
}


/*
Sample Input
1
ABC
6
ABD
EG
GE
ABE
AC
BCD

Sample Output
0

5
1 2 3 5 6



*/
