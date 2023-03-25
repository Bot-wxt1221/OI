#include <stdio.h>
#include<math.h> 
int check(int x)
{
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0) return 1;
	}
	return 0;
}
int dp[205];
short prime[47];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	dp[0]=1;
	for(int i=2;i<=200;i++){
	    if(check(i)==0){
	        prime[++prime[0]]=i;
	    }
	}
	for(int i=1;i<=46;i++){
		for(int j=prime[i];j<=200;j++){
			dp[j]=dp[j-prime[i]]+dp[j];
		}
	}
	int a;
	while(scanf("%d",&a)!=EOF){
		printf("%d\n",dp[a]);
	}
	return 0;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/

