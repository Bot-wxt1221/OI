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
		a[la-1-i]=a1[i]-'0';
	}
	for(int i=0;i<lb;i++){
		b[lb-1-i]=b1[i]-'0';
	}
	int l=max(la,lb);
	int lc=0,x=0;
	while(lc<l){
		c[lc]=a[lc]-b[lc]+x;
		x=c[lc]/10;
		c[lc]=c[lc]%10;
		lc++;
	}
	c[lc]=x;
	lc++;
	if(x==0){
		lc--;	
	}
	while(lc<la){
		c[lc]=a[lc]-b[lc];
	}	
	while(c[lc-1]==0&&lc>0){
		lc--;
	}
		for(int i=lc-1;i>=0;i--){
		cout<<c[i];
	}
	return 0;
}
