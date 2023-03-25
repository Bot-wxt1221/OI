#include <iostream>
#include <cmath>
using namespace std;
int len[1000005];
int main(){
    int n,p,num;
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        cin>>len[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;i++){
            if(abs(len[i]-len[j])<=p){
                num++;
            }
        }
    }
    cout<<num/2;
    return 0;
}