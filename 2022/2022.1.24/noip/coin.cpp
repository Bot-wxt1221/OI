#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
using namespace std;
vector <int > as;
signed main(){
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	int a,b,_max=0;
	cin>>a>>b;
	for(int i=0;i<=b;i++){
		for(int b1=0;b1<=a;b1++){
			as.push_back(i*a+b1*b);
		}
	}
	for(int j=a*b-1;j>=0;j--){
		bool yes=1;
		for(int i=0;i<as.size();i++){
			if(as[i]==j){
				yes=0;
			}
		}
		if(yes){
			cout<<j;
			break;
		}
	}
	return 0;
}

