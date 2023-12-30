#include <iostream>
#include <cstdio>
namespace pro{
	int read();
	int seq[10];
	int a[10][10];
	int ans=0;
	int n;
	void dfs(int now){
		if(now==6){
			//check
			for(int i=1;i<=n;i++){
				int cnt=0;
				int aa,bb;
				for(int j=1;j<=5;j++){
					if((a[i][j]-seq[j]+10)%10){
						cnt++;
						bb=aa;
						aa=j;
					}
				}
				if(cnt>=3){
					return ;
				}else if(cnt==2){
					if(bb!=aa-1){
						return ;
					}else if((a[i][aa]-seq[aa]+10)%10!=(a[i][bb]-seq[bb]+10)%10){
						return ;
					}
//					ans1++;
				}else if(cnt==0){
					return ;
				}else{
//					ans2++;
				}
			}
			ans++;
			return ;
		}
		for(int i=1;i<=10;i++){
			seq[now]=i;
			dfs(now+1);
		}
		return ;
	}
	//O(10^5*n)
	int solve(){
		n=read();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=5;j++){
				a[i][j]=read();
			} 
		}
		dfs(1);
		printf("%d",ans);
		return 0;
	}
};
int main(){
// 	freopen("lock.in","r",stdin);
// 	freopen("lock.out","w",stdout);
	return pro::solve();
}
int pro::read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		if(temp=='-'){
			f=-1;
		}
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
