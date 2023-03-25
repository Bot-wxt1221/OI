#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	if(c==EOF){
		return -1;
	} 
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
		if(c==EOF){
		return -1;
	} 
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
		if(c==EOF){
		return -1;
	} 
	}
	return f*x;
}
int _max[20005];
int _max2[20005];
int a[20005];
signed main(){
	freopen("rain.in","r",stdin);
	freopen("rain.out","w",stdout);
	int n=0;
	while(scanf("%lld",&a[++n])==1);//读入 
	n--;//神奇 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]>a[i]){//往后 
				break;
			}
			_max[j]=max(_max[j],a[i]);
		}
		for(int j=i;j>=1;j--){
			if(a[j]>a[i]){ //往前 
				break;
			}
			_max2[j]=max(_max2[j],a[i]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(min(_max[i],_max2[i])-a[i]>0){//负的直接去掉 
			ans+=min(_max[i],_max2[i])-a[i];
		}
	}
	cout<<ans;
	return 0;
}
