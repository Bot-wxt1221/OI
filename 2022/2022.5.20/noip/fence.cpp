#include <iostream>
#include <cstdio>
#include <queue>
#define int unsigned long long
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
priority_queue<int>a;
signed main(){
//	freopen("fence.in","r",stdin);
//	freopen("fence.out","w",stdout);
	int n=read(),total=0,ans=0;
	for(int i=1;i<=n;i++){
		a.push(-read());//默认大跟对取负数以从小到大 
	}
	for(int i=1;i<=n-1;i++){
//		cout<<a1<<' '<<a2
		int a1=-a.top();
		a.pop();
		int a2=-a.top();
		a.pop();
		ans+=(a1+a2);
		a.push(-a1-a2);
	}
	cout<<ans;
	return 0;
}
/*
Anything about this program:
Type:
	例题 
Description:
	农夫约翰想要修复牧场周围的一小段围栏。他测量了栅栏，发现他需要N (1 ≤ N ≤ 20,000) 块木板，每块木板都有一定的整数长度L 
i
 (1 ≤ L 
i
 ≤
50,000) 个单位。然后，他购买了一块长板，其长度刚好可以锯入N块木板（即，其长度是长度L 
i
的总和）。FJ 忽略了“切口”，即锯切时因锯末而
损失的额外长度；你也应该忽略它。
FJ 遗憾地意识到他没有锯木头的锯子，所以他拿着这块长板走到农夫唐的农场，并礼貌地问他是否可以借一把锯子。
壁橱资本家 Farmer Don 没有借给 FJ 一把锯子，而是提出向 Farmer John 收取N -1 木板上的每一次切割的费用。切割一块木头的费用正好等于它
的长度。切割长度为 21 的木板需要 21 美分。
Farmer Don 然后让 Farmer John 决定切割木板的顺序和位置。帮助农夫约翰确定他可以花费的最低金额来制作N块木板。FJ 知道他可以以各种不
同的顺序切割板子，这将导致不同的费用，因为生成的中间板具有不同的长度。

Example:
	1:
		In:
			3 8 5 8
		Out:
			34
	2：
		In:
			5 4 8 2 3 6 
		Out:
			51
		Wrong Out:
			52
More:
反过来做，将划分变为合并 

*/

