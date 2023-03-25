#include <iostream>
using namespace std;
int a[6005];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int _min=1410065407,temp;
    for(int i=1;i<=n-m;i++){
        temp=0;
        for(int j=0;j<m;j++){
            temp=temp+a[i+j];
        }
        _min=min(_min,temp);
    }
    cout<<_min;
    return 0;
}