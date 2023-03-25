#include <cstdio>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n,k,m;
        scanf("%d%d",&n,&k);
        m=n-k+1;
        if((n-k+1)%2==0){
            m--;
        }
        if(((n-m+1)/2)>(k/2)){
            printf("%d\n",0);
        }else{
            printf("1\n");
        }
    }
    return 0;
}