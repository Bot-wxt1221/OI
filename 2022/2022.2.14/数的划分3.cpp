#include<cstdio>
#include<iostream>

using namespace std;
int n,k,total;
int min(int x,int y)
{
    if (x < y) return x; 
    else return y;
}

void select(int dep,int rest,int last)
{
     int i;
     if (dep == 0) total++;
     else for (i = min(rest-dep+1,last); i >= rest/dep; i--)
             select(dep-1,rest-i,i);
}
int main()
{
    cin >> n >> k;
    total = 0;
    select(k,n,n);
    cout << total;

    return 0;
}

