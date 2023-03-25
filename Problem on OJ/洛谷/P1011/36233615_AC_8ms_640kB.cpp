#include<cstdio>
using namespace std;
int sum1[25],sum2[25];
int main(){
	int a,n,m,x;
	scanf("%d%d%d%d",&a,&n,&m,&x);
	sum1[2]=1,sum1[3]=2;
	for(int i=4;i<n;i++){
		sum1[i]=sum1[i-1]+sum1[i-2]-1;
		sum2[i]=sum2[i-1]+sum2[i-2]+1;
	}
	int b=(m-a*sum1[n-1])/sum2[n-1];
	printf("%d",a*sum1[x]+b*sum2[x]);
	return 0;
}
