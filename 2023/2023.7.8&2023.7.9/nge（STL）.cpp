#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    freopen("nge.in", "r", stdin);
    freopen("nge.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;    
    cin >> n;
    vector<int> V(n + 1), ans(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> V[i];
    stack<int> S;
    for (int i = 1; i <= n; ++i)
    {
        while (!S.empty() && V[S.top()] < V[i])
        {
            ans[S.top()] = i;
            S.pop();
        }
        S.push(i);
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    return 0;
}
