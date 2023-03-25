#include <iostream>
using namespace std;
int a[1000005];
int main(){
    int _max=0,temp=0,__max=0,n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]>temp){
            __max++;
        }else{
            _max=max(_max,__max);
            __max=0;
            temp=a[i];
        }
    }
    cout<<_max;
}