#include<bits/stdc++.h>
using namespace std;
char s[20];
int a[20];
long long dfs(int l,int r,int qz,int hz,int zr=0){
	if(l==r) return ((a[l]-hz)&1)^1;
	if(l>r) return qz==hz;
	int cs=min(qz*10+a[r]-hz,9)-max(zr,qz*10+a[r]-hz-9)+1;
	if((a[r]==0&&hz==1)||(a[r]==9&&hz==0)){
		if(qz*10+a[l]==10) return (9-zr+1)*dfs(l+1,r-1,1,hz);
		if(qz*10+a[l]==9) return (9-zr+1)*dfs(l+1,r-1,0,hz);
	}
	else if(cs>0){
		if(a[l]==a[r]-hz) return cs*dfs(l+1,r-1,0,qz);
		if(a[l]-1==a[r]-hz) return cs*dfs(l+1,r-1,1,qz);
	}
	return 0;
}
int main(){
		freopen("ex_number2.in","r",stdin);
		freopen("number.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int lth;
		long long ans;
		scanf("%s",s);
		lth=strlen(s);
		for(int i=1;i<=lth;i++){
			a[i]=s[i-1]-'0';
		}
		ans=dfs(1,lth,0,0,1);
		if(a[1]==1) ans+=dfs(2,lth,1,0,1);
		printf("%lld\n",ans);
		memset(s,0,sizeof s);
		memset(a,0,sizeof a);
	}
	return 0;
}
