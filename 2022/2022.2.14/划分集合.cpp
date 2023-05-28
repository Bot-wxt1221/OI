/*
集合划分，每个子集合不为空 (未完成)
f(n,k):
if(n<k)  0
if(n==k||k==1)  1
else  f(n-1,k-1)+f(n-1,k)*k
*/
#include <iostream>
#include <cstdio>
#define MAXK 1000
long long dp[MAXK+5];
using namespace std;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,k;
	cin>>n>>k;
	return 0;
}
