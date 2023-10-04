#include <iostream>
using namespace std;
int op[4]={10,50,100,500};
int ans=0;
int a=0;
void dfs(int x){
	if(x>=1000){
		ans++;
		return;
	}
	if(a>15){
		return;
	}
	cout<<a<<endl;
	for(int i=0;i<4;i++){
		a++;
		dfs(x+op[i]);
		a--;
	}
	return;
}
int main(){
	dfs(0);
	cout<<ans;
	return 0;
}
