#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
class node{
	public:
		int k,s;
		node(){
			k=0,s=0;
		}
}da[5005];
bool cmp(node a,node b){
	if(a.s!=b.s){
		return a.s<b.s;
	}
	return a.k<b.k;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>da[i].k>>da[i].s;
	}
	sort(da+1,da+n+1,cmp);
	int k=floor(m*1.5);
	int score=da[n-k+1].s;
	int num=0;
	for(int i=1;i<=n;i++){
		if(da[i].s>=score){
			num++;
		}
	}
	cout<<score<<" "<<num<<endl;
	for(int i=n;i!=0;i--){
		if(da[i].s>=score){
			cout<<da[i].k<<' '<<da[i].s<<endl;
		}
	}
	return 0;
}