#include <cstdio>
using namespace std;
int main(){
//	freopen("1.txt","r",stdin);
//	freopen(".out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n,k;
        scanf("%d%d",&n,&k);
        if((n&k)==k){
        	printf("1\n");
        }else{
        	printf("0\n");
        }
    }
    return 0;
}