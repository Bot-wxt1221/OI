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
	int w/*��ֵ*/;
	int c/*���*/;
}object;
object obj[maxn];
int n,m;
int f[maxn]/*f[i]��ʾ����װi�����Ʒʱ������ֵ*/;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	for(RI i=1;i<=n;i++) cin >> obj[i].w >> obj[i].c;
	for(RI i=1;i<=n;i++)/*��ÿ����Ʒ����ö��*/
		for(RI v=m;v>=obj[i].c;v--)/*������Ͽ�ʼö��*/
			f[v]=max(f[v],f[v-obj[i].c]+obj[i].w);/*��̬ת�Ʒ���f[i][v]=max{f[i-1,v,f[i-1][v-c[i]]-w[i]}*/ 
	printf("%d",f[m]);		
	fclose(stdin);
	fclose(stdout);
	return 0;
}

