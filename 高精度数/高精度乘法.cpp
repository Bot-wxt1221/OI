#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int main(){
	char a1[1001]={},b1[1001]={};
	int a[1001]={},b[1001]={},c[1001]={};
	cin>>a1>>b1;
	int la=strlen(a1);
	int lb=strlen(b1);
	for(int i=0;i<la;i++){
		a[la-i]=a1[i]-'0';
	}
	for(int i=0;i<lb;i++){
		b[lb-i]=b1[i]-'0';
	}
	for(int i=1;i<=lb;i++){
		int x=0;
		for(int j=1;j<=la;j++){
		c[i+j-1]=a[j]*b[i]+x+c[i+j-1];
		x=c[i+j-1]/10;
		c[i+j-1]%=10;
		}
		c[i+la]=x;
	}
	int lc=la+lb;
	while(c[lc]==0&&lc>1){
		lc--;
	}
		for(int i=lc;i>=1;i--){
		cout<<c[i];
	}
	return 0;
}
