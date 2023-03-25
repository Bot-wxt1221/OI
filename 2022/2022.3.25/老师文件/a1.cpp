#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int n, x, y;
priority_queue<int> a, b;
int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        a.push(x);
        b.push(-x);
    }
    while (a.size() > 1) {
        x = a.top();
        a.pop();
        y = a.top();
        a.pop();
        a.push(x * y + 1);
    }
    while (b.size() > 1) {
        x = -b.top();
        b.pop();
        y = -b.top();
        b.pop();
        b.push(-(x * y + 1));
    }
    printf("%d", -b.top() - a.top());
}
