#include <cstdio>
#include <iostream>
using namespace std;
bool use[1005];
int main(){
    int m,n,now;
    cin>>n>>m;
    now=0;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		now++;
    		now=((now==n+1)?1:now);
    		if(use[now]){
    			j--;
    		}
    	}
    	cout<<now<<' ';
    	use[now]=1;
    }
    return 0;
}