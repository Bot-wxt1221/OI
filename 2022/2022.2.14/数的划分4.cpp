#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
int i,j,k,n,x;
int p[201][7]; 

int main()
{
    cin >> n >> k;
    memset(p,0,sizeof(p));
    p[0][0] = 1;
    for (i = 1; i <= n; i++) p[i][1] = 1;
    for (i = 1; i <= n - k; i++)
        for (j = 2; j <= min(i,k); j++)
            for (x = 1; x <= min(i,j); x++)
                p[i][j] += p[i-x][min(i-x,x)];                
    cout << p[n-k][k];            

    return 0;
}

