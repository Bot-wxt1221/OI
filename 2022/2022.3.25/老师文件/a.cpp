#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
    priority_queue<int> b;
    priority_queue<int, vector<int>, greater<int> > s;
    int n;
    freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        b.push(a);
        s.push(a);
    }
    for (int i = 1; i < n; i++) {
        int b1 = b.top();
        b.pop();
        int b2 = b.top();
        b.pop();
        b.push(b1 * b2 + 1);
        int s1 = s.top();
        s.pop();
        int s2 = s.top();
        s.pop();
        s.push(s1 * s2 + 1);
    }
    cout << s.top() - b.top() << endl;
    return 0;
}
