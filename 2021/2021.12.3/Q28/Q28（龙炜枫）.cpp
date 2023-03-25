#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<set>
#include<ctime>
#define RI register int
using namespace std;
const int maxn=1e5+10;
typedef struct
{
	int w/*价值*/;
	int c/*体积*/;
}object;
object obj[maxn];
int n,m;
int f[maxn]/*f[i]表示背包装i体积物品时的最大价值*/;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	for(RI i=1;i<=n;i++) cin >> obj[i].w >> obj[i].c;
	for(RI i=1;i<=n;i++)/*对每个物品进行枚举*/
		for(RI v=m;v>=obj[i].c;v--)/*从体积上开始枚举*/
			f[v]=max(f[v],f[v-obj[i].c]+obj[i].w);/*动态转移方程f[i][v]=max{f[i-1,v,f[i-1][v-c[i]]-w[i]}*/ 
	printf("%d",f[m]);		
	fclose(stdin);
	fclose(stdout);
	return 0;
}

