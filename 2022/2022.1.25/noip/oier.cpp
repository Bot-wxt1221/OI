#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
class oier{
	public:
		string a;
		long long b;
		oier(){
			b=0;
		}
}oi[10005];
bool cmp(oier a,oier b){
	return a.a<b.a;
}
bool cmp2(oier a,oier b){
	return a.a==b.a;
}
bool cmp3(oier a,oier b){
	return a.b==b.b?a.a<b.a:a.b>b.b;
}
int search(int first,int last,string find){
	int mid=first+(last-first)/2;
	while(first<last-1){
		mid=first+(last-first+1)/2;
		if(oi[mid].a<find){
			first=mid+1;
		}else{
			last=mid;
		}
	}
	if(oi[first].a==find){
		return first;
	}else{
		return last;
	}
}
int main(){
	freopen("oier.in","r",stdin);
	freopen("oier.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>oi[i].a;
		oi[i].b=0;
	}
	sort(oi+1,oi+n+1,cmp);
	int k;
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		string a;long long b;
		cin>>a>>b;
		oier temp;
		oi[search(1,n,a)].b+=b;
	}
	sort(oi+1,oi+n+1,cmp3);
	for(int i=1;i<=n;i++){
		cout<<oi[i].a<<' '<<oi[i].b<<endl;
	}
	return 0;
}

