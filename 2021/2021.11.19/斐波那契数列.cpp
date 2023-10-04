#include <iostream>
#define MAX 1000000
using namespace std;
unsigned long long b[MAX]={0,1,1,2};
unsigned long long dfs(unsigned long long a);
int main(){
	int cnt=0;
	for(unsigned long long i=1;1;i++){
		unsigned long long a=dfs(i);
	//	cout<<a<<endl;
		unsigned long long temp=a;
		unsigned long long sum=0;
		while(a){
			sum+=(a%10);
			a/=10;
		}
		if(a%sum==0){
			cnt++;
			cout<<temp<<endl;
		}
		if(cnt>21){
			break;
		}
	}
	return 0;
}
unsigned long long dfs(unsigned long long a){
	if(a==1||a==2){
		return 1;
	}
	if(b[a]&&a<MAX){
		return b[a];
	}
	if(a<MAX)
		return b[a]=dfs(a-1)+dfs(a-2);
	else
		return dfs(a-1)+dfs(a-2);
}
