#include <iostream>
#include <cstdio>
#define MAXN 1000000
using namespace std;
bool temp[MAXN+5];//0为质数，1为合数 
int main(){
	freopen(".out","w",stdout);
	for(int i=2;i*i<=MAXN;i++){//i的倍数 
		if(temp[i]){
			continue;
		}
		int a=i+i;
		for(;a<=MAXN;){//多少倍     *******：不能去掉 1倍的数，去掉就废了 
			temp[a]=1;
			a+=i;
		}
	}
	for(int i=2;i<=MAXN;i++){
		if(!temp[i]){
			cout<<i<<' ';
		}
	}
	return 0;
}

