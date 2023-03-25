#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,f[1009][1009];
struct alyson{
	int a;
	int b;
	int zuok;
	int youk;
};
alyson hyt[100009];
int main()
{
	//freopen("matrix.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&hyt[i].a,&hyt[i].b);
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	    if(i!=j) f[i][j]=0x3f3f3f3f;
	for(int len=2;len<=n;len++)
	    for(int l=1;l+len-1<=n;l++) 
	    {
	    	int r=l+len-1;
	    	for(int k=l;k<r;k++) 
	    	f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+hyt[l].a*hyt[k].b*hyt[r].b);
	    }
	cout<<f[1][n]<<endl;
	return 0;
}
