#include <iostream>
#include <cstdio>
using namespace std;
int rs,n;
class node{
	public:
		int l,t,x,y;
}a[10005];
int check(int v);
int main(){
	freopen("rectangle.in","r",stdin);
	freopen("rectangle.out","w",stdout);
	cin>>rs>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].t>>a[i].x>>a[i].y;
		a[i].x=a[i].l+a[i].x;
		a[i].y=a[i].t+a[i].y;
	}
	int l=0,r=rs,mid,ans;
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid)>0){
			r=mid;
		}else{
			l=mid;
		}
	}
	while(check(r-1)>0)	r--;
	if(check(r-1)!=0){
		cout<<r;
	}else{
		cout<<r-1;
	}
	return 0;
}
int check(int v){
	int l=0,r=0;
	for(int i=1;i<=n;i++){
		if(a[i].l>=v){
			r+=(a[i].x-a[i].l)*(a[i].y-a[i].t);
		}else if(a[i].l<v&&a[i].x>v){
			l+=(v-a[i].l)*(a[i].y-a[i].t);
			r+=(a[i].x-v)*(a[i].y-a[i].t);
		}else{
			l+=(a[i].x-a[i].l)*(a[i].y-a[i].t);
		}
	}
	return l-r;
}
