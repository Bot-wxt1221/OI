#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int read(){
	char a=getchar();
	int f=1,x=0;
	while('0'>a||a>'9'){
		(a=='-')?f=-1:0;
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		x=(x<<3)+(x<<1)+(a-'0');
		a=getchar();
	}
	return f*x;
}
int f[4000005];
int cnt[4000005],sum[4000005]; 
//	freopen("bus.in","r",stdin);
//	freopen("bus.out","w",stdout);
	int n=read();
	int _max=0;
	int m=read();
	for(int i=1;i<=n;i++){
		int temp=read();
		_max=max(_max,temp);
		cnt[temp]++;
		sum[temp]+=temp;
	}
	for(int i=1;i<_max+m;i++){
		cnt[i]+=cnt[i-1];
		sum[i]+=sum[i-1];
	}
	for(int i=1;i<_max+m;i++){
		if(i>=m&&cnt[i]==cnt[i-m]){
			f[i]=f[i-m];
			continue;
		}
		f[i]=i*cnt[i]-sum[i];
		for(int j=max(0,i-2*m+1);j<=i-m;j++){
			f[i]=min(f[i],f[j]+(cnt[i]-cnt[j])*i-(sum[i]-sum[j]));
		}
	}
	int ans=1e9;
	for(int i=mt;i<mt+m;i++){
		ans=min(ans,f[i]);
	}
	printf("%d",ans);
	return 0;
}
