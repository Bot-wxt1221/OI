#include <iostream>
#include <cstdio>
using namespace std;
long long a[1000005];
long long aa[1000005];
inline long long f(int a,int b);//求区间【a，b】的和 
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
    int n,k,ans=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
    	scanf("%d",&a[i]);
    	aa[i]=aa[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
    	for(int j=i;j<=n;j++){
    		if(f(i,j)%k==0){
    			ans++;
    		}
    	}
    }
    cout<<ans;
    return 0;
}
inline long long f(int a,int b){
	return aa[b]-aa[a-1];
}
