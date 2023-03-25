#include <iostream>
#include <algorithm>
using namespace std;
class node{
	public:
		string a;
		int s;
}da[25];
bool cmp(node a,node b){
	if(a.s!=b.s){
		return a.s>b.s;
	}
	return a.a<b.a;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>da[i].a>>da[i].s;
	}
	sort(da+1,da+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<da[i].a<<' '<<da[i].s<<endl;
	}
	return 0;
}