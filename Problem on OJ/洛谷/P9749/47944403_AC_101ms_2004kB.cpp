#include <iostream>
#include <cstdio>
namespace pro{
	long long read();
	long long dis[100005];
	long long a[100005];
	long long solve(){
		signed n=read(),d;
		d=read();
		for(long long i=1;i<n;i++){
			dis[i]=read();
		}
		for(long long i=1;i<=n;i++){
			a[i]=read();
		}
		long long i=1;
		long long j=2;
		long long oil=0;
		long long cost=0;
		a[n]=0;
		while(i<n){
			long long di=dis[i];
			while(a[j]>=a[i]&&j<=n){
				di+=dis[j];
				j++;
			}
			long long mo=(oil-di);
			if(mo>=0){
				oil-=di;
			}else{
				di-=oil;
				oil=0;
				long long noil=((di/d)+((di%d==0)?0:1));
				cost+=noil*a[i];
//				std::cerr<<noil<<' '<<a[i]<<std::endl;
				oil+=noil*d-di;
			}
			i=j;
			j=i+1;
		}
		printf("%lld",cost);
		return 0;
	}
};

signed main(){
// 	freopen("road.in","r",stdin);
// 	freopen("road.out","w",stdout);
	return pro::solve();
}
long long pro::read(){
	long long f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		if(temp=='-'){
			f=-1;
		}
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}

