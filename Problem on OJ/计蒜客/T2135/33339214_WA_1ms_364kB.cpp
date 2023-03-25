#include <iostream>
#include <algorithm>
using namespace std;
class node{
	public:
		int s1,s2,s3,sum,num;
}da[305];
bool cmp(node a,node b){
	if(a.sum!=b.sum){
		return a.sum>b.sum;
	}
	if(a.s1!=a.s1){
		return a.s1>b.s1;
	}
	return a.num<b.num;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>da[i].s1>>da[i].s2>>da[i].s3;
		da[i].sum=da[i].s1+da[i].s2+da[i].s3;
		da[i].num=i;
	}
	sort(da+1,da+n+1,cmp);
	for(int i=1;i<=5;i++){
		cout<<da[i].num<<' '<<da[i].sum<<endl;
	}
	return 0;
}