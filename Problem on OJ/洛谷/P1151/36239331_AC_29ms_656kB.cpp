#include <iostream>
using namespace std;
int a[10];
int main(){
    int k;
    bool h=1;
    cin>>k;
    for(int i=10000;i<=30000;i++){
        a[1]=i/10000;
        a[2]=i%10000/1000;
        a[3]=i%1000/100;
        a[4]=i%100/10;
        a[5]=i%10;
        int d,b,c;
        d=100*a[1]+10*a[2]+a[3];
        b=100*a[2]+10*a[3]+a[4];
        c=100*a[3]+10*a[4]+a[5];
        if(d%k==0&&b%k==0&&c%k==0){
            cout<<i<<endl;
            h=0;
        }
    }
    if(h){
        cout<<"No";
    }
    return 0;
}