#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int len[1000005];
int main(){
    int n,p,num;
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        cin>>len[i];
    }
    sort(len+1,len+n+1);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(abs(len[i]-len[j])>p){
                break;
            }
            num++;
        }
    }
    cout<<num;
    return 0;
}