#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
priority_queue <int > a;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int temp;
		cin>>temp;
		a.push((-1)*temp);
	}
	long long aa=0;
	while(a.size()>1){
		int b=(-1)*a.top();
		a.pop();
		int c=(-1)*a.top();
		a.pop();
		aa+=(b+c);
		a.push((-1)*(b+c));
	}
	cout<<aa;
	return 0;
}
