#include <iostream>
#include <algorithm>
using namespace std;
class node{
	public:
		string id;
		int num;
		int y;
		node(){
			id="";
			num=0;
			y=0;
	}
}da[105];
bool cmp(node a,node b);
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>da[i].id>>da[i].y;
		da[i].num=i;
	}
	sort(da+1,da+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<da[i].id<<endl;
	}
	return 0;
}
bool cmp(node a,node b){
	if(a.y>=60&&b.y<60){
		return 1;
	}
	if(b.y>=60&&a.y<60){
		return 0;
	}
	if(a.y>=60&&b.y>=60){
		if(a.y==b.y){
			return a.num<b.num;
		}else{
			return a.y>b.y;
		}
	}
	return a.num<b.num;
}