#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
inline int read();
std::priority_queue<int>a,b;
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("average.in","r",stdin);
	freopen("average.out","w",stdout);
	#endif
    int n1,n2,n;
    while(scanf("%lld%lld%lld",&n1,&n2,&n)!=EOF&&(n1!=0||n2!=0||n!=0)){
        a=std::priority_queue<int>();
        b=std::priority_queue<int>();
        int sum=0;
        for(int i=1;i<=n;i++){
            int temp=read();
            sum+=temp;
            a.push(-temp);
            b.push(temp);
            if(a.size()>n1){
                a.pop();
            }
            if(b.size()>n2){
                b.pop();
            }
        }
        while(a.size()>0){
            sum+=a.top();
            a.pop();
        }
        while(b.size()>0){
            sum-=b.top();
            b.pop();
        }
        printf("%.6lf\n",(double(sum))/(n-n1-n2));
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


