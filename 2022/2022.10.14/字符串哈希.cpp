//字符串哈希
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;
unsigned long long B = 29;
unsigned long long h[MAXN], p[MAXN];
unordered_set<unsigned long long> T;  //存不同满足 A+A形式的子串哈希值 

int solve(string str) {
	h[0] = 0, p[0] = 1; // p[i] = Base ^ i
	for(int i = 0; i < str.size(); i++) {
		h[i+1] = h[i] * B + (str[i] - 'a' + 1); 
	}
	for(int i = 1; i <= str.size(); i++) {
		p[i] = p[i-1] * B;
	}
	
	unsigned long long L_h, R_h;
	for(int i = 2; i <= str.size(); i += 2) {
		for(int j = 0; j + i - 1 < str.size(); j++) {
			int L1 = j, R1 = j + i / 2 - 1;
			int L2 = j + i / 2, R2 = j + i - 1;
			L_h = h[R1 + 1] - h[L1] * p[R1 + 1 - L1];
			R_h = h[R2 + 1] - h[L2] * p[R2 + 1 - L2];
			if(L_h == R_h) T.insert(L_h);
		}
	}	
	
	return T.size(); 
} 

int main() {
	string str;
	cin >> str;
	cout << solve(str);
}

/*
输入：
abcabcabc
输出 
3
*/
