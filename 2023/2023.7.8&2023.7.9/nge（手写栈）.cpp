#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

int V[3000000+5], ans[3000000+5];
int S[3000000+5], top;
int read() {
    char ch = getchar(); int x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    } 
	while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    } return x * f;
}

int main()
{
    freopen("nge.in", "r", stdin);
    freopen("nge.out", "w", stdout); 
    int n;    
    cin >> n;    
    for (int i = 1; i <= n; ++i)
        V[i] = read();   
    top = 0;
    for (int i = 1; i <= n; ++i)
    {
       	while (top != 0 && V[S[top]] < V[i])
        {
            ans[S[top]] = i;
            top--;
        }
        top++;
		S[top] = i;;
    }
    for (int i = 1; i <= n; ++i)  
        printf("%d ", ans[i]);
    return 0;
}
