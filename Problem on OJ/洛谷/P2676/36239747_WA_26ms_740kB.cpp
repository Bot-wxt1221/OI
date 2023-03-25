#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
class far{
	public:
		int p,a;
		far(){
		p=0;a=0;
		}
};
bool cmp(far a,far b){
	return a.p<b.p;
}
int main() {
//	freopen("milk.in","r",stdin);
//	freopen("milk.out","w",stdout);
	int n,m;
	cin>>n>>m;
	far f[20005];
	for(int i=1;i<=m;i++){
		cin>>f[i].p>>f[i].a;
	}
	sort(f,f+m+1,cmp);
	int ans=0;
	int i=1;
	while(1){
		if(f[i].a<n){
			ans++;
			n=n-f[i].a;
		}else{
			ans++;
			break;
		}
		i++;
	}
	cout<<ans;
	return 0;
}