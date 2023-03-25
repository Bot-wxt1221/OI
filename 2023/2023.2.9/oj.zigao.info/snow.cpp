#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
inline int read();

signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("snow.in","r",stdin);
	freopen("snow.out","w",stdout);
	#endif
    read();
    read();
    double ans=0;
    int x1,y1,x2,y2;
    while(scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2)!=EOF){
        ans+=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));//所有的街道都可以走一遍就完成
    }
    ans*=2;
    int h=ans/1000/20;
    int mi=(ans-(h*20000))*3;
    int temp;//计算时间
    if(mi%1000>=500){
        temp=mi/1000+1;
    }else{
        temp=mi/1000;
    }
    if(temp<10){
        printf("%lld:0%lld",h,temp);
    }else{
        printf("%lld:%lld",h,temp);
    }
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


