#include <cstdio>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n,k,m;
        scanf("%d%d",&n,&k);
        m=n-k;
        int temp=n/2;
        int tem=(m)/2+(k)/2;
        if(temp>tem){
        	printf("0\n");
        }else{
        	printf("1\n");
        }
    }
    return 0;
}