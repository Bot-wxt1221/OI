#include <iostream>
#include <cstdio>
using namespace std;
int gcd(int a,int b){
	while(a!=0){
		if(a<b){
			swap(a,b);
		}
		a=a%b;
	}
	return b;
}
int main(){
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	int n,ans,last=0,a,b;
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			if(i>j){
				cout<<"  ";
			}else{
				int n=i^j;
				cout<<n<<' ';
			}
		}
		cout<<endl;
	}
	return 0;
}

