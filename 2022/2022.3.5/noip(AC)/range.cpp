#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
class node{
	public:
		int a,b;
}a[10005];
bool operator<(node a,node b){
	return a.b==b.b?a.a<b.a:a.b<b.b;
}
int main(){
	freopen("range.in","r",stdin);
	freopen("range.out","w",stdout);
	int n,maxb,ans;
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b;
	}
	sort(a+1,a+n+1);
	int x=-1,sum=0;
	for(int i=1;i<=n;i++){
		if(x>=a[i].a){
			continue;
		}
		sum++;x=a[i].b;
	}
	cout<<sum;
	return 0;
}
