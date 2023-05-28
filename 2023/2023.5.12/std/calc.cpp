#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
stack<long long> num;
stack<char> op;
unordered_map <char, int> pre{ {'+', 1},  {'-', 1}, {'*',2} };

void eval() {
    long long b = num.top(); num.pop();
    long long a = num.top(); num.pop();
    char p = op.top(); op.pop();
    
    long long ans = 0;
    if (p == '+')  ans = (long long)(a % M + b % M) % M;
    if (p == '-')  ans = (long long)(a % M - b % M) % M;
    if (p == '*')  ans = (long long)(a % M * b % M) % M;  
    
    num.push(ans);
}

int main() {
	freopen("calc.in", "r", stdin);
	freopen("calc.out", "w", stdout);
	string s;
	cin >> s;	
	
    for (int i = 0;i < s.size(); i++) {
        char c = s[i];
        if (isdigit(c)) {
            int x = 0;
			int j = i;
            while (j < s.size() && isdigit(s[j]))
                x = x * 10 + (s[j++] - '0');       
            num.push(x);
            i = j - 1;
        }
        else if (c == '(')  op.push(c);
        else if (c == ')') {
            while (op.top() != '(') eval();
            op.pop();
        }
        else {
            while (op.size() && pre[op.top()] >= pre[c]) eval();
            op.push(c);
        }
    }    
    while (op.size()) eval();
    cout << num.top() << endl;
	
	return 0;
}

/*
ÊäÈë£º
(1+2)*3+4

Êä³ö£º 
13
*/



