#include <iostream>
#include <cstdio>
#include <deque>
#define int long long 
inline int read();
std::deque<int>de;
int cnt=0;
int now2=0;
void dfs(int now){
    if(now==1){
        de.push_front(++now2);
        de.push_back(now2);
        cnt++;
        cnt++;
        return ;
    }
    if((now&1)==0){
        dfs(now-1);
        de.push_front(++now2);
        de.push_back(now2);
        cnt++;
        cnt++;
        return ;
    }else{
        dfs(now/2);
        de.insert(de.begin()+std::max(0ll,cnt/2),++now2);
        de.push_back(now2);
        cnt++;
        cnt++;
        return ;
    }
    return ;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read();
    dfs(n);
    printf("%lld\n",cnt);
    for(int i=0;i<cnt;i++){
        printf("%lld ",de[i]);
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

