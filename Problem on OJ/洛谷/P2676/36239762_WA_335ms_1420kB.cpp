#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
class far{
	public:
		long long a;
		far(){
		a=0;
		}
};
bool cmp(far a,far b){
	return a.a>b.a;
}
int main() {
	int n,m;
	cin>>m>>n;
	far f[100005];
	for(int i=1;i<=m;i++){
		cin>>f[i].a;
	}
	sort(f,f+m+1,cmp);
	int i=1;
	while(1){
		if(f[i].a<n){
			n=n-f[i].a;
		}else{
			break;
		}
		i++;
	}
	cout<<i;
	return 0;
}