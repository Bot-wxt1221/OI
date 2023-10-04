#include<cstdio>
#include<iostream>

using namespace std;
int n,i,j,k,rest,sum,total;
int s[7];

int main()
{
    cin >> n >> k;
    total = 0; s[1] = 0;
    i = 1;
    while (i)
    {
        s[i]++;
        if (s[i] > n) i--;
        else if (i == k)
             {
                   sum = 0;
                   for (j = 1; j <= k; j++) sum += s[j];
                   if (n == sum) total++;
             }
             else
			 {
                         rest -= s[i];
                         i++;
                         s[i] = s[i-1] - 1;
             }  
    }
    cout << total;

    return 0;
}

