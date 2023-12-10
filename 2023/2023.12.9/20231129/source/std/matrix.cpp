#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,L=105;
int sum[L][L],a[N][L],len[N],n,m,tot,xl,xr,yl,yr,nx=0;
long long ans[N];char x[L];
struct qu{int x,y,id,op;}q[400400];
bool cmp(qu a,qu b){return a.x<b.x;}
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%lld",&n,&ans[0]);
	for(int i=1;i<=n;i++){
		scanf("%s",x+1),len[i]=strlen(x+1);
		for(int j=1;j<=len[i];j++)a[i][j]=(x[j]-'0')+a[i][j-1];
	}scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d%d",&xl,&yl,&xr,&yr),
		q[++tot]={xr,yr,i,1},q[++tot]={xl-1,yr,i,-1},
		q[++tot]={xr,yl-1,i,-1},q[++tot]={xl-1,yl-1,i,1};
	sort(q+1,q+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		while(nx<q[i].x){
		nx++;for(int j=1;j<=len[nx];j++)
			sum[len[nx]][j]+=a[nx][j];}
		for(int j=1;j<=100;j++)ans[q[i].id]+=(1ll*sum[j][j]*(q[i].y/j)+sum[j][q[i].y%j])*q[i].op;
	}
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]); 
}
