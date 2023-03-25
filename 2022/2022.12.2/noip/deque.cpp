#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>
#define int long long
using namespace std;
int read(){
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
class node{
	public:
		int data,i;
}a[200005];
bool cmp(node a,node b){
	return a.data==b.data?a.i<b.i:a.data<b.data;
}
//bool top[200005];//这个数是双端队列的队头 
signed main(){
	freopen("deque.in","r",stdin);
	freopen("deque.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		a[i].data=read();
		a[i].i=i;
	}
	sort(a+1,a+n+1,cmp);
	int _max,_min=1;
	int ans=1;
	int now_max=-0x3f3f3f3f,now_min=0x3f3f3f3f;
	int now=0;//1上升，0下降
	for(int i=1;i<=n;i++){
		if(a[i].data!=a[i+1].data)//对读入的数据进行排序后，进行对B数组的处理，最终拼成包含尽量少的段数的序列，其中每一段都具有单谷性质。
        {
            _max=i;
            if(now==0)
            {
                if(a[_max].i<=now_min)
                {
                    now_min=a[_min].i;
                }
                else
                {
                    now=1-now;
                    now_max=a[_max].i;
                }
            }
            else
            {
                if(a[_min].i<now_max)
                {
                    ans++;
                    now=1-now;
                    now_min=a[_min].i;
                }
                else
                {
                    now_max=a[_max].i;
                }
            }
            _min=i+1;
        }
	}
	printf("%lld",ans);
	return 0;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:
			6 3 6 0 9 6 3
		Out:
			2
More:

*/
