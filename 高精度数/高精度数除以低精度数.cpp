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
	char a1[10001]={};
	int a[10001]={},b,c[10001]={};
	cin>>a1>>b;
	int la=strlen(a1);
	for(int i=0;i<la;i++){
		a[i+1]=a1[i]-'0';
	}
	int x=0;
	for(int i=1;i<=la;i++){
		c[i]=(x*10+a[i])/b;
		x=(x*10+a[i])%b;
	}
	int lc=1;
	while(c[lc]==0&&lc<la){
		lc++;
	}	
	for(int i=lc;i<=la;i++){
		cout<<c[i];
	}
	return 0;
}
