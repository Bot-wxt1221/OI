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
	int a[1001]={},b[1001]={};
	cin>>a1>>b1;
	int la=strlen(a1);
	int lb=strlen(b1);
	for(int i=0;i<la;i++){
		a[la-1-i]=a1[i]-'0';
	}
	for(int i=0;i<lb;i++){
		b[lb-1-i]=b1[i]-'0';
	}
	for(int i=0;i<la;i++){
		cout<<a[i];
	}
	cout<<endl;
	for(int i=0;i<lb;i++){
		cout<<b[i];
	}
	return 0;
}
