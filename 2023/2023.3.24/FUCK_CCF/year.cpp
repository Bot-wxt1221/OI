//对拍
#include <iostream>
#include <cstdio>
#define int long long
inline int read();

signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("year.in","r",stdin);
	freopen("year.out","w",stdout);
	#endif
    int a=read();
	int b=read();
	if(b-a<=100000){
		int ans=0;
		for(int i=a;i<=b;i++){
			if((i%4==0&&i%100!=0)||(i%400==0)){
				ans++;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	int na=((a+400)/400)*400;
	int nb=(b/400)*400;
	int ans=((nb-na)/400)*97ll;
	ans++;
	for(int i=a;i<na;i++){
		if((i%4==0&&i%100!=0)||(i%400==0)){
			ans++;
		}
	}
	for(int i=nb+1;i<=b;i++){
		if((i%4==0&&i%100!=0)||(i%400==0)){
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/


