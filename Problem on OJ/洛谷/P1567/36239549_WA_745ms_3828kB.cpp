#include <iostream>
using namespace std;
unsigned int a[1000005];
int main(){
    int _max=1,temp=0,__max=0,n;
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
            __max=0;
        }
    }
    cout<<_max;
}