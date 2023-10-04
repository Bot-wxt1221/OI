#include <iostream>
#include <cstdio>
using namespace std;
int a[501];
char b[2005];
int main(){
	freopen("2011.in","r",stdin);
	freopen("2011.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin>>k;
	a[1]=2011;
	for(int i=2;i<=500;i++){
		a[i]=a[i-1]*2011%10000;
	}
	for(int i=1;i<=k;i++){
		memset(b,0,sizeof(b));
		cin>>b;
		int temp;
		if(strlen(b)>=4)
			temp=(b[strlen(b)-1]-'0')+(b[strlen(b)-2]-'0')*10+(b[strlen(b)-3]-'0')*100+(b[strlen(b)-4]-'0')*1000;
		else if(strlen(b)==3){
			temp=(b[strlen(b)-1]-'0')+(b[strlen(b)-2]-'0')*10+(b[strlen(b)-3]-'0')*100;
		}
		else if(strlen(b)==2){
			temp=(b[strlen(b)-1]-'0')+(b[strlen(b)-2]-'0')*10;
		}
		else{
			temp=(b[strlen(b)-1]-'0');
		}
		if(temp%500==0){
			cout<<a[500]<<endl;
			continue;
		}
		cout<<a[temp%500]<<endl;
	}
	return 0;
}
