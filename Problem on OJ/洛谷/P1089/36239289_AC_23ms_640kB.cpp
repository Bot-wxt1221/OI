#include <iostream>
using namespace std;
int a[20];
int main(){
    for(int i=1;i<=12;i++){
        cin>>a[i];
    }
    int c=0,b=0;
    for(int i=1;i<=12;i++){
        b+=300;
        if(b<a[i]){
            cout<<-i;
            return 0;
        }
        b-=a[i];
        c+=(b/100)*100;
        b=b%100;
    }
    cout<<c*1.2+b;
    return 0;
}