/*
���ֵ�������
������룺ԭ��ǰ׺��ͬ 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
string a[30];
int main(){
	freopen("maxnum.in","r",stdin);
	freopen("maxnum.out","w",stdout);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}

