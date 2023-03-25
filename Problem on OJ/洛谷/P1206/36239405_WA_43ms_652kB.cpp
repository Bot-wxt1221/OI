#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;
string to_b(int n,int b);
int main() {
//	freopen("palsquare.in","r",stdin);
//	freopen("palsquare.out","w",stdout);
	int b;
	cin>>b;
	string a,af;
	bool ca;
	for(int i=1;i<=300;i++){
		ca=1;
		a=to_b(i,b);
		af=to_b(i*i,b);
		for(int i=0;i<af.size();i++){
			if(af[i]!=af[af.size()-1-i]){
				ca=0;
			}
		}
		if(ca){
			cout<<a<<' '<<af<<endl;
		}
	}
	return 0;
}
string to_b(int n,int b){
	char a[20]={'\0'};
	int i=0;
	while(n){
		if(n%b<10){
			a[i]=n%b+'0';
		}else{
			a[i]=n&b-10+'A';
		}
		i++;
		n=n/b;
	}
	a[i]='\0';
	reverse(a,a+i);
	string abc=a;
	return abc;
}