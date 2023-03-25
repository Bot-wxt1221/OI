#include <iostream>
using namespace std;
unsigned int a[1000005];
int main(){
    int _max=1,temp=0,__max=1,n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    temp=a[1];
    for(int i=1;i<=n;i++){
        if(a[i]>=temp){
            __max++;
            temp=a[i];
        }else{
            _max=max(_max,__max);
            __max=1;
            temp=a[i];
        }
    }
    cout<<_max;
}