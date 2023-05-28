#include <iostream>
#include <cstdio>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int pow(int as);
int main(){
	freopen("matches.in","r",stdin);
	freopen("matches.out","w",stdout);
	int n;
	cin>>n;
	n-=4;
	int ans=0;
	for(int i=0;i<=1111&&n>=pow(i);i++){
		for(int j=0;j<=1111&&n>=pow(j);j++){
			
			int m=i+j;
			if(m<=1111&&pow(i)+pow(j)+pow(m)==n){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
int pow(int as){
	int ans=0;
	if(as==0){
		return a[0];
	}
	while(as){
		ans+=a[as%10];
		as/=10;
	}
	return ans;
}
