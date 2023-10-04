#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
char a[20005];
int b[20005];
int yuejie[20005];
int rMax[20005];
int yuejie2[20005];
int nrMax[20005];
int nlMax[20005];
int lMax[20005];
int top=0;
int anss[20005];
signed main() {
	freopen("areas.in","r",stdin);
	freopen("areas.out","w",stdout);
	scanf("%s",a);
	int ans=0,total=0;
	int n=strlen(a);
	b[0]=20005;
	for(int i=0; i<n; i++) {
		if(a[i]=='_') {
			b[i+1]=b[i];
		} else if(a[i]=='/') {
			b[i+1]=b[i]+1;
		} else {
			b[i+1]=b[i]-1;
		}
	}
	for(int i=0;i<=n;i++){
		if(b[i]>=rMax[i-1]){
			rMax[i]=b[i];
			nrMax[i]=i;
		}else{
			rMax[i]=rMax[i-1];
			nrMax[i]=nrMax[i-1];
		}
	}
	for(int i=n;i>=0;i--){
		if(b[i]>=lMax[i+1]){
			lMax[i]=b[i];
			nlMax[i]=i;
		}else{
			lMax[i]=lMax[i+1];
			nlMax[i]=nlMax[i+1];
		}
	}
	int r=-1,zheng=0,ling=0;
	for(int i=0;i<n;i++){
		int ni;
		if(rMax[i]<=lMax[i]){
			ni=nrMax[i];
		}else{
			ni=nlMax[i];
		}
		if(ni!=r){
			r=ni;
			if(zheng+ling/2>0){
				anss[++ans]=zheng+ling/2;
			}
			zheng=ling=0;
		}
		if(a[i]=='_'){
			zheng+=min(rMax[i],lMax[i])-b[i];
		}else if(a[i]=='/'){
			zheng+=min(rMax[i],lMax[i])-b[i];
			ling++;
		}else{
			zheng+=min(rMax[i],lMax[i])-b[i];
			ling--;
		}
	}
	if(zheng+ling/2>0){
		anss[++ans]=zheng+ling/2;
	}
	zheng=ling=0;
	total=0;
	for(int i=1;i<=ans;i++){
		total+=anss[i];
	}
	cout<<total<<endl<<ans;
	for(int i=1; i<=ans; i++) {
		cout<<' '<<anss[i];
	}
	cout<<endl;
	return 0;
}
