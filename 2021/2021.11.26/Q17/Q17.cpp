#include <iostream>
#include <cstdio>
using namespace std;
bool p[50];//0ÄÐ 1 Å® 
unsigned long long dfs(int step);
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cout<<dfs(0);
	return 0;
}
unsigned long long dfs(int step){
	if(step==30){
	//	for(int i=0;i<30;i++){
	//		cout<<p[i];
	//	}
	//	cout<<endl;
		return 1;
	}
	unsigned long long cnt=0;
	if(p[step-1]==0){
		p[step]=0;
		cnt+=dfs(step+1);
		p[step]=1;
		cnt+=dfs(step+1);
	}else{
		p[step]=0;
		cnt+=dfs(step+1);
	}
	return cnt;
}
