#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
string a[105];
bool cmp(string a,string b){
	return (a+b)<(b+a);
}
int main(){
	freopen("strcat.in","r",stdin);
	freopen("strcat.out","w",stdout);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
}

