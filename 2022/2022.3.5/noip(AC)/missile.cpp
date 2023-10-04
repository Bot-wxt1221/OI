/*
贪心拦截每个导弹 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool vised[1005];
int h[1005];
int main(){
	freopen("missile.in","r",stdin);
	freopen("missile.out","w",stdout);
	int n=1;
	for(;!cin.eof();n++){
		cin>>h[n];//读入 
	}
	int used=0,have=0;
	while(have<n){//由于每个都要拦截 
		used++;
		int free=60005;
		bool havse=0;
		for(int i=1;i<=n;i++){//选剩下的导弹第一个拦截 
			if(!vised[i]){
				if(h[i]<=free){ 
					have++;//已拦截数 
					vised[i]=1;
					free=h[i];
				}
			}
		}
	}
	cout<<used;
	return 0;
}
