#include <iostream>
using namespace std;
long long int a[10000005];
int main(){
    long long _max=1,temp=0,__max=1,n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    temp=0;
    for(int i=1;i<=n;i++){
        if(a[i]>=a[i-1]){
            __max++;
        }else{
            _max=max(_max,__max);
            __max=1;
        }
    }
    _max=max(_max,__max);
    __max=1;
    cout<<_max;
}