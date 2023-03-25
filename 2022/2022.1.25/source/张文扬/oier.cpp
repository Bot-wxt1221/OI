#include <cstdio>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
int n,k;
const int maxn=1e4+10;
struct oier{
	string name;
	long long score;
}oi[maxn];
bool cmp1(oier a,oier b){
	return a.name<b.name;
}
bool cmp2(oier a,oier b){
	if(a.score!=b.score) return a.score>b.score;
	else return a.name<b.name;
}
int _find(string a){
	int l=1,r=n;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(oi[mid].name==a) return mid;
		if(oi[mid].name<a) l=mid+1;
		else r=mid-1;
	}
}
int main(){
	freopen("oier.in","r",stdin);
	freopen("oier.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>oi[i].name;
	sort(oi+1,oi+n+1,cmp1);
	cin>>k;
	for(int i=1;i<=k;++i){
		string nam;
		cin>>nam;
		long long p;
		cin>>p;
		oi[_find(nam)].score+=p;
	}
	sort(oi+1,oi+n+1,cmp2);
	for(int i=1;i<=n;++i){
		cout<<oi[i].name<<" "<<oi[i].score<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
