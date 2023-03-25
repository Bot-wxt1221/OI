#include <iostream>
using namespace std;
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int ans=0;
    for(int i=1;i<=a;i++){
        int temp=i;
        while(temp!=0){
            if(temp%10==b){
                ans++;
            }
            temp=temp/10;
        }
    }
    printf("%d",ans);
    return 0;
}