#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    if(n<=150){
        printf("%.1f",n*0.4463);
    }else if(n<=400){
        printf("%.1f",150*0.4463+(n-150)*0.4663);
    }else{
        printf("%.1f",150*0.4463+250*0.4663+(n-400)*0.5663);
    }
    return 0;
}