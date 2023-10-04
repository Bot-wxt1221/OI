#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
int read(){
	int x=0,op=1;
	char f=getchar();
	while(f<'0'||f>'9'){
		op=((f=='-')?-1:1);
		f=getchar();
	}
	while('0'<=f&&f<='9'){
		x=(x<<3)+(x<<1)+(f^'0');
		f=getchar();
	}
	return op*x;
}
int fa[500005];
int getfa(int i){
	return fa[i]==i?i:fa[i]=getfa(fa[i]);
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	#endif
	int n=read();
	int tot=n;
	int ans=0;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=n;i>=1;i--){
		for(int j=i;j+i<=n;j+=i){
			if(getfa(j)==getfa(j+i)){
				continue;
			}
//			if(i+j==12&&i==3){
//				std::cerr<<std::endl;
//			}
			fa[fa[j]]=fa[j+i];
			tot--;
			ans+=i;
//			printf("%lld %lld\n",i,i+j);
			if(tot==1){
				break;
			}
		}
		if(tot==1){
			break;
		}
	}
	printf("%lld %lld",ans,n-1);
	return 0;
}

