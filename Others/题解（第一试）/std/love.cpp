//��һ���ߵ���ʤ̬�Ǳذ�̬ 
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[1000005];
bool W[1100005];//W����Ϊ��ǰ���Ƿ��Ǳ�ʤ̬ 
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
		W[n]=false;//�ߵ����յ���ô�߶����� 
		for (int i=n-1;i>=1;i--)
		{
			if (W[i+1]&&W[i+a[i]])//��ô�߶��Ǳ�ʤ̬�����Ǳذ�̬    ��Ȼ��� 
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
