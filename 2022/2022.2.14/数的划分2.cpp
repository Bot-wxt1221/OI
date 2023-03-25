#include<cstdio>
#include<iostream>

using namespace std;
int n,k;
int f(int a,int b,int c)
{
    int g = 0,i;
    if (b == 1) g = 1;
    else for (i = c; i <= a/b; i++)
            g += f(a-i,b-1,i);
    return g;
}

int main()
{
    cin >> n >> k;
    cout << f(n,k,1);
    
    return 0;
}

