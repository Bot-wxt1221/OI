#include <iostream>
#include <algorithm>
using namespace std;
int c[55];
string d,e;
bool cmp(int a,int b){
	d="";
	e="";
	for(int i=1;a!=0;i++){
		d=d+char(a%10);
		a=a/10;
	}
	for(int i=1;b!=0;i++){
		e=e+char(b%10);
		b=b/10;
	}
	reverse(d.begin(),d.end());
	reverse(e.begin(),e.end());
	a=0,b=0;
	for(int i=d.size()-1;i>=0;i--){
		a=a*10+d[i];
	}
	for(int i=e.size()-1;i>=0;i--){
		b=b*10+e[i];
	}
	return a<b;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		for(int i=a;i<=b;i++){
			c[i-a]=i;
		}
		sort(c,c+b-a+1,cmp);
		for(int i=0;i<=b-a;i++){
			cout<<c[i]<<' ';
		}
	}
}
