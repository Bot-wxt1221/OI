/*
暴力枚举时间，坑多多 
*/
#include <iostream>
#include <cstdio>
using namespace std;
int p,e,i,d;
bool check(int a);
int main(){
	freopen("cycle.in","r",stdin); 
	freopen("cycle.out","w",stdout);
	cin>>p>>e>>i>>d;
	for(int i=0;i<=21252;i++){
		if(check(i+d)){
			cout<<i;
			return 0;
		}
	}
	return 0;
}
bool check(int a){
	if(a%23==p%23&&a%28==e%28&&a%33==i%33){//p,e,i要取模，不取模永远都不会等于 
		return true;
	}else{
		return false;
	}
}
