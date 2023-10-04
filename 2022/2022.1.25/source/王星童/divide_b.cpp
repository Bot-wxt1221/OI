#include <iostream>
#include <cstdio>
using namespace std;
bool check(int b);
int n,m,c=0;
int a[100005];
int main(){
	freopen("divide_b.in","r",stdin);
	freopen("divide_b.out","w",stdout);
	n=m=c=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c+=a[i];
	}
	int l=c/m,r=c,t,ans;
	while(l<r){
		t=(l+r)/2;
		if(check(t)){
			ans=t;
			r=t-1;
		}else{
			l=t+1;
		}
	}
	if(check(l)){
		cout<<l;
	}else if(check(r)){
		cout<<r;
	}else if(check(ans)){
		cout<<ans;
	}
	return 0;
}
bool check(int b){
	int c2=0,used=1;
	for(int i=1;i<=n;i++){
		if(a[i]>b){
			return false;
		}
		if(c2+a[i]<=b){
			c2+=a[i];
		}else{
			c2=0;
			used++;
			c2+=a[i];
		}
	}
	if(used<=m){
		return true;
	}else{
		return false;
	}
}
