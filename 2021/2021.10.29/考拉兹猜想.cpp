#include <iostream>
using namespace std;
int ans=0;
void dfs(int x,int n){
	if(x==1){
		return;
	}
	if(x==n){
		ans++;
		return;
	}
	if(x%2==0){
		dfs(x/2,n);
	}else{
		dfs(x*3+1,n);
	}
}
int main(){
	for(int i=2;i<=10000;i+=2){
		dfs(i*3+1,i);
	}
	cout<<ans;
	return 0;
}
