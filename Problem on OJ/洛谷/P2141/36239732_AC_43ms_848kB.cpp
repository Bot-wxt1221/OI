#include <iostream>
#include <cstdio>
using namespace std;
int a[105];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		bool check=0;
		for(int j=1;j<=n;j++){
			for(int m=1;m<=n;m++){
				if(i!=j&&i!=m&&j!=m&&a[i]==(a[j]+a[m])){
					check=1;
				}
			}
		}
		ans+=check;
	}
	cout<<ans;
	return 0;
}