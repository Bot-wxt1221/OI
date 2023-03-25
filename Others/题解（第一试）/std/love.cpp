//能一步走到必胜态是必败态 
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[1000005];
bool W[1100005];//W定义为当前点是否是必胜态 
int main()
{
//	freopen("love.in","r",stdin);
//	freopen("love.out","w",stdout);
	int n;
	scanf("%d",&n);
	while (n!=0)
	{
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(W,true,sizeof(W));
		W[n]=false;//走到最终点怎么走都出格 
		for (int i=n-1;i>=1;i--)
		{
			if (W[i+1]&&W[i+a[i]])//怎么走都是必胜态，就是必败态    自然溢出 
				W[i]=false;
		}
		if (W[1]) printf("YTC.\n");
		else printf("LZM.\n");
		scanf("%d",&n);
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
