#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int aa[11];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>aa[j]; 
		}
		if(n==2){
			cout<<abs((aa[1])-(aa[2]))<<endl;
		}else if(n%2==1){
			sort(aa+1,aa+n+1);
			int k=(n/2)+1;
			int a=0,b=0;
			if(aa[1]==0){
				swap(aa[1],aa[2]);
			}
			for(int i=1;i<=k;i++){
				a=a*10+aa[i];
			}
			for(int i=n;i>k;i--){
				b=b*10+aa[i];
			}
			cout<<a-b<<endl;
		}
	}
	return 0;
}

