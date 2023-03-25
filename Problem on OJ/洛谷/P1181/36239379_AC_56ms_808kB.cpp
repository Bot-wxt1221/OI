#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> ans;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,m,ans=1,num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int temp;
		cin>>temp;
		num+=temp;
		if(num>m){
			ans++;
			num=temp;
		}
	}
	cout<<ans;
	return 0;
}
