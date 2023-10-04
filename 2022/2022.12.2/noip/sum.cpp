#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
inline int read();
std::deque<int>a;
int sum[3000005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	#endif
    int n=read(),m;
    m=read();
    for(int i=1;i<=n;i++){
        sum[i]=read()+sum[i-1];
    }
    int _max=-0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=n;i++){
        while(a.size()>0&&i-a.front()>=m){
            a.pop_front();
        }
        while(a.size()>0&&sum[i-1]<=sum[a.back()-1]){
            a.pop_back();
        }
        a.push_back(i);
        if(a.size()>0)
            _max=std::max(_max,sum[i]-sum[a.front()-1]);
    }
    printf("%lld",_max);
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
    封控在家可能 5天，即将死亡，啊啊啊啊啊啊啊啊啊啊啊，全体去看QQ群。呜呜
    这次的题从一位前缀和到三位前缀和，感觉不算特别难的算法，三维可以通过二维和一维的递推式猜，还是很好猜的
*/
