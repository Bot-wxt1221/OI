#include <cstdio>
#include <algorithm>
using namespace std;
long long ans[5000005];
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++){
        scanf("%lld",&ans[i]);
    }
    nth_element(ans,ans+n,ans+m);//简短又高效
    printf("%lld",ans[n]);
}