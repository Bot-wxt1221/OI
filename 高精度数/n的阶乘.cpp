#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int a[30000];
int main(){
	int n;
	cin>>n;
	a[1]=1;
	int l=1;
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=1;j<=l;j++){
			a[j]=a[j]*i+x;
			x=a[j]/10;
			a[j]%=10;
			if(x>0&&j>=l){
				l++;
			}
		}
	}
	for(int i=l;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
