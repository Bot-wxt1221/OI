#include <iostream>
using namespace std;
int main(){
    double n,len=2,i=0;
    cin>>n;
    while(n){
        i++;
        n-=len;
        len=len*0.98;
    }
    cout<<i;
}