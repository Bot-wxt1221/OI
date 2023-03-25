#include <cstdio>
#include<iostream>
#include <algorithm> 
#define int long long int
//#include<bits/stdc++.h>
using namespace std;
int n;
int i,j;
int work(int ,int ,int);
signed main()
{
	cin>>n>>i>>j;
	int ans=work(n,i,j);
	cout<<ans;
	return 0;	
}
int work(int n,int i,int j)
{
	if(i==1)
		return j;
	else if(j==n)
		return n+i-1;
	else if(i==n)
		return 3*n-1-i;
	else if(j==1)
		return 4*n-2-i;
	return work(n-2,i-1,j-1)+4*(n-1);
}