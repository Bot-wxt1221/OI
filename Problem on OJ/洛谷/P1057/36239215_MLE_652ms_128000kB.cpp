#include <iostream>
using namespace std;
int n,m;
long long dfs(int n1,int m1);
int main(){
    cin>>n>>m;
    cout<<dfs(1,1);
}
long long dfs(int n1,int m1){
		if(n1>3){
			n1=n1&n+1;
		}
		if(n1==0){
			n1=n;
		}
	    if(1>m){
	        return 0;
	    }
    if(n1==1&&m1==m){
        return 1;
	}
	return dfs(n1-1,m1+1)+dfs(n1+1,m1+1);
}