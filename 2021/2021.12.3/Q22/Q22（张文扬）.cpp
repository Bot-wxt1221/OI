#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
int f[101];
/*
	1.将电话线拆开来算，实际上就是卡特兰数。 
	2.然后可以根据 排列组合 C(n,2*n)/(n+1)化简； 
	f(n)=f(n-1)*2*(2*n-1)/(n+1);	
*/
int main(){
	scanf("%d",&N);
	f[1]=1;f[2]=2;
	for(int i=3;i<=N/2;++i){
		f[i]=f[i-1]*(4*i-2)/(i+1);
	}
	printf("%d",f[N/2]);
	return 0;
}
